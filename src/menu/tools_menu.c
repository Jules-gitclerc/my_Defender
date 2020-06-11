/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tools_menu
*/

#include "menu.h"
#include "enemy.h"

int cod_i_menu(sfVector2f vec_bouton, sfVector2f vec,
                sfSprite *sprite, welcome *mn)
{
    if (vec.x > vec_bouton.x && vec.x < vec_bouton.x + mn->rect_bouton.width
        && vec.y > vec_bouton.y &&
        vec.y < vec_bouton.y + mn->rect_bouton.height) {
        mn->rect_bouton.left = 425;
        sfSprite_setTextureRect(sprite, mn->rect_bouton);
    } else {
        mn->rect_bouton.left = 0;
        sfSprite_setTextureRect(sprite, mn->rect_bouton);
    }
    return (0);
}

void text_position(welcome *mn)
{
    sfVector2f vec_title = {800, 90};
    sfVector2f vec_text_play = {885, 390};
    sfVector2f vec_text_option = {850, 590};
    sfVector2f vec_text_credit = {850, 790};

    sfText_setPosition(mn->text_play, vec_text_play);
    sfText_setPosition(mn->title, vec_title);
    sfText_setPosition(mn->text_option, vec_text_option);
    sfText_setPosition(mn->text_credit, vec_text_credit);
}

void create_text(welcome *mn)
{
    sfFont *font = sfFont_createFromFile("./ressource/04B_30__.TTF");

    mn->title = sfText_create();
    mn->text_play = sfText_create();
    mn->text_option = sfText_create();
    mn->text_credit = sfText_create();
    sfText_setString(mn->title, "SPLOOF");
    sfText_setString(mn->text_play, "PLAY");
    sfText_setString(mn->text_option, "OPTIONS");
    sfText_setString(mn->text_credit, "QUIT");
    sfText_setFont(mn->title, font);
    sfText_setFont(mn->text_play, font);
    sfText_setFont(mn->text_option, font);
    sfText_setFont(mn->text_credit, font);
    sfText_setCharacterSize(mn->title, 70);
    sfText_setCharacterSize(mn->text_play, 50);
    sfText_setCharacterSize(mn->text_option, 50);
    sfText_setCharacterSize(mn->text_credit, 50);
    text_position(mn);
}

void position_management(welcome *mn)
{
    sfVector2f vec_back = {520, 80};
    sfVector2f vec_bouton_play = {800, 350};
    sfVector2f vec_bouton_option = {800, 550};
    sfVector2f vec_bouton_credit = {800, 750};

    sfSprite_setTextureRect(mn->sprite_bouton_play, mn->rect_bouton);
    sfSprite_setTextureRect(mn->sprite_bouton_option, mn->rect_bouton);
    sfSprite_setTextureRect(mn->sprite_bouton_credit, mn->rect_bouton);
    sfSprite_setPosition(mn->background_menu, vec_back);
    sfSprite_setPosition(mn->sprite_bouton_play, vec_bouton_play);
    sfSprite_setPosition(mn->sprite_bouton_option, vec_bouton_option);
    sfSprite_setPosition(mn->sprite_bouton_credit, vec_bouton_credit);
}

void file_struct_menu(welcome *mn)
{
    mn->background_menu = create_sprite(
        "./ressource/sprite_menu/MenuBackground.png");
    mn->sprite_bouton_play = create_sprite(
        "./ressource/sprite_menu/MenuButtons.png");
    mn->sprite_bouton_option = create_sprite(
        "./ressource/sprite_menu/MenuButtons.png");
    mn->sprite_bouton_credit = create_sprite(
        "./ressource/sprite_menu/MenuButtons.png");
    mn->rect_bouton.width = 394;
    mn->rect_bouton.height = 156;
    mn->rect_bouton.left = 0;
    mn->rect_bouton.top = 0;
    position_management(mn);
    create_text(mn);
}
