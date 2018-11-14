/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** test
*/

#include "hunter.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left + offset >= max_value)
        rect->left = 0;
    else
        rect->left = rect->left + offset;
}

int main(int ac, char **av, char **env)
{
    char *env_display = env[5];

    sfRenderWindow *window = Create_my_Window(1920, 1080, 32);
    sfEvent event;
    texture_t tex;

    tex.back_tex = sfTexture_createFromFile("./image_src/windows_back.jpg", NULL);
    tex.back_spr = sfSprite_create();
    tex.bird_tex = sfTexture_createFromFile("./image_src/basic_bird.png", NULL);
    tex.bird_spr = sfSprite_create();

    sfSprite_setTexture(tex.back_spr, tex.back_tex, sfTrue);
    sfSprite_setTexture(tex.bird_spr, tex.bird_tex, sfTrue);

    sfIntRect rect = {0, 0, 110, 110};

    sfClock *clock;
    sfTime time;
    float seconds;
    clock = sfClock_create();

    sfVector2f bird_vect = {1.0, 0.0};

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        sfRenderWindow_drawSprite(window, tex.back_spr, NULL);
        sfRenderWindow_drawSprite(window, tex.bird_spr, NULL);
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1.0;
        if (seconds > 100000) {
            move_rect(&rect, 110, 330);
            sfClock_restart(clock);
        }
        sfSprite_setTextureRect(tex.bird_spr, rect);
        sfSprite_move(tex.bird_spr, bird_vect);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    sfTexture_destroy(tex.back_tex);
    sfSprite_destroy(tex.back_spr);
    sfTexture_destroy(tex.bird_tex);
    sfSprite_destroy(tex.bird_spr);
    return 0;
}
