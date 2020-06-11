/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** gestion_coord_bad_tower
*/

#include "tower.h"

int check_bad_coord_bis(s_tower *tower)
{
    s_tower *target = tower;
    sfVector2f vec_sprite;
    sfVector2f vec;
    int i = 0;

    for (; target->next != NULL; target = target->next, i++);
    if (target->tower_sp == NULL || target->statu == 1)
        return (0);
    vec_sprite = sfSprite_getPosition(target->tower_sp);
    for (s_tower *cur = tower->next; cur != target; cur = cur->next) {
        vec = sfSprite_getPosition(cur->tower_sp);
        if (vec_sprite.x >= vec.x - 50 && vec_sprite.x <= vec.x + 145
        && vec_sprite.y >= vec.y - 50 && vec_sprite.y <= vec.y + 110) {
            delete_node(tower, i);
            return (0);
        }
    }
}

void check_bad_coord(s_tower *tower)
{
    sfVector2f vec;
    int i = 1;

    for (s_tower *cur = tower->next; cur != NULL; cur = cur->next, i++) {
        vec = sfSprite_getPosition(cur->tower_sp);
        if (cur->statu == 0 && vec.x >= 1550)
            delete_node(tower, i);
        else if (cur->statu == 0 && vec.x >= 120 && vec.x <= 240
                && vec.y <= 840)
            delete_node(tower, i);
        else if (cur->statu == 0 && vec.x >= 140 && vec.x <= 560 &&
        vec.y >= 640 && vec.y <= 780)
            delete_node(tower, i);
    }
    check_bad_coord_bis(tower);
}
