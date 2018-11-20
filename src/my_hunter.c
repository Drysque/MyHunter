/*
** EPITECH PROJECT, 2018
** my_hunter.c
** File description:
** -
*/

#include <stdlib.h>
#include "hunter.h"

// void draw_my_sprite(sfRenderWindow *window, texture_t *tex)
// {
//     sfRenderWindow_drawSprite(window, tex->back_spr, NULL);
//     sfRenderWindow_drawSprite(window, tex->bird_spr, NULL);
// }

void my_hunter(void)
{
    sfRenderWindow *window = create_my_window(1920, 1080, 32);
    sfEvent event;
    texture_t *tex = malloc(sizeof(texture_t));
    bird_clock_t *b_clock = malloc(sizeof(bird_clock_t));
    bird_mouv_t *b_mouv = malloc(sizeof(bird_mouv_t));

    create_my_ressources(tex, b_mouv, b_clock);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, tex->back_spr, NULL);
        sfRenderWindow_drawSprite(window, tex->bird_spr, NULL);
        sfRenderWindow_drawSprite(window, tex->mouse_spr, NULL);
        update_my_bird(tex, b_clock, b_mouv);
        check_shot(window, tex, b_mouv);
        update_my_cursor(window, tex);
        sfRenderWindow_display(window);
        close_my_window(window, event);
    }
    sfRenderWindow_destroy(window);
    destroy_my_ressources(tex);
}
