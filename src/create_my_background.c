/*
** EPITECH PROJECT, 2018
** create_my_ressources.c
** File description:
** Associate the texture to the background sprite
*/

#include "hunter.h"

void create_my_background(texture_t *tex)
{
    tex->back_tex = sfTexture_createFromFile("./image_src/windows_back.jpg", NULL);
    tex->back_spr = sfSprite_create();
    sfSprite_setTexture(tex->back_spr, tex->back_tex, sfTrue);
}
