/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** menu
*/

#ifndef MENU_H_
#define MENU_H_

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Audio.h>
#include "map.h"

typedef struct data_menu {
    sfSprite *background_menu;
    sfSprite *sprite_bouton_play;
    sfSprite *sprite_bouton_option;
    sfSprite *sprite_bouton_credit;
    sfIntRect rect_bouton;
    sfText *title;
    sfText *text_play;
    sfText *text_option;
    sfText *text_credit;
    sfEvent evt_menu;
} welcome;

typedef struct stick_loader {
    sfSprite *loader_on;
    sfSprite *loader_off;
    sfSprite *stick_loader;
    sfIntRect rect_loader;
    sfSprite *monster;
    sfSprite *monster_2;
    sfSprite *monster_3;
    sfSprite *monster_4;
    sfClock *clock_monster;
    sfIntRect rect_monster;
} set_loader;

void file_struct_menu(welcome *mn);
int cod_i_menu(sfVector2f vec_bouton, sfVector2f vec,
                sfSprite *sprite, welcome *mn);
int loop_loade(screen *weed, welcome mn);
void cod_i_init_loader(set_loader *loader);
void anim_monster_menu(set_loader *monster);
void display_monster_menu(set_loader *monster, screen *screen);
void destroy_monster_menu(set_loader *monster);
void create_anim_menu(set_loader *monster);
void setpos_menu(set_loader *monster);
void setpos_menu(set_loader *monster);
void set_pos_loader(set_loader *loader);

#endif /* !MENU_H_ */
