/*
** EPITECH PROJECT, 2018
** Create_My_Window.c
** File description:
** -
*/

#include "hunter.h"

sfRenderWindow *Create_my_Window(int width, int height, int bpp)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {width, height, bpp};

    window = sfRenderWindow_create(video_mode, "Nice",
        sfResize | sfClose, NULL);
    return (window);
}
