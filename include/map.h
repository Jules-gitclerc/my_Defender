/*
** EPITECH PROJECT, 2020
** defender/map.h
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Audio.h>
#include "enemy.h"

typedef struct map
{
    sfSprite *map;
    sfTexture *background;
    sfSprite *portal_blue;
    sfSprite *portal_red;
    sfSprite *heart;
    sfFont *font_coin;
    sfText *Text_coin;
    sfFont *font;
    sfText *text;
    sfIntRect rect_portal;
    sfClock *clock_portal;
} s_map;

typedef struct create_screen
{
    sfRenderWindow* window;
    sfEvent evt;
    int nb;
} screen;

void create_map(s_map *map);
void display_map(s_map *map, screen *screen);
void display_heart(s_map *heart, screen *screen, game *gm);
void display_portal(s_map *portal, screen *screen);
void create_heart(s_map *heart);
void anim_portal(s_map *portal);
void create_portal(s_map *portal);
void destroy_portal(s_map *portal);
void destroy_heart(s_map *heart);
void create_coin(s_map *coin);
void display_coin(screen *screen, s_map *coin);
void destroy_coin(s_map *coin);

#endif /* !MAP_H_ */
