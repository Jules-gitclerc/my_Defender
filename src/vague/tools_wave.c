/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** tools_wave.c
*/

#include "map.h"
#include "enemy.h"

int check_wave_enemy(enemy *np)
{
    int nb = 0;

    for (enemy *cur = np; cur != NULL; cur = cur->next, nb++);
    return (nb);
}