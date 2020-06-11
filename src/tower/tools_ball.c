/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tools_ball
*/

#include "tower.h"

void destroy_node_ball(ball *missile, int i)
{
    ball *target = missile;
    ball *cur = missile;

    int o = 0;
    for (; o < i - 1; o++) {
        target = target->next;
        cur = cur->next;
    }
    target = target->next;
    cur->next = cur->next->next;
}

void init_head_missile(ball *missile)
{
    missile->fire = NULL;
    missile->next = NULL;
}

void destroy_missile(ball *missile)
{
    ball *cur = missile;
    ball *next = missile->next;

    while (next != NULL) {
        cur = next;
        next = next->next;
        sfSprite_destroy(cur->fire);
        sfClock_destroy(cur->clock_moove);
        free (cur);
    }
    free (missile);
}
