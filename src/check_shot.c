/*
** EPITECH PROJECT, 2018
** check_shot.c
** File description:
** -
*/

#include <time.h>
#include "hunter.h"

void switch_status(texture_t *tex, bird_mouv_t *b_mouv)
{
    switch(b_mouv->status) {
    case 0: b_mouv->position.y = 0.0;
        b_mouv->bird_vect.y = 0.5;
        sfSprite_setPosition(tex->bird_spr, b_mouv->position);
        break;
    case 1: b_mouv->position.y = 800.0;
        b_mouv->bird_vect.y = -0.5;
        sfSprite_setPosition(tex->bird_spr, b_mouv->position);
        break;
    case 2: b_mouv->position.y = 360.0;
        b_mouv->bird_vect.y = 0.0;
        sfSprite_setPosition(tex->bird_spr, b_mouv->position);
        break;
    default: break;
    }
}

void move_expl_rect(texture_t *tex, bird_mouv_t *b_mouv,
    sfIntRect *expl_spr_rect)
{
    if (expl_spr_rect->left + 200 < 800)
        expl_spr_rect->left = expl_spr_rect->left + 200;
    else
        sfSprite_setPosition(tex->expl_spr, b_mouv->out_of_bound);
}

void animate_expl(texture_t *tex, bird_mouv_t *b_mouv, expl_clock_t *e_mouv)
{
    e_mouv->expl_time = sfClock_getElapsedTime(e_mouv->expl_clock);
    e_mouv->expl_sec = e_mouv->expl_time.microseconds / 100000.0;
    if (e_mouv->expl_sec > 1.0) {
        move_expl_rect(tex, b_mouv, &e_mouv->expl_spr_rect);
        sfClock_restart(e_mouv->expl_clock);
    }
    sfSprite_setTextureRect(tex->expl_spr, e_mouv->expl_spr_rect);
}

void check_shot(sfRenderWindow *window, texture_t *tex,
    bird_mouv_t *b_mouv, expl_clock_t *e_mouv)
{
    int mousex = sfMouse_getPositionRenderWindow(window).x;
    int mousey = sfMouse_getPositionRenderWindow(window).y;
    int birdx = sfSprite_getPosition(tex->bird_spr).x;
    int birdy = sfSprite_getPosition(tex->bird_spr).y;

    b_mouv->click_coor.x = (float) mousex - 100;
    b_mouv->click_coor.y = (float) mousey - 100;
    animate_expl(tex, b_mouv, e_mouv);
    if (sfMouse_isButtonPressed(sfMouseLeft) && mousex > birdx -60 &&
        mousex < birdx + 100 && mousey > birdy -20 && mousey < birdy + 100) {
        b_mouv->position.x = 0.0;
        switch_status(tex, b_mouv);
        b_mouv->status = rand() % 3;
        b_mouv->bird_vect.x += 0.04;
        sfSprite_setPosition(tex->expl_spr, b_mouv->click_coor);
        e_mouv->expl_spr_rect.left = 0;
    }
}
