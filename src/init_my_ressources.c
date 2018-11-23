/*
** EPITECH PROJECT, 2018
** init_mt_ressources.c
** File description:
** initializes ressources
*/

#include <SFML/Graphics.h>
#include <time.h>
#include "hunter.h"

void init_my_bird(bird_mouv_t *b_mouv)
{
    b_mouv->bird_spr_rect.top = 0;
    b_mouv->bird_spr_rect.left = 0;
    b_mouv->bird_spr_rect.width = 110;
    b_mouv->bird_spr_rect.height = 110;
    b_mouv->bird_vect.x = 1.7;
    b_mouv->bird_vect.y = 0.5;
    b_mouv->bird_clock = sfClock_create();
    b_mouv->position.x = 0.0;
    b_mouv->status = 0;
    b_mouv->life = 3;
    b_mouv->origine.x = 0.0;
    b_mouv->origine.y = 0.0;
    srand(time(NULL));
}

void init_my_expl(texture_t *tex, bird_mouv_t *b_mouv, expl_clock_t *e_clock)
{
    e_clock->expl_spr_rect.top = 200;
    e_clock->expl_spr_rect.left = 0;
    e_clock->expl_spr_rect.width = 200;
    e_clock->expl_spr_rect.height = 200;
    e_clock->expl_clock = sfClock_create();
    sfSprite_setPosition(tex->expl_spr, b_mouv->out_of_bound);
}

void init_my_heart(texture_t *tex, bird_mouv_t *b_mouv)
{
    sfVector2f heart1_vec = {1800.0, 975.0};
    sfVector2f heart2_vec = {1680.0, 975.0};
    sfVector2f heart3_vec = {1560.0, 975.0};

    sfSprite_setPosition(tex->heart1_spr, heart1_vec);
    sfSprite_setPosition(tex->heart2_spr, heart2_vec);
    sfSprite_setPosition(tex->heart3_spr, heart3_vec);
}
