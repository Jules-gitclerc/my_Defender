/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ges_ball
*/

#include "defender.h"
#include "tower.h"
#include "enemy.h"

int clock_bonus(ball *cur)
{
    sfTime time = sfClock_getElapsedTime(cur->bonus);
    float sec = (float) time.microseconds / 10000000.0;

    if (sec >= 0.01) {
        sfClock_restart(cur->bonus);
        return (1);
    }
    return (0);
}

sfVector2f ia_ball(ball *cur, ball *missile, int i)
{
    sfVector2f vec_act = sfSprite_getPosition(cur->fire);

    if (vec_act.x > cur->vec_end.x)
        vec_act.x -= 1;
    else
        vec_act.x += 1;
    if (vec_act.y > cur->vec_end.y)
        vec_act.y -= 1;
    else
        vec_act.y += 1;
    sfSprite_setPosition(cur->fire, vec_act);
    if (clock_bonus(cur) == 1)
        destroy_node_ball(missile, i);
    return (vec_act);
}

int clock_moove(ball *cur)
{
    sfTime time = sfClock_getElapsedTime(cur->clock_moove);
    float sec = (float) time.microseconds / 10000000.0;

    if (sec >= 0.001) {
        sfClock_restart(cur->clock_moove);
        return (1);
    }
    return (0);
}

void add_node_missile(ball *missile, sfSprite *tower, sfSprite *enemy)
{
    ball *cur = missile;

    for (; cur->next != NULL; cur = cur->next);
    cur->next = malloc(sizeof(ball));
    cur = cur->next;
    cur->fire = create_sprite("./ressource/sprite_tower/fire_ball.png");
    cur->clock_moove = sfClock_create();
    cur->bonus = sfClock_create();
    cur->vec_initial = sfSprite_getPosition(tower);
    cur->vec_end = sfSprite_getPosition(enemy);
    sfSprite_setPosition(cur->fire, cur->vec_initial);
    cur->next = NULL;
}

int display_ball(screen *screen, ball *missile)
{
    int i = 0;

    for (ball *cur = missile->next; cur != NULL; cur = cur->next, i++) {
        if (clock_moove(cur) == 1)
            ia_ball(cur, missile, i);
        sfRenderWindow_drawSprite(screen->window, cur->fire, NULL);
    }
    return (0);
}