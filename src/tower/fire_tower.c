/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** fire_tower.c
*/

#include "enemy.h"
#include "tower.h"
#include "defender.h"

int clock_fire(enemy *cur, float nb)
{
    sfTime time = sfClock_getElapsedTime(cur->t_fire);
    float sec = (float) time.microseconds / 10000000.0;

    if (sec >= nb) {
        sfClock_restart(cur->t_fire);
        return (1);
    }
    return (0);
}

void delete_node_enemy(enemy *np, int i)
{
    enemy *target = np;
    enemy *cur = np;

    int o = 0;
    for (; o < i - 1; o++) {
        target = target->next;
        cur = cur->next;
    }
    target = target->next;
    cur->next = cur->next->next;
}

void check_life(enemy *np, game *gm, screen *screen)
{
    int i = 0;

    for (enemy *cur = np; cur != NULL; cur = cur->next, i++)
        if (cur->p_life <= 0) {
            screen->nb += 3;
            delete_node_enemy(np, i);
        }
}

int fire_tower(s_tower *tower, enemy *np, ball *misile, screen *screen)
{
    sfVector2f vec_enemy;
    sfVector2f vec_tower;
    float distance = 0;
    int i = 0;

    for (s_tower *cur_t = tower->next; cur_t != NULL; cur_t = cur_t->next) {
        vec_tower = sfSprite_getPosition(cur_t->tower_sp);
        for (enemy *cur_e = np->next; cur_e != NULL; cur_e = cur_e->next) {
            vec_enemy = sfSprite_getPosition(cur_e->sprite_enemy);
            distance = sqrtf(pow(vec_enemy.x - vec_tower.x, 2) +
            pow(vec_enemy.y - vec_tower.y, 2));
            i = clock_fire(cur_e, cur_t->attack_seepd);
            if (distance <= 180 && i == 1) {
                add_node_missile(misile, cur_t->tower_sp, cur_e->sprite_enemy);
                cur_e->p_life -= cur_t->dammage;
                break;
            }
        }
    }
}
