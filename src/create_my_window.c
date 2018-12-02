/*
** EPITECH PROJECT, 2018
** Create_My_Window.c
** File description:
** Creates the main game window
*/

#include <SFML/Graphics.h>
#include <time.h>
#include "hunter.h"

sfRenderWindow *create_my_window(int width, int height, int bpp)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {width, height, bpp};

    window = sfRenderWindow_create(video_mode,
        "<xX_My_$w4ggY_MoTh3r_FuCkInG_HuNt3r_Xx>",
        sfResize | sfClose | sfFullscreen, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return (window);
}

void create_my_background(texture_t *tex)
{
    tex->back_tex = sfTexture_createFromFile("./image_src/XP-pix.jpg", NULL);
    tex->back_spr = sfSprite_create();
    sfSprite_setTexture(tex->back_spr, tex->back_tex, sfTrue);
    tex->start_tex = sfTexture_createFromFile("./image_src/menu.jpg", NULL);
    tex->start_spr = sfSprite_create();
    sfSprite_setTexture(tex->start_spr, tex->start_tex, sfTrue);
}

void create_my_over(texture_t *tex, bird_mouv_t *b_mouv)
{
    tex->over_tex = sfTexture_createFromFile("./image_src/GO.png", NULL);
    tex->over_spr = sfSprite_create();
    sfSprite_setTexture(tex->over_spr, tex->over_tex, sfTrue);
    b_mouv->out_of_bound.x = 2000;
    b_mouv->out_of_bound.y = 2000;
    sfSprite_setPosition(tex->over_spr, b_mouv->out_of_bound);
}

void create_my_cursor(texture_t *tex)
{
    tex->mouse_tex = sfTexture_createFromFile("./image_src/cross.png", NULL);
    tex->mouse_spr = sfSprite_create();
    sfSprite_setTexture(tex->mouse_spr, tex->mouse_tex, sfTrue);
}
