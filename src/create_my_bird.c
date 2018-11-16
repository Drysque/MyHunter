/*
** EPITECH PROJECT, 2018
** create_my_bird.c
** File description:
** Associate the texture to the bird sprite
*/

#include "hunter.h"

void create_my_bird(texture_t *tex)
{
    tex->bird_tex = sfTexture_createFromFile("./image_src/basic_bird.png", NULL);
    tex->bird_spr = sfSprite_create();
    sfSprite_setTexture(tex->bird_spr, tex->bird_tex, sfTrue);
}
