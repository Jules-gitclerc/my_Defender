/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** create_map
*/

#include "map.h"
#include "defender.h"
#include "enemy.h"

void create_map(s_map *map)
{
    map->map = sfSprite_create();
    map->background = sfTexture_createFromFile(
        "./ressource/sprite_map/map.png", NULL);
    sfSprite_setTexture(map->map, map->background, sfTrue);
}

void display_map(s_map *map, screen *screen)
{
    sfRenderWindow_drawSprite(screen->window, map->map, NULL);
}