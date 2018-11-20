/*
** EPITECH PROJECT, 2018
** my_hunter.c
** File description:
** -
*/

#include <stdlib.h>
#include "hunter.h"

// void create_my_ressources(texture_t *tex)
// {
//     create_my_background(tex);
//     create_my_bird(tex);
//     init du bird;
// }
// void draw_my_sprite(sfRenderWindow *window, texture_t *tex)
// {
//     sfRenderWindow_drawSprite(window, tex->back_spr, NULL);
//     sfRenderWindow_drawSprite(window, tex->bird_spr, NULL);
// }

void check_shot(sfRenderWindow *window, texture_t *tex)
{
    int mousex = sfMouse_getPositionRenderWindow(window).x;
    int mousey = sfMouse_getPositionRenderWindow(window).y;
    int birdx = sfSprite_getPosition(tex->bird_spr).x;
    int birdy = sfSprite_getPosition(tex->bird_spr).y;
    sfVector2f origine = {0.0, 0.0};


    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (mousex > birdx -110 && mousex < birdx + 110
            && mousey > birdy -110 && mousey < birdy + 110)
            sfSprite_setPosition(tex->bird_spr, origine);
    }
}

void my_hunter(void)
{
    sfRenderWindow *window = create_my_window(1920, 1080, 32);
    sfEvent event;
    texture_t *tex = malloc(sizeof(texture_t));
    bird_clock_t *b_clock = malloc(sizeof(bird_clock_t));
    bird_mouv_t *b_mouv = malloc(sizeof(bird_mouv_t));

    // create_my_ressources(tex);
    create_my_background(tex);
    create_my_bird(tex);
    init_my_bird(b_mouv, b_clock);
    while (sfRenderWindow_isOpen(window)) {
        close_my_window(window, event);
        sfRenderWindow_drawSprite(window, tex->back_spr, NULL);
        sfRenderWindow_drawSprite(window, tex->bird_spr, NULL);
        update_my_bird(tex, b_clock, b_mouv);
        check_shot(window, tex);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    destroy_my_ressources(tex);
}
