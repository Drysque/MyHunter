/*
** EPITECH PROJECT, 2018
** end_of_program.c
** File description:
** Destroy the created ressources
*/

#include "hunter.h"

void destroy_my_ressources(texture_t *tex)
{
    sfTexture_destroy(tex->back_tex);
    sfSprite_destroy(tex->back_spr);
    sfTexture_destroy(tex->bird_tex);
    sfSprite_destroy(tex->bird_spr);
}
