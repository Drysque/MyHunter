/*
** EPITECH PROJECT, 2018
** hunter.h
** File description:
** includes protos for my_hunter
*/

#ifndef HUNTER_H
#define HUNTER_H

#include <SFML/Graphics.h>
sfRenderWindow *Create_my_Window(int width, int height, int bpp);

typedef struct texture_s
{
    sfTexture *back_tex;
    sfSprite *back_spr;
    sfTexture *bird_tex;
    sfSprite *bird_spr;
} texture_t;

#endif
