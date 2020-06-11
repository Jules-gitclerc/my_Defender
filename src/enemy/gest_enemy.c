/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_enemy
*/

#include "enemy.h"
#include "defender.h"

void destroy_enemy(enemy *np)
{
    enemy *cur = np;
    enemy *next = np->next;

    while (next != NULL) {
        cur = next;
        next = next->next;
        sfSprite_destroy(cur->sprite_enemy);
        sfSprite_destroy(cur->life_sprite);
        sfClock_destroy(cur->clock_rect);
        sfClock_destroy(cur->t_fire);
        free (cur);
    }
    free (np);
}

void display_enemy(enemy *np, chrono *tm, sfRenderWindow* window,
                    vague *vg, game *gm)
{
    enemy *cur = np->next;

    vg->rand = clock_sapwn_enemy(tm, vg->rand);
    for (int i = 1; i <= vg->rand && cur != NULL; cur = cur->next, i++) {
        cur->rect_enemy = clock_rect_enemy2(cur, cur->rect_enemy, 256);
        sfSprite_setTextureRect(cur->sprite_enemy, cur->rect_enemy);
        moove_enemy(cur, gm, i, np);
        set_bar_file(cur);
        sfRenderWindow_drawSprite(window, cur->sprite_enemy, NULL);
        sfRenderWindow_drawSprite(window, cur->life_sprite, NULL);
    }
}

void init_enemy_head(enemy *np, char *image)
{
    sfVector2f vec = {167, 85};
    sfVector2f scale = {0.37, 0.37};

    np->p_life = 100;
    np->is = 0;
    np->sprite_enemy = create_sprite(image);
    sfSprite_setPosition(np->sprite_enemy, vec);
    sfSprite_setScale(np->sprite_enemy, scale);
    np->rect_enemy = create_rect_enemy(0);
    np->life_sprite = create_sprite("./ressource/sprite_enemy/bar_life.png");
    np->clock_rect = sfClock_create();
    np->dead = 0;
    np->t_fire = sfClock_create();
    np->i = 1;
    np->next = NULL;
}

void fill_info_enemy(enemy *np, char *image)
{
    sfVector2f vec = {167, 85};
    sfVector2f scale = {0.37, 0.37};

    enemy *cur = np;
    for (; cur->next != NULL; cur = cur->next);
    cur->next = malloc(sizeof(enemy));
    cur = cur->next;
    cur->p_life = 140;
    cur->sprite_enemy = create_sprite(image);
    sfSprite_setPosition(cur->sprite_enemy, vec);
    sfSprite_setScale(cur->sprite_enemy, scale);
    cur->rect_enemy = create_rect_enemy(0);
    cur->life_sprite = create_sprite("./ressource/sprite_enemy/bar_life.png");
    cur->clock_rect = sfClock_create();
    cur->t_fire = sfClock_create();
    cur->dead = 0;
    cur->i = 1;
    cur->next = NULL;
}

void init_enemy(enemy *np, int nb_enemy)
{
    int nb = 0;

    init_enemy_head(np, "./ressource/sprite_enemy/blue_down2.png");
    for (int i = 0; i <= nb_enemy; i++) {
        fill_info_enemy(np, "./ressource/sprite_enemy/blue_down2.png");
    }
}