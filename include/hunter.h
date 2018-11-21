/*
** EPITECH PROJECT, 2018
** hunter.h
** File description:
** includes protos for my_hunter
*/

#ifndef HUNTER_H_
#define HUNTER_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct texture_s
{
    sfRenderWindow *window;
    sfTexture *back_tex;
    sfSprite *back_spr;
    sfTexture *bird_tex;
    sfSprite *bird_spr;
    sfTexture *expl_tex;
    sfSprite *expl_spr;
    sfTexture *mouse_tex;
    sfSprite *mouse_spr;
    sfVector2f mouse_coor;
} texture_t;

typedef struct sound_s
{
    sfMusic *shot_blast;
    sfMusic *mii;
} sound_t;

typedef struct bird_mouv_s
{
    sfIntRect bird_spr_rect;
    sfVector2f bird_vect;
    sfVector2f position;
    sfVector2f click_coor;
    sfVector2f out_of_bound;
    int status;
    sfClock *bird_clock;
    sfTime bird_time;
    float bird_sec;
} bird_mouv_t;

typedef struct expl_clock_s
{
    sfClock *expl_clock;
    float expl_sec;
    sfTime expl_time;
    sfIntRect expl_spr_rect;
} expl_clock_t;

sfRenderWindow *create_my_window(int width, int height, int bpp);
void check_shot(texture_t *tex, bird_mouv_t *b_mouv,
    expl_clock_t *e_mouv, sound_t *sound);
void update_my_bird(texture_t *tex, bird_mouv_t *b_mouv, sound_t *sound);
void update_my_cursor(texture_t *tex);
void close_my_window(sfRenderWindow *window, sfEvent event);
void destroy_my_ressources(texture_t *tex, sound_t *sound);
void create_my_ressources(texture_t *tex, sound_t *sound,
    bird_mouv_t *b_mouv, expl_clock_t *e_clock);

#endif
