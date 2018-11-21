/*
** EPITECH PROJECT, 2018
** create_my_ressources.c
** File description:
** creates all the ressources
*/

#include <time.h>
#include "hunter.h"

void create_my_background(texture_t *tex)
{
    tex->back_tex = sfTexture_createFromFile("./image_src/windows.jpg", NULL);
    tex->back_spr = sfSprite_create();
    sfSprite_setTexture(tex->back_spr, tex->back_tex, sfTrue);
}

void create_my_bird(texture_t *tex)
{
    tex->bird_tex = sfTexture_createFromFile("./image_src/bird.png", NULL);
    tex->bird_spr = sfSprite_create();
    sfSprite_setTexture(tex->bird_spr, tex->bird_tex, sfTrue);
}

void create_my_cursor(texture_t *tex)
{
    tex->mouse_tex = sfTexture_createFromFile("./image_src/cross.png", NULL);
    tex->mouse_spr = sfSprite_create();
    sfSprite_setTexture(tex->mouse_spr, tex->mouse_tex, sfTrue);
}

void create_my_explosion(texture_t *tex)
{
    tex->expl_tex = sfTexture_createFromFile("./image_src/expl_sprS.png", NULL);
    tex->expl_spr = sfSprite_create();
    sfSprite_setTexture(tex->expl_spr, tex->expl_tex, sfTrue);
}

void init_my_bird(bird_mouv_t *b_mouv, bird_clock_t *b_clock)
{
    b_mouv->bird_spr_rect.top = 0;
    b_mouv->bird_spr_rect.left = 0;
    b_mouv->bird_spr_rect.width = 110;
    b_mouv->bird_spr_rect.height = 110;
    b_mouv->bird_vect.x = 1.7;
    b_mouv->bird_vect.y = 0.5;
    b_mouv->out_of_bound.x = 2000;
    b_mouv->out_of_bound.y = 2000;
    b_clock->bird_clock = sfClock_create();
    b_mouv->position.x = 0.0;
    b_mouv->status = 0;
    srand(time(NULL));
}

void init_my_expl(texture_t *tex, bird_mouv_t *b_mouv, expl_clock_t *e_clock)
{
    e_clock->expl_spr_rect.top = 200;
    e_clock->expl_spr_rect.left = 0;
    e_clock->expl_spr_rect.width = 200;
    e_clock->expl_spr_rect.height = 200;
    e_clock->expl_clock = sfClock_create();
    sfSprite_setPosition(tex->expl_spr, b_mouv->out_of_bound);
}

void create_my_ressources(texture_t *tex, bird_mouv_t *b_mouv,
    bird_clock_t *b_clock, expl_clock_t *e_clock)
{
    create_my_background(tex);
    create_my_bird(tex);
    create_my_cursor(tex);
    create_my_explosion(tex);
    init_my_bird(b_mouv, b_clock);
    init_my_expl(tex, b_mouv, e_clock);
}
