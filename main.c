/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** test
*/

#include <stdlib.h>
#include "hunter.h"

void move_bird_rect(sfIntRect *bird_spr_rect, int offset, int max_value)
{
    if (bird_spr_rect->left + offset >= max_value)
        bird_spr_rect->left = 0;
    else
        bird_spr_rect->left = bird_spr_rect->left + offset;
}

void destroy_my_ressources(texture_t *tex)
{
    sfTexture_destroy(tex->back_tex);
    sfSprite_destroy(tex->back_spr);
    sfTexture_destroy(tex->bird_tex);
    sfSprite_destroy(tex->bird_spr);
}

void create_my_bird(texture_t *tex)
{
    tex->bird_tex = sfTexture_createFromFile("./image_src/basic_bird.png", NULL);
    tex->bird_spr = sfSprite_create();
    sfSprite_setTexture(tex->bird_spr, tex->bird_tex, sfTrue);
}

void create_my_background(texture_t *tex)
{
    tex->back_tex = sfTexture_createFromFile("./image_src/windows_back.jpg", NULL);
    tex->back_spr = sfSprite_create();
    sfSprite_setTexture(tex->back_spr, tex->back_tex, sfTrue);
}

void create_my_ressources(texture_t *tex)
{
    create_my_background(tex);
    create_my_bird(tex);
}

void draw_my_sprite(sfRenderWindow *window, texture_t *tex)
{
    sfRenderWindow_drawSprite(window, tex->back_spr, NULL);
    sfRenderWindow_drawSprite(window, tex->bird_spr, NULL);
}

void init_my_bird(bird_mouvement_t *b_mouv, bird_clock_t *b_clock)
{
    b_mouv->bird_spr_rect.top = 0;
    b_mouv->bird_spr_rect.left = 0;
    b_mouv->bird_spr_rect.width = 110;
    b_mouv->bird_spr_rect.height = 110;
    b_mouv->bird_vect.x = 1.7;
    b_mouv->bird_vect.y = 0.0;
    b_clock->bird_clock = sfClock_create();
}

// void Update_my_Bird(texture_t *tex, bird_clock_t *b_clock, sfVector2f bird_vect, sfIntRect bird_spr_rect)
// {
//         sfSprite_move(tex->bird_spr, bird_vect);
//         b_clock->bird_time = sfClock_getElapsedTime(b_clock->bird_clock);
//         b_clock->bird_sec = b_clock->bird_time.microseconds / 10000.0;
//         // printf("%f\n", b_clock->bird_sec);
//         if (b_clock->bird_sec > 1.0) {
//             move_bird_rect(&bird_spr_rect, 110, 330);
//             sfClock_restart(b_clock->bird_clock);
//         }
//         sfSprite_setTextureRect(tex->bird_spr, bird_spr_rect);
// }

void my_hunter(void)
{
    sfRenderWindow *window = create_my_window(1920, 1080, 32);
    sfEvent event;
    texture_t *tex = malloc(sizeof(texture_t));
    bird_clock_t *b_clock = malloc(sizeof(bird_clock_t));//ici mais je ne l'utilise que dans update
    bird_mouvement_t *b_mouv = malloc(sizeof(bird_mouvement_t));

    create_my_ressources(tex);
    init_my_bird(b_mouv, b_clock);
    while (sfRenderWindow_isOpen(window)) {
        close_my_window(window, event);
        draw_my_sprite(window, tex);
        // Update_my_Bird(tex, b_clock, bird_vect, bird_spr_rect);
        sfSprite_move(tex->bird_spr, b_mouv->bird_vect);
        b_clock->bird_time = sfClock_getElapsedTime(b_clock->bird_clock);
        b_clock->bird_sec = b_clock->bird_time.microseconds / 100000.0;
        if (b_clock->bird_sec > 1.0) {
            move_bird_rect(&b_mouv->bird_spr_rect, 110, 330);
            sfClock_restart(b_clock->bird_clock);
        }
        sfSprite_setTextureRect(tex->bird_spr, b_mouv->bird_spr_rect);
        // ----
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    destroy_my_ressources(tex);
}

int main(int ac, char **av, char **env)
{
    char *env_display = env[5];

    my_hunter();
    return 0;
}
