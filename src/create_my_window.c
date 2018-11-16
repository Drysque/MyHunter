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

    window = sfRenderWindow_create(video_mode, "My Hunter",
        sfResize | sfClose, NULL);
    return (window);
}
