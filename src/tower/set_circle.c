/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_cur
*/


#include "my.h"
#include "enemy.h"
#include "map.h"
#include "tower.h"

void set_circle(s_tower *cur)
{
    sfColor color = sfColor_fromRGBA(135, 206, 235, 100);
    sfColor color2 = sfColor_fromRGB(65, 105, 225);
    sfCircleShape_setRadius(cur->circle, 300);
    sfCircleShape_setOutlineColor(cur->circle, color2);
    sfCircleShape_setFillColor(cur->circle, color);
}