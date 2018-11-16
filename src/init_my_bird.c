/*
** EPITECH PROJECT, 2018
** init_my_bird.c
** File description:
** initalize the bird paramaters
*/

#include "hunter.h"

void init_my_bird(bird_mouv_t *b_mouv, bird_clock_t *b_clock)
{
    b_mouv->bird_spr_rect.top = 0;
    b_mouv->bird_spr_rect.left = 0;
    b_mouv->bird_spr_rect.width = 110;
    b_mouv->bird_spr_rect.height = 110;
    b_mouv->bird_vect.x = 1.7;
    b_mouv->bird_vect.y = 0.0;
    b_clock->bird_clock = sfClock_create();
}
