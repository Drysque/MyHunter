/*
** EPITECH PROJECT, 2018
** Create_My_Window.c
** File description:
** Creates the main game window
*/

#include <SFML/Graphics.h>

sfRenderWindow *create_my_window(int width, int height, int bpp)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {width, height, bpp};

    window = sfRenderWindow_create(video_mode, "<xX_My_$w4ggY_MoTh3r_FuCkInG_HuNt3r_Xx>",
        sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return (window);
}
