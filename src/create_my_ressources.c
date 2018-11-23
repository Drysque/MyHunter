/*
** EPITECH PROJECT, 2018
** create_my_ressources.c
** File description:
** creates all the ressources
*/

#include <SFML/Graphics.h>
#include <time.h>
#include "hunter.h"
void init_my_bird(bird_mouv_t *b_mouv);
void init_my_expl(texture_t *tex, bird_mouv_t *b_mouv, expl_clock_t *e_clock);
void init_my_heart(texture_t *tex, bird_mouv_t *b_mouv);
sfRenderWindow *create_my_window(int width, int height, int bpp);
void create_my_background(texture_t *tex);
void create_my_over(texture_t *tex, bird_mouv_t *b_mouv);
void create_my_cursor(texture_t *tex);

void create_my_bird(texture_t *tex)
{
    tex->bird_tex = sfTexture_createFromFile("./image_src/bird.png", NULL);
    tex->bird_spr = sfSprite_create();
    sfSprite_setTexture(tex->bird_spr, tex->bird_tex, sfTrue);
}

void create_my_explosion(texture_t *tex)
{
    tex->expl_tex = sfTexture_createFromFile("./image_src/expl_sprS.png", NULL);
    tex->expl_spr = sfSprite_create();
    sfSprite_setTexture(tex->expl_spr, tex->expl_tex, sfTrue);
}

void create_my_sound(sound_t *sound)
{
    sound->shot_blast = sfMusic_createFromFile("./sound_src/SG.wav");
    sound->mii = sfMusic_createFromFile("./sound_src/Mii.ogg");
    sound->roblox = sfMusic_createFromFile("./sound_src/Roblox.ogg");
    sound->violin = sfMusic_createFromFile("./sound_src/Violin.ogg");
    sfMusic_play(sound->mii);
    sfMusic_setLoop(sound->mii, sfTrue);
    sfMusic_setVolume(sound->shot_blast, 10.0);
}

void create_my_heart(texture_t *tex)
{
    tex->heart_tex = sfTexture_createFromFile("./image_src/Heart.png", NULL);
    tex->heart1_spr = sfSprite_create();
    tex->heart2_spr = sfSprite_create();
    tex->heart3_spr = sfSprite_create();
    sfSprite_setTexture(tex->heart1_spr, tex->heart_tex, sfTrue);
    sfSprite_setTexture(tex->heart2_spr, tex->heart_tex, sfTrue);
    sfSprite_setTexture(tex->heart3_spr, tex->heart_tex, sfTrue);
}

void create_my_ressources(texture_t *tex, sound_t *sound,
    bird_mouv_t *b_mouv, expl_clock_t *e_clock)
{
    tex->window = create_my_window(1920, 1080, 32);
    create_my_over(tex, b_mouv);
    create_my_background(tex);
    create_my_bird(tex);
    create_my_cursor(tex);
    create_my_explosion(tex);
    create_my_heart(tex);
    create_my_sound(sound);
    init_my_bird(b_mouv);
    init_my_expl(tex, b_mouv, e_clock);
    init_my_heart(tex, b_mouv);
}
