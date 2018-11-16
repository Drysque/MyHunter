/*
** EPITECH PROJECT, 2018
** hunter.h
** File description:
** includes protos for my_hunter
*/

#ifndef HUNTER_H_
#define HUNTER_H_

#include <SFML/Graphics.h>

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

typedef struct bird_mouv_s
{
    sfIntRect bird_spr_rect;
    sfVector2f bird_vect;
} bird_mouv_t;

sfRenderWindow *create_my_window(int width, int height, int bpp);
void create_my_background(texture_t *tex);
void create_my_bird(texture_t *tex);
void init_my_bird(bird_mouv_t *b_mouv, bird_clock_t *b_clock);
void update_my_bird(texture_t *tex, bird_clock_t *b_clock, bird_mouv_t *b_mouv);
void close_my_window(sfRenderWindow *window, sfEvent event);
void destroy_my_ressources(texture_t *tex);

#endif
