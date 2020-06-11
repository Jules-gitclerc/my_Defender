/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** anime_tower
*/

#include "tower.h"

int change_spe(s_tower *cur, int nb)
{
    if (nb == 1) {
        cur->dammage = 5;
        cur->attack_seepd = 1;
        cur->crital = 10;
    } if (nb == 2) {
        cur->dammage = 6;
        cur->attack_seepd = 1.2;
        cur->crital = 20;
    } if (nb == 3) {
        cur->dammage = 8;
        cur->attack_seepd = 1;
        cur->crital = 30;
    } if (nb == 4) {
        cur->dammage = 12;
        cur->attack_seepd = 0.7;
        cur->crital = 40;
    }
}

void remake_selct(s_tower *tower)
{
    for (s_tower *cur = tower; cur != NULL; cur = cur->next)
        cur->selct = 0;
}

void clock_anime_tower(s_tower *cur, int nb)
{
    sfTime time = sfClock_getElapsedTime(cur->clock_tower);
    float sec = (float) time.microseconds / 10000000.0;

    if (sec > 0.01) {
        cur->rect_tower.left += 140;
        sfClock_restart(cur->clock_tower);
    }
    if (cur->rect_tower.left >= nb)
        cur->rect_tower.left = 0;
}

void anime_tower(s_tower *tower)
{
    for (s_tower *cur = tower->next; cur != NULL; cur = cur->next) {
        if (cur->t_tower == 1)
            clock_anime_tower(cur, 2040);
        if (cur->t_tower == 3)
            clock_anime_tower(cur, 5880);
        if (cur->t_tower == 4)
            clock_anime_tower(cur, 3640);
        if (cur->t_tower == 2)
            clock_anime_tower(cur, 4760);
        sfSprite_setTextureRect(cur->tower_sp, cur->rect_tower);
    }
}
