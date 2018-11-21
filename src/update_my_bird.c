/*
** EPITECH PROJECT, 2018
** update_my_bird.c
** File description:
** refresh the bird sprite
*/

#include "hunter.h"

void move_bird_rect(sfIntRect *bird_spr_rect, int offset, int max_value)
{
    if (bird_spr_rect->left + offset >= max_value)
        bird_spr_rect->left = 0;
    else
        bird_spr_rect->left = bird_spr_rect->left + offset;
}

void update_my_bird(texture_t *tex, bird_mouv_t *b_mouv, sound_t *sound)
{
    sfSprite_move(tex->bird_spr, b_mouv->bird_vect);
    if (sfSprite_getPosition(tex->bird_spr).x < 1920) {
        b_mouv->bird_time = sfClock_getElapsedTime(b_mouv->bird_clock);
        b_mouv->bird_sec = b_mouv->bird_time.microseconds / 100000.0;
        if (b_mouv->bird_sec > 1.0) {
            move_bird_rect(&b_mouv->bird_spr_rect, 110, 330);
            sfClock_restart(b_mouv->bird_clock);
        }
        sfSprite_setTextureRect(tex->bird_spr, b_mouv->bird_spr_rect);
    } else {
        write(1, "Better luck next time\n", 23);
        destroy_my_ressources(tex, sound);
        exit(0);
    }
}
