/*
** EPITECH PROJECT, 2018
** update_my_bird.c
** File description:
** refresh the bird sprite
*/

#include "hunter.h"
void switch_status(texture_t *tex, bird_mouv_t *b_mouv);

void move_bird_rect(sfIntRect *bird_spr_rect, int offset, int max_value)
{
    if (bird_spr_rect->left + offset >= max_value)
        bird_spr_rect->left = 0;
    else
        bird_spr_rect->left = bird_spr_rect->left + offset;
}

void failure_manage(texture_t *tex, bird_mouv_t *b_mouv, sound_t *sound)
{
    sfMusic_play(sound->roblox);
    b_mouv->life -= 1;
    b_mouv->position.x = -300.0;
    b_mouv->bird_vect.x = 1.7;
    b_mouv->status = rand() % 3;
    switch_status(tex, b_mouv);
    if (b_mouv->life == 2)
        sfSprite_setPosition(tex->heart3_spr, b_mouv->out_of_bound);
    if (b_mouv->life == 1)
        sfSprite_setPosition(tex->heart2_spr, b_mouv->out_of_bound);
    if (b_mouv->life == 0) {
        sfMusic_stop(sound->mii);
        sfMusic_stop(sound->roblox);
        b_mouv->bird_vect.x = 0.0;
        sfSprite_setPosition(tex->over_spr, b_mouv->origine);
        sfMusic_play(sound->violin);
        write(1, "Better luck next time\n", 23);
    }
}

void update_my_bird(texture_t *tex, bird_mouv_t *b_mouv, sound_t *sound)
{
    sfSprite_move(tex->bird_spr, b_mouv->bird_vect);
    if (sfSprite_getPosition(tex->bird_spr).x < 1940) {
        b_mouv->bird_time = sfClock_getElapsedTime(b_mouv->bird_clock);
        b_mouv->bird_sec = b_mouv->bird_time.microseconds / 100000.0;
        if (b_mouv->bird_sec > 1.0) {
            move_bird_rect(&b_mouv->bird_spr_rect, 110, 330);
            sfClock_restart(b_mouv->bird_clock);
        }
        sfSprite_setTextureRect(tex->bird_spr, b_mouv->bird_spr_rect);
    } else {
        failure_manage(tex, b_mouv, sound);
    }
}
