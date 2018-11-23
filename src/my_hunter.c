/*
** EPITECH PROJECT, 2018
** my_hunter.c
** File description:
** -
*/

#include <stdlib.h>
#include "hunter.h"

void my_hunter(void)
{
    sfEvent event;
    texture_t *tex = malloc(sizeof(texture_t));
    sound_t *sound = malloc(sizeof(sound_t));
    bird_mouv_t *b_mouv = malloc(sizeof(bird_mouv_t));
    expl_clock_t *e_clock = malloc(sizeof(expl_clock_t));

    create_my_ressources(tex, sound, b_mouv, e_clock);
    while (sfRenderWindow_isOpen(tex->window)) {
        sfRenderWindow_drawSprite(tex->window, tex->back_spr, NULL);
        sfRenderWindow_drawSprite(tex->window, tex->bird_spr, NULL);
        sfRenderWindow_drawSprite(tex->window, tex->mouse_spr, NULL);
        sfRenderWindow_drawSprite(tex->window, tex->expl_spr, NULL);
        update_my_bird(tex, b_mouv, sound);
        check_shot(tex, b_mouv, e_clock, sound);
        update_my_cursor(tex);
        sfRenderWindow_display(tex->window);
        close_my_window(tex->window, event);
    }
    destroy_my_ressources(tex, sound);
}
