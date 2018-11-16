/*
** EPITECH PROJECT, 2018
** update_my_bird.c
** File description:
** refresh the bird sprite
*/

#include "hunter.h"
void move_bird_rect(sfIntRect *bird_spr_rect, int offset, int max_value);

void update_my_bird(texture_t *tex, bird_clock_t *b_clock, bird_mouv_t *b_mouv)
{
    sfSprite_move(tex->bird_spr, b_mouv->bird_vect);
    b_clock->bird_time = sfClock_getElapsedTime(b_clock->bird_clock);
    b_clock->bird_sec = b_clock->bird_time.microseconds / 100000.0;
    if (b_clock->bird_sec > 1.0) {
        move_bird_rect(&b_mouv->bird_spr_rect, 110, 330);
        sfClock_restart(b_clock->bird_clock);
    }
    sfSprite_setTextureRect(tex->bird_spr, b_mouv->bird_spr_rect);
}
