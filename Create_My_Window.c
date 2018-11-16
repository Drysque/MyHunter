/*
** EPITECH PROJECT, 2018
** Create_My_Window.c
** File description:
** -
*/

#include "hunter.h"

sfRenderWindow *create_my_window(int width, int height, int bpp)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {width, height, bpp};

    window = sfRenderWindow_create(video_mode, "My Hunter",
        sfResize | sfClose, NULL);
    return (window);
}

void close_my_window(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
}
