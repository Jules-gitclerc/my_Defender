/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** game_over.c
*/

#include "defender.h"
#include "map.h"

int check_lige(screen *screen, game *gm)
{
    if (gm->life <= 0) {
        return (1);
    }
    return (0);
}
