/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** upgrate_tower
*/

#include "tower.h"

void set_string(s_up_tower *upgrate)
{
    sfText_setString(upgrate->t1_up_1, "+2");
    sfText_setString(upgrate->t1_up_2, "-0.2");
    sfText_setString(upgrate->t1_up_3, "+10");
    sfText_setString(upgrate->t2_up_1, "+2");
    sfText_setString(upgrate->t2_up_2, "-0.2");
    sfText_setString(upgrate->t2_up_3, "+10");
    sfText_setString(upgrate->t3_up_1, "+2");
    sfText_setString(upgrate->t3_up_2, "-0.2");
    sfText_setString(upgrate->t3_up_3, "+10");
    sfText_setString(upgrate->t4_up_1, "+2");
    sfText_setString(upgrate->t4_up_2, "-0.2");
    sfText_setString(upgrate->t4_up_3, "+10");
}

void set_size(s_up_tower *upgrade)
{
    sfText_setCharacterSize(upgrade->t1_up_1, 20);
    sfText_setCharacterSize(upgrade->t1_up_2, 20);
    sfText_setCharacterSize(upgrade->t1_up_3, 20);
    sfText_setCharacterSize(upgrade->t2_up_1, 20);
    sfText_setCharacterSize(upgrade->t2_up_2, 20);
    sfText_setCharacterSize(upgrade->t2_up_3, 20);
    sfText_setCharacterSize(upgrade->t3_up_1, 20);
    sfText_setCharacterSize(upgrade->t3_up_2, 20);
    sfText_setCharacterSize(upgrade->t3_up_3, 20);
    sfText_setCharacterSize(upgrade->t4_up_1, 20);
    sfText_setCharacterSize(upgrade->t4_up_2, 20);
    sfText_setCharacterSize(upgrade->t4_up_3, 20);
}

void set_font(s_up_tower *upgrade)
{
    sfText_setFont(upgrade->t1_up_1, upgrade->font);
    sfText_setFont(upgrade->t1_up_2, upgrade->font);
    sfText_setFont(upgrade->t1_up_3, upgrade->font);
    sfText_setFont(upgrade->t2_up_1, upgrade->font);
    sfText_setFont(upgrade->t2_up_2, upgrade->font);
    sfText_setFont(upgrade->t2_up_3, upgrade->font);
    sfText_setFont(upgrade->t3_up_1, upgrade->font);
    sfText_setFont(upgrade->t3_up_2, upgrade->font);
    sfText_setFont(upgrade->t3_up_3, upgrade->font);
    sfText_setFont(upgrade->t4_up_1, upgrade->font);
    sfText_setFont(upgrade->t4_up_2, upgrade->font);
    sfText_setFont(upgrade->t4_up_3, upgrade->font);
}

void create_upgrade(s_up_tower *upgrade)
{
    upgrade->font = sfFont_createFromFile("./ressource/American Captain.ttf");
    upgrade->t1_up_1 = sfText_create();
    upgrade->t1_up_2 = sfText_create();
    upgrade->t1_up_3 = sfText_create();
    upgrade->t2_up_1 = sfText_create();
    upgrade->t2_up_2 = sfText_create();
    upgrade->t2_up_3 = sfText_create();
    upgrade->t3_up_1 = sfText_create();
    upgrade->t3_up_2 = sfText_create();
    upgrade->t3_up_3 = sfText_create();
    upgrade->t4_up_1 = sfText_create();
    upgrade->t4_up_2 = sfText_create();
    upgrade->t4_up_3 = sfText_create();
}

void upgrade(s_up_tower *upgrade)
{
    sfVector2f vec1 = {320, 840};
    sfVector2f vec2 = {320, 860};
    sfVector2f vec3 = {320, 880};

    create_upgrade(upgrade);
    set_font(upgrade);
    set_size(upgrade);
    set_string(upgrade);
    sfText_setPosition(upgrade->t1_up_1, vec1);
    sfText_setPosition(upgrade->t1_up_2, vec2);
    sfText_setPosition(upgrade->t1_up_3, vec3);
    sfText_setPosition(upgrade->t2_up_1, vec1);
    sfText_setPosition(upgrade->t2_up_2, vec2);
    sfText_setPosition(upgrade->t2_up_3, vec3);
    sfText_setPosition(upgrade->t3_up_1, vec1);
    sfText_setPosition(upgrade->t3_up_2, vec2);
    sfText_setPosition(upgrade->t3_up_3, vec3);
    sfText_setPosition(upgrade->t4_up_1, vec1);
    sfText_setPosition(upgrade->t4_up_2, vec2);
    sfText_setPosition(upgrade->t4_up_3, vec3);
}