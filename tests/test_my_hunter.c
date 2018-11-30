/*
** EPITECH PROJECT, 2018
** test my hunter
** File description:
** unit tests for my_hunter
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "hunter.h"
int check_args(int ac, char **av, char **env);
void pause_game(void);
int wait_for_start(int start_status, texture_t *tex, bird_mouv_t *b_mouv);
void move_bird_rect(sfIntRect *bird_spr_rect, int offset, int max_value);
void switch_status(texture_t *tex, bird_mouv_t *b_mouv);
void move_expl_rect(texture_t *tex, bird_mouv_t *b_mouv,
    sfIntRect *expl_spr_rect);
void failure_manage(texture_t *tex, bird_mouv_t *b_mouv, sound_t *sound);
int wait_for_start(int start_status, texture_t *tex, bird_mouv_t *b_mouv);
void draw_my_sprites(texture_t *tex);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(check_args, all_good, .init = redirect_all_stdout)
{
    int ac = 1;
    char **av = NULL;
    char *env[] = {"1"};
    int return_value = check_args(ac, av, env);

    cr_expect_eq(0, return_value);
}

Test(check_args, null_env, .init = redirect_all_stdout)
{
    int ac = 1;
    char **av = NULL;
    char *env[] = {NULL};
    int return_value = check_args(ac, av, env);

    cr_expect_eq(84, return_value);
}

Test(check_args, usage, .init = redirect_all_stdout)
{
    int ac = 2;
    char **av = NULL;
    char *env[] = {"1"};
    int return_value = check_args(ac, av, env);

    cr_expect_eq(1, return_value);
}

Test(create_my_window, test_create)
{
    sfRenderWindow *window = create_my_window(1920, 1080, 32);

    cr_expect_eq(sfTrue, sfRenderWindow_isOpen(window));
    sfRenderWindow_close(window);
}

Test(create_my_window, test_close)
{
    sfRenderWindow *window = create_my_window(1920, 1080, 32);
    sfEvent event;

    event.type = sfEvtClosed;
    close_my_window(window, event);
    sfRenderWindow_close(window);
    cr_expect_eq(sfFalse, sfRenderWindow_isOpen(window));
}

Test(move_bird_rect, test_move_rect)
{
    sfIntRect *bird_spr_rect = malloc(sizeof(sfIntRect));

    bird_spr_rect->left = 0;
    move_bird_rect(bird_spr_rect, 100, 50);
    cr_expect_eq(bird_spr_rect->left, 0);
    free(bird_spr_rect);
}

Test(move_bird_rect, test_move_rect2)
{
    sfIntRect *bird_spr_rect = malloc(sizeof(sfIntRect));

    bird_spr_rect->left = 0;
    move_bird_rect(bird_spr_rect, 0, 50);
    cr_expect_eq(bird_spr_rect->left, 0);
    free(bird_spr_rect);
}

Test(create_my_ressources, play_game_idle)
{
    texture_t *tex = malloc(sizeof(texture_t));
    sound_t *sound = malloc(sizeof(sound));
    bird_mouv_t *b_mouv = malloc(sizeof(bird_mouv_t));
    expl_clock_t *e_clock = malloc(sizeof(expl_clock_t));
    sfEvent event;

    event.type = sfEvtClosed;
    pause_game();
    create_my_ressources(tex, sound, b_mouv, e_clock);
    update_my_cursor(tex, b_mouv);
    check_shot(tex, b_mouv, e_clock, sound);
    cr_expect_eq(b_mouv->life, 3);
    close_my_window(tex->window, event);
    destroy_my_ressources(tex, sound);
}

Test(switch_status, respawn_bird)
{
    texture_t *tex = malloc(sizeof(texture_t));
    sound_t *sound = malloc(sizeof(sound));
    bird_mouv_t *b_mouv = malloc(sizeof(bird_mouv_t));
    expl_clock_t *e_clock = malloc(sizeof(expl_clock_t));
    sfEvent event;

    event.type = sfEvtClosed;
    create_my_ressources(tex, sound, b_mouv, e_clock);
    b_mouv->status = 0;
    switch_status(tex, b_mouv);
    cr_expect_eq(b_mouv->position.y, 0.0);
    close_my_window(tex->window, event);
    destroy_my_ressources(tex, sound);
}

Test(switch_status, respawn_bird2)
{
    texture_t *tex = malloc(sizeof(texture_t));
    sound_t *sound = malloc(sizeof(sound));
    bird_mouv_t *b_mouv = malloc(sizeof(bird_mouv_t));
    expl_clock_t *e_clock = malloc(sizeof(expl_clock_t));
    sfEvent event;

    event.type = sfEvtClosed;
    create_my_ressources(tex, sound, b_mouv, e_clock);
    b_mouv->status = 1;
    switch_status(tex, b_mouv);
    cr_expect_eq(b_mouv->position.y, 800.0);
    close_my_window(tex->window, event);
    destroy_my_ressources(tex, sound);
}

Test(switch_status, respawn_bird3)
{
    texture_t *tex = malloc(sizeof(texture_t));
    sound_t *sound = malloc(sizeof(sound));
    bird_mouv_t *b_mouv = malloc(sizeof(bird_mouv_t));
    expl_clock_t *e_clock = malloc(sizeof(expl_clock_t));
    sfEvent event;

    event.type = sfEvtClosed;
    create_my_ressources(tex, sound, b_mouv, e_clock);
    b_mouv->status = 2;
    switch_status(tex, b_mouv);
    cr_expect_eq(b_mouv->position.y, 360.0);
    close_my_window(tex->window, event);
    destroy_my_ressources(tex, sound);
}

Test(switch_status, respawn_bird4)
{
    texture_t *tex = malloc(sizeof(texture_t));
    sound_t *sound = malloc(sizeof(sound));
    bird_mouv_t *b_mouv = malloc(sizeof(bird_mouv_t));
    expl_clock_t *e_clock = malloc(sizeof(expl_clock_t));
    sfEvent event;

    event.type = sfEvtClosed;
    create_my_ressources(tex, sound, b_mouv, e_clock);
    b_mouv->status = 3;
    switch_status(tex, b_mouv);
    cr_expect_eq(b_mouv->position.y, 0.0);
    close_my_window(tex->window, event);
    destroy_my_ressources(tex, sound);
}

Test(move_expl_rect, animate_expl)
{
    texture_t *tex = malloc(sizeof(texture_t));
    sound_t *sound = malloc(sizeof(sound));
    bird_mouv_t *b_mouv = malloc(sizeof(bird_mouv_t));
    expl_clock_t *e_clock = malloc(sizeof(expl_clock_t));
    sfEvent event;
    sfIntRect *expl_spr_rect = malloc(sizeof(sfIntRect));

    event.type = sfEvtClosed;
    create_my_ressources(tex, sound, b_mouv, e_clock);
    expl_spr_rect->left = 800;
    move_expl_rect(tex, b_mouv, expl_spr_rect);
    cr_expect_eq(expl_spr_rect->left, 800);
    expl_spr_rect->left = 0;
    move_expl_rect(tex, b_mouv, expl_spr_rect);
    cr_expect_eq(expl_spr_rect->left, 200);
    close_my_window(tex->window, event);
    destroy_my_ressources(tex, sound);
    free(expl_spr_rect);
}

Test(move_bird_rect, animate_bird, .init = redirect_all_stdout)
{
    texture_t *tex = malloc(sizeof(texture_t));
    sound_t *sound = malloc(sizeof(sound));
    bird_mouv_t *b_mouv = malloc(sizeof(bird_mouv_t));
    expl_clock_t *e_clock = malloc(sizeof(expl_clock_t));
    sfEvent event;

    event.type = sfEvtClosed;
    create_my_ressources(tex, sound, b_mouv, e_clock);
    b_mouv->life = 3;
    failure_manage(tex, b_mouv, sound);
    b_mouv->life = 2;
    failure_manage(tex, b_mouv, sound);
    b_mouv->life = 1;
    failure_manage(tex, b_mouv, sound);
    b_mouv->life = 0;
    failure_manage(tex, b_mouv, sound);
    cr_expect_stdout_neq_str("Better luck next time\n");
    close_my_window(tex->window, event);
    destroy_my_ressources(tex, sound);
}

Test(update_my_bird, test_bird_out, .init = redirect_all_stdout)
{
    texture_t *tex = malloc(sizeof(texture_t));
    sound_t *sound = malloc(sizeof(sound));
    bird_mouv_t *b_mouv = malloc(sizeof(bird_mouv_t));
    expl_clock_t *e_clock = malloc(sizeof(expl_clock_t));
    sfEvent event;

    event.type = sfEvtClosed;
    create_my_ressources(tex, sound, b_mouv, e_clock);
    sfSprite_setPosition(tex->bird_spr, b_mouv->origine);
    update_my_bird(tex, b_mouv, sound);
    sfSprite_setPosition(tex->bird_spr, b_mouv->out_of_bound);
    update_my_bird(tex, b_mouv, sound);
    cr_expect_stdout_neq_str("Better luck next time\n");
    close_my_window(tex->window, event);
    destroy_my_ressources(tex, sound);
}

Test(wait_for_start, test_start_game)
{
    texture_t *tex = malloc(sizeof(texture_t));
    sound_t *sound = malloc(sizeof(sound));
    bird_mouv_t *b_mouv = malloc(sizeof(bird_mouv_t));
    expl_clock_t *e_clock = malloc(sizeof(expl_clock_t));
    sfEvent event;
    int status = 0;

    event.type = sfEvtClosed;
    create_my_ressources(tex, sound, b_mouv, e_clock);
    draw_my_sprites(tex);
    status = wait_for_start(1, tex, b_mouv);
    cr_expect_eq(status, 1);
    close_my_window(tex->window, event);
    destroy_my_ressources(tex, sound);
}
