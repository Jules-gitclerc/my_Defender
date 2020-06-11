/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** heart
*/

#include "map.h"
#include "enemy.h"
#include "my.h"

void create_heart(s_map *heart)
{
    sfVector2f vec = {1750, 35};
    sfVector2f vec_text = {1792, 80};

    heart->heart = create_sprite(
        "./ressource/sprite_map/heart.png");
    heart->font = sfFont_createFromFile("./ressource/04B_30__.TTF");
    heart->text = sfText_create();
    sfText_setString(heart->text, "10");
    sfText_setFont(heart->text, heart->font);
    sfText_setCharacterSize(heart->text, 40);
    sfText_setPosition(heart->text, vec_text);
    sfSprite_setPosition(heart->heart, vec);
}

void display_heart(s_map *heart, screen *screen, game *gm)
{
    sfText_setString(heart->text, my_supergetnbr(gm->life));
    sfRenderWindow_drawSprite(screen->window, heart->heart, NULL);
    sfRenderWindow_drawText(screen->window, heart->text, NULL);
}

void destroy_heart(s_map *heart)
{
    sfSprite_destroy(heart->heart);
    sfText_destroy(heart->text);
}