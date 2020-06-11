/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ia_enemy
*/

#include "enemy.h"
#include "defender.h"
#include <math.h>

void set_bar_file(enemy *cur)
{
    sfVector2f vec;
    sfIntRect rect;

    rect.width = cur->p_life;
    rect.left = 0;
    rect.top = 0;
    rect.height = 38;
    vec = sfSprite_getPosition(cur->sprite_enemy);
    vec.x -= 20;
    vec.y -= 20;
    sfSprite_setTextureRect(cur->life_sprite, rect);
    sfSprite_setPosition(cur->life_sprite, vec);
}

void delete_enemy(enemy *cur, game *gm, enemy *np, int o)
{
    sfVector2f tab[] = {{167, 85}, {167, 815}, {442, 815}, {442, 10}, {722, 10},
                {722, 955}, {1005, 955}, {1005, 250}, {1422, 250}, {1422, 810},
                {1652, 810}, {-1, -1}};
        if (tab[cur->i].x == -1) {
        delete_node_enemy(np, o);
        gm->life -= 1;
        return;
    }
}

void moove_enemy(enemy *cur, game *gm, int o, enemy *np)
{
    sfVector2f vec = sfSprite_getPosition(cur->sprite_enemy);
    sfVector2f tab[] = {{167, 85}, {167, 815}, {442, 815}, {442, 10}, {722, 10},
                {722, 955}, {1005, 955}, {1005, 250}, {1422, 250}, {1422, 810},
                {1652, 810}, {-1, -1}};
    float distance = sqrtf(pow(tab[cur->i].x - tab[cur->i - 1].x, 2) +
    pow(tab[cur->i].y - tab[cur->i - 1].y, 2));
    sfVector2f dist_btw_pos = {tab[cur->i].x - tab[cur->i - 1].x,
    tab[cur->i].y - tab[cur->i - 1].y};
    sfVector2f result = {dist_btw_pos.x / distance, dist_btw_pos.y / distance};
    sfVector2f transformation = {result.x * 0.02, result.y * 0.02};
    float x = vec.x;
    float y = vec.y;
    delete_enemy(cur, gm, np, o);
    vec.x += transformation.x;
    vec.y += transformation.y;
    sfSprite_setPosition(cur->sprite_enemy, (sfVector2f){vec.x, vec.y});
    if (x >= tab[cur->i].x - 1 && x <= tab[cur->i].x + 1 &&
    y >= tab[cur->i].y - 1 && y <= tab[cur->i].y + 1)
        cur->i++;
}
