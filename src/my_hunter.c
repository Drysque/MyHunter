/*
** EPITECH PROJECT, 2018
** my_hunter.c
** File description:
** -
*/

#include <stdlib.h>
#include "hunter.h"

void draw_my_sprites(texture_t *tex)
{
    sfRenderWindow_drawSprite(tex->window, tex->back_spr, NULL);
    sfRenderWindow_drawSprite(tex->window, tex->bird_spr, NULL);
    sfRenderWindow_drawSprite(tex->window, tex->mouse_spr, NULL);
    sfRenderWindow_drawSprite(tex->window, tex->expl_spr, NULL);
    sfRenderWindow_drawSprite(tex->window, tex->heart1_spr, NULL);
    sfRenderWindow_drawSprite(tex->window, tex->heart2_spr, NULL);
    sfRenderWindow_drawSprite(tex->window, tex->heart3_spr, NULL);
    sfRenderWindow_drawSprite(tex->window, tex->over_spr, NULL);
    sfRenderWindow_drawSprite(tex->window, tex->start_spr, NULL);
}

int wait_for_start(int start_status, texture_t *tex, bird_mouv_t *b_mouv)
{
    while (start_status == 0)
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            start_status = 1;
    sfSprite_setPosition(tex->start_spr, b_mouv->out_of_bound);
    return (start_status);
}

void pause_game(void)
{
    while (sfKeyboard_isKeyPressed(sfKeySpace));
}

void my_hunter(void)
{
    sfEvent event;
    texture_t *tex = malloc(sizeof(texture_t));
    sound_t *sound = malloc(sizeof(sound_t));
    bird_mouv_t *b_mouv = malloc(sizeof(bird_mouv_t));
    expl_clock_t *e_clock = malloc(sizeof(expl_clock_t));
    int start_status = 0;

    create_my_ressources(tex, sound, b_mouv, e_clock);
    while (sfRenderWindow_isOpen(tex->window)) {
        pause_game();
        draw_my_sprites(tex);
        update_my_bird(tex, b_mouv, sound);
        check_shot(tex, b_mouv, e_clock, sound);
        update_my_cursor(tex);
        sfRenderWindow_display(tex->window);
        close_my_window(tex->window, event);
        if (start_status == 0)
            start_status = wait_for_start(start_status, tex, b_mouv);
    }
    destroy_my_ressources(tex, sound);
}
