/*
** EPITECH PROJECT, 2018
** end_of_program.c
** File description:
** Destroy the created ressources
*/

#include "hunter.h"

void destroy_my_textures(texture_t *tex)
{
    sfRenderWindow_destroy(tex->window);
    sfTexture_destroy(tex->back_tex);
    sfSprite_destroy(tex->back_spr);
    sfTexture_destroy(tex->over_tex);
    sfSprite_destroy(tex->over_spr);
    sfTexture_destroy(tex->bird_tex);
    sfSprite_destroy(tex->bird_spr);
    sfTexture_destroy(tex->mouse_tex);
    sfSprite_destroy(tex->mouse_spr);
    sfTexture_destroy(tex->expl_tex);
    sfSprite_destroy(tex->expl_spr);
    sfTexture_destroy(tex->heart_tex);
    sfSprite_destroy(tex->heart1_spr);
    sfSprite_destroy(tex->heart2_spr);
    sfSprite_destroy(tex->heart3_spr);
}

void destroy_my_ressources(texture_t *tex, sound_t *sound)
{
    destroy_my_textures(tex);
    sfMusic_stop(sound->mii);
    sfMusic_destroy(sound->mii);
    sfMusic_destroy(sound->shot_blast);
    sfMusic_destroy(sound->roblox);
    sfMusic_destroy(sound->violin);
}
