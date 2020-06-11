/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** cost_tower
*/

#include "tower.h"
#include "map.h"

void set_position_cost_tower(place_t *cost)
{
    sfVector2f vec_1 = {1812, 333};
    sfVector2f vec_2 = {1812, 506};
    sfVector2f vec_3 = {1812, 683};
    sfVector2f vec_4 = {1806, 857};
    sfText_setCharacterSize(cost->text_t_1, 40);
    sfText_setCharacterSize(cost->text_t_2, 40);
    sfText_setCharacterSize(cost->text_t_3, 40);
    sfText_setCharacterSize(cost->text_t_4, 40);
    sfText_setPosition(cost->text_t_1, vec_1);
    sfText_setPosition(cost->text_t_2, vec_2);
    sfText_setPosition(cost->text_t_3, vec_3);
    sfText_setPosition(cost->text_t_4, vec_4);
}

void create_cost_tower(place_t *cost)
{
    cost->font = sfFont_createFromFile("./ressource/American Captain.ttf");
    cost->text_t_1 = sfText_create();
    cost->text_t_2 = sfText_create();
    cost->text_t_3 = sfText_create();
    cost->text_t_4 = sfText_create();
    sfText_setString(cost->text_t_1, "2$");
    sfText_setString(cost->text_t_2, "4$");
    sfText_setString(cost->text_t_3, "8$");
    sfText_setString(cost->text_t_4, "10$");
    sfText_setFont(cost->text_t_1, cost->font);
    sfText_setFont(cost->text_t_2, cost->font);
    sfText_setFont(cost->text_t_3, cost->font);
    sfText_setFont(cost->text_t_4, cost->font);
    set_position_cost_tower(cost);
}

void display_cost_tower(place_t *cost, screen *screen)
{
    sfRenderWindow_drawText(screen->window, cost->text_t_1, NULL);
    sfRenderWindow_drawText(screen->window, cost->text_t_2, NULL);
    sfRenderWindow_drawText(screen->window, cost->text_t_3, NULL);
    sfRenderWindow_drawText(screen->window, cost->text_t_4, NULL);
}

void destroy_cost_tower(place_t *cost)
{
    sfText_destroy(cost->text_t_1);
    sfText_destroy(cost->text_t_2);
    sfText_destroy(cost->text_t_3);
    sfText_destroy(cost->text_t_4);
}