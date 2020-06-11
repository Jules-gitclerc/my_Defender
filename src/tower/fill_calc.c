/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** fill_calc.c
*/

#include "enemy.h"
#include "tower.h"

void fill_calc_bis(s_tower *cur, int dis, sfVector2f vec)
{
    for (int i = 1; i <= 8; i++)
        if (vec.y <= dis * i) {
            cur->calc = i;
            break;
        }
}

void fill_calc(s_tower *tower)
{
    sfVector2f vec;
    int dis = 140;

    for (s_tower *cur = tower->next; cur != NULL; cur = cur->next) {
        vec = sfSprite_getPosition(cur->tower_sp);
        fill_calc_bis(cur, dis, vec);
    }
}

void algo_bis_tower(s_tower *cur, screen *screen, int i)
{
    if (cur->calc == i) {
        if (cur->statu == 1 || cur->selct == 1)
            sfRenderWindow_drawCircleShape(screen->window, cur->circle, NULL);
        sfRenderWindow_drawSprite(screen->window, cur->tower_sp, NULL);
    }
}

void algo_display_tower(s_tower *tower, screen *screen)
{
    for (int i = 1; i <= 8; i++)
        for (s_tower *cur = tower->next; cur != NULL; cur = cur->next)
            algo_bis_tower(cur, screen, i);
}