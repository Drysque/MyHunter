/*
** EPITECH PROJECT, 2018
** update_my_cursor.c
** File description:
** updates the cursor sprite
*/

#include "hunter.h"

void update_my_cursor(sfRenderWindow *window, texture_t *tex)
{
    tex->mouse_coor.x = sfMouse_getPositionRenderWindow(window).x - 25;
    tex->mouse_coor.y = sfMouse_getPositionRenderWindow(window).y - 25;
    sfSprite_setPosition(tex->mouse_spr, tex->mouse_coor);
}
