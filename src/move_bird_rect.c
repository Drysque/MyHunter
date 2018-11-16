/*
** EPITECH PROJECT, 2018
** move_bird_rect.c
** File description:
** changes the rectangle the bird sprite sheet
*/

#include "hunter.h"

void move_bird_rect(sfIntRect *bird_spr_rect, int offset, int max_value)
{
    if (bird_spr_rect->left + offset >= max_value)
        bird_spr_rect->left = 0;
    else
        bird_spr_rect->left = bird_spr_rect->left + offset;
}
