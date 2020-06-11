/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tools_load_stick
*/


#include "menu.h"
#include "defender.h"
#include "enemy.h"

void cod_i_init_loader(set_loader *loader)
{
    sfIntRect rect = {0, 0, 691, 100};

    sfSprite_setTextureRect(loader->stick_loader, rect);
    rect.top += 100;
    sfSprite_setTextureRect(loader->loader_off, rect);
    loader->rect_loader.height = 60;
    loader->rect_loader.width = 0;
    loader->rect_loader.left = 0;
    loader->rect_loader.top = 189;
    sfSprite_setTextureRect(loader->loader_on, loader->rect_loader);
    set_pos_loader(loader);
}

void create_anim_menu(set_loader *monster)
{
    sfIntRect rect = {0, 0, 150, 250};
    sfVector2f vec = {650, 250};
    sfVector2f vec_2 = {800, 250};
    sfVector2f vec_3 = {950, 250};
    sfVector2f vec_4 = {1100, 250};

    monster->monster = create_sprite(
        "./ressource/sprite_enemy/blue_down.png");
    monster->monster_2 = create_sprite(
        "./ressource/sprite_enemy/green_down.png");
    monster->monster_3 = create_sprite(
        "./ressource/sprite_enemy/purple_down.png");
    monster->monster_4 = create_sprite(
        "./ressource/sprite_enemy/red_down.png");
    monster->rect_monster =  rect;
    sfSprite_setPosition(monster->monster, vec);
    sfSprite_setPosition(monster->monster_2, vec_2);
    sfSprite_setPosition(monster->monster_3, vec_3);
    sfSprite_setPosition(monster->monster_4, vec_4);
    setpos_menu(monster);
    monster->clock_monster = sfClock_create();
}

void anim_monster_menu(set_loader *monster)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(monster->clock_monster))
        >= 125.5) {
        if (monster->rect_monster.left >= 1950)
            monster->rect_monster.left = 0;
        else
            monster->rect_monster.left += 150;
        sfClock_restart(monster->clock_monster);
    }
    sfSprite_setTextureRect(monster->monster, monster->rect_monster);
    sfSprite_setTextureRect(monster->monster_2, monster->rect_monster);
    sfSprite_setTextureRect(monster->monster_3, monster->rect_monster);
    sfSprite_setTextureRect(monster->monster_4, monster->rect_monster);
}

void display_monster_menu(set_loader *monster, screen *screen)
{
    sfRenderWindow_drawSprite(screen->window, monster->monster, NULL);
    sfRenderWindow_drawSprite(screen->window, monster->monster_2, NULL);
    sfRenderWindow_drawSprite(screen->window, monster->monster_3, NULL);
    sfRenderWindow_drawSprite(screen->window, monster->monster_4, NULL);
}

void destroy_monster_menu(set_loader *monster)
{
    sfSprite_destroy(monster->monster);
    sfSprite_destroy(monster->monster_2);
    sfSprite_destroy(monster->monster_3);
    sfSprite_destroy(monster->monster_4);
    sfClock_destroy(monster->clock_monster);
}