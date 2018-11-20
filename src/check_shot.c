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

void check_shot(sfRenderWindow *window, texture_t *tex, bird_mouv_t *b_mouv)
{
    int mousex = sfMouse_getPositionRenderWindow(window).x;
    int mousey = sfMouse_getPositionRenderWindow(window).y;
    int birdx = sfSprite_getPosition(tex->bird_spr).x;
    int birdy = sfSprite_getPosition(tex->bird_spr).y;

    if (sfMouse_isButtonPressed(sfMouseLeft) && mousex > birdx -60 &&
        mousex < birdx + 100 && mousey > birdy -20 && mousey < birdy + 100) {
        b_mouv->position.x = 0.0;
        switch_status(tex, b_mouv);
        b_mouv->status = rand() % 3;
        b_mouv->bird_vect.x += 0.025;
    }
}
