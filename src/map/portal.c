/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** portal
*/

#include "map.h"
#include "defender.h"
#include "enemy.h"

void create_portal(s_map *portal)
{
    sfIntRect rect = {0, 0, 140, 192};
    sfVector2f vec = {140, 5};
    sfVector2f vec_2 = {1620, 800};

    portal->portal_blue = create_sprite(
        "./ressource/sprite_map/portal_blue.png");
    portal->portal_red = create_sprite(
        "./ressource/sprite_map/portal_red_2.png");
    portal->rect_portal = rect;
    sfSprite_setPosition(portal->portal_blue, vec);
    sfSprite_setPosition(portal->portal_red, vec_2);
    sfSprite_setTextureRect(portal->portal_blue, rect);
    sfSprite_setTextureRect(portal->portal_red, rect);
    portal->clock_portal = sfClock_create();
}

void anim_portal(s_map *portal)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(portal->clock_portal))
        >= 60) {
        if (portal->rect_portal.left >= 2100)
            portal->rect_portal.left = 0;
        else
            portal->rect_portal.left += 140;
        sfClock_restart(portal->clock_portal);
    }
    sfSprite_setTextureRect(portal->portal_blue, portal->rect_portal);
    sfSprite_setTextureRect(portal->portal_red, portal->rect_portal);
}

void display_portal(s_map *portal, screen *screen)
{
    sfRenderWindow_drawSprite(screen->window, portal->portal_blue, NULL);
    sfRenderWindow_drawSprite(screen->window, portal->portal_red, NULL);
}

void destroy_portal(s_map *portal)
{
    sfSprite_destroy(portal->portal_blue);
    sfSprite_destroy(portal->portal_red);
    sfClock_destroy(portal->clock_portal);
}