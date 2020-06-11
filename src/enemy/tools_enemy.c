/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tools_enemy
*/

#include "enemy.h"

sfSprite* create_sprite(char *image)
{
    sfTexture* texture;
    sfSprite* sprite;

    texture = sfTexture_createFromFile(image, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

sfIntRect create_rect_enemy(int nb)
{
    sfIntRect begin;

    if (nb == 0)
        begin.width = 256;
    else
        begin.width = 51;
    begin.height = 340;
    begin.left = 0;
    begin.top = 0;
    return (begin);
}
