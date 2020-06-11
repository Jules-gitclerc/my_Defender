/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** tireh.c
*/

#include "my.h"

int print_tireh(char *str, int ac)
{
    if (ac == 1)
        return (0);
    if (str[0] == '-' && str[1] == 'h' && my_strlen(str) == 2) {
        my_printf("USAGE:\n\t./defender\n\n");
        my_printf("ORDERS:\n\tP to pause\n\tEscape to exit\n");
        my_printf("GAME:\n\tPress the turret on the ");
        my_printf("right and place them on the map.\n\t");
        my_printf("Eliminate all enemies to win.\n");
        return (1);
    }
    return (0);
}