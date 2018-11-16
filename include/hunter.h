/*
** EPITECH PROJECT, 2018
** hunter.h
** File description:
** includes protos for my_hunter
*/

#ifndef HUNTER_H_
#define HUNTER_H_

#include <SFML/Graphics.h>

sfRenderWindow *create_my_window(int width, int height, int bpp);
void close_my_window(sfRenderWindow *window, sfEvent event);

typedef struct texture_s
{
    sfTexture *back_tex;
    sfSprite *back_spr;
    sfTexture *bird_tex;
    sfSprite *bird_spr;
} texture_t;

typedef struct bird_clock_s
{
    sfClock *bird_clock;
    sfTime bird_time;
    float bird_sec;
} bird_clock_t;

typedef struct bird_mouvement_s
{
    sfIntRect bird_spr_rect;
    sfVector2f bird_vect;
} bird_mouvement_t;

#endif
