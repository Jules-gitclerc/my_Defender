/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** display_upgrade
*/

#include "tower.h"

void display_tower_1(s_up_tower *upgrade, screen *screen)
{
    sfRenderWindow_drawText(screen->window, upgrade->t1_up_1, NULL);
    sfRenderWindow_drawText(screen->window, upgrade->t1_up_2, NULL);
    sfRenderWindow_drawText(screen->window, upgrade->t1_up_3, NULL);
}

void display_tower_2(s_up_tower *upgrade, screen *screen)
{
    sfRenderWindow_drawText(screen->window, upgrade->t2_up_1, NULL);
    sfRenderWindow_drawText(screen->window, upgrade->t2_up_2, NULL);
    sfRenderWindow_drawText(screen->window, upgrade->t2_up_3, NULL);
}

void display_tower_3(s_up_tower *upgrade, screen *screen)
{
    sfRenderWindow_drawText(screen->window, upgrade->t3_up_1, NULL);
    sfRenderWindow_drawText(screen->window, upgrade->t3_up_2, NULL);
    sfRenderWindow_drawText(screen->window, upgrade->t3_up_3, NULL);
}

void display_tower_4(s_up_tower *upgrade, screen *screen)
{
    sfRenderWindow_drawText(screen->window, upgrade->t4_up_1, NULL);
    sfRenderWindow_drawText(screen->window, upgrade->t4_up_2, NULL);
    sfRenderWindow_drawText(screen->window, upgrade->t4_up_3, NULL);
}