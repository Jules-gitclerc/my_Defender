/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** coins
*/
#include "map.h"
#include "enemy.h"
#include "my.h"

void create_coin(s_map *coin)
{
    sfVector2f vec = {5, 2};

    coin->font_coin = sfFont_createFromFile("./ressource/American Captain.ttf");
    coin->Text_coin = sfText_create();
    sfText_setString(coin->Text_coin, "20");
    sfText_setFont(coin->Text_coin, coin->font_coin);
    sfText_setCharacterSize(coin->Text_coin, 70);
    sfText_setPosition(coin->Text_coin, vec);
}

void display_coin(screen *screen, s_map *coin)
{
    sfText_setString(coin->Text_coin, my_supergetnbr(screen->nb));
    sfRenderWindow_drawText(screen->window, coin->Text_coin, NULL);
}

void destroy_coin(s_map *coin)
{
    sfText_destroy(coin->Text_coin);
}
