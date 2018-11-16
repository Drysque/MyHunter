/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** test
*/

void my_hunter(void);

// void create_my_ressources(texture_t *tex)
// {
//     create_my_background(tex);
//     create_my_bird(tex);
// }

// void draw_my_sprite(sfRenderWindow *window, texture_t *tex)
// {
//     sfRenderWindow_drawSprite(window, tex->back_spr, NULL);
//     sfRenderWindow_drawSprite(window, tex->bird_spr, NULL);
// }

int main(int ac, char **av, char **env)
{
    char *env_display = env[5];

    my_hunter();
    return 0;
}
