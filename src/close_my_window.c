/*
** EPITECH PROJECT, 2018
** close_my_window.c
** File description:
** Closes the main game window
*/

#include "hunter.h"

void close_my_window(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
}
