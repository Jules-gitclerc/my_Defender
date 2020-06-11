/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** clock_enemy
*/

#include "enemy.h"

void destroy_clock_enemy(chrono *tm)
{
    sfClock_destroy(tm->clock_spawn);
}

void init_clock_enemy(chrono *tm)
{
    tm->clock_spawn = sfClock_create();
}

int clock_sapwn_enemy(chrono *tm, int rand)
{
    sfTime time = sfClock_getElapsedTime(tm->clock_spawn);
    float sec = (float) time.microseconds / 10000000.0;

    if (sec >= 0.5) {
        rand += 1;
        sfClock_restart(tm->clock_spawn);
    }
    return (rand);
}

sfIntRect clock_rect_enemy(enemy *cur, sfIntRect rect_enemy, int nb)
{
    sfTime time = sfClock_getElapsedTime(cur->clock_rect);
    float sec = (float) time.microseconds / 10000000.0;

    if (sec > 0.01) {
        rect_enemy.left += nb;
        sfClock_restart(cur->clock_rect);
    }
    if (rect_enemy.left >= 2100)
        rect_enemy.left = 0;
    return (rect_enemy);
}

sfIntRect clock_rect_enemy2(enemy *cur, sfIntRect rect_enemy, int nb)
{
    sfTime time = sfClock_getElapsedTime(cur->clock_rect);
    float sec = (float) time.microseconds / 10000000.0;

    if (sec > 0.01) {
        rect_enemy.left += nb;
        sfClock_restart(cur->clock_rect);
    }
    if (rect_enemy.left >= 1024 && rect_enemy.top <= 1360) {
        rect_enemy.left = 0;
        rect_enemy.top += 340;
    } else
        rect_enemy.top = 0;
    return (rect_enemy);
}
