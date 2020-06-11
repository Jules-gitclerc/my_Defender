/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** menu
*/

#include "menu.h"
#include "enemy.h"

void setpos_menu(set_loader *monster)
{
    sfSprite_setTextureRect(monster->monster, monster->rect_monster);
    sfSprite_setTextureRect(monster->monster_2, monster->rect_monster);
    sfSprite_setTextureRect(monster->monster_3, monster->rect_monster);
    sfSprite_setTextureRect(monster->monster_4, monster->rect_monster);
}

void destroy_menu(welcome *mn, sfMusic *music_menu)
{
    sfMusic_destroy(music_menu);
    sfSprite_destroy(mn->background_menu);
    sfSprite_destroy(mn->sprite_bouton_play);
    sfSprite_destroy(mn->sprite_bouton_option);
    sfSprite_destroy(mn->sprite_bouton_credit);
}

void render_menu(welcome *mn, screen *weed)
{
    sfRenderWindow_clear(weed->window, sfBlack);
    sfRenderWindow_drawSprite(weed->window, mn->background_menu, NULL);
    sfRenderWindow_drawSprite(weed->window, mn->sprite_bouton_play, NULL);
    sfRenderWindow_drawSprite(weed->window, mn->sprite_bouton_option, NULL);
    sfRenderWindow_drawSprite(weed->window, mn->sprite_bouton_credit, NULL);
    sfRenderWindow_drawText(weed->window, mn->title, NULL);
    sfRenderWindow_drawText(weed->window, mn->text_play, NULL);
    sfRenderWindow_drawText(weed->window, mn->text_option, NULL);
    sfRenderWindow_drawText(weed->window, mn->text_credit, NULL);
    sfRenderWindow_display(weed->window);
}

int gest_coord(sfSprite *sprite, screen *weed, welcome *mn)
{
    sfVector2f vec_bouton = sfSprite_getPosition(sprite);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(weed->window);
    sfVector2f vec;

    vec.x = mouse.x;
    vec.y = mouse.y;
    cod_i_menu(vec_bouton, vec, sprite, mn);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (vec.x > vec_bouton.x && vec.x < vec_bouton.x + mn->rect_bouton.width
        && vec.y > vec_bouton.y &&
        vec.y < vec_bouton.y + mn->rect_bouton.height) {
            mn->rect_bouton.left = 1182;
            sfSprite_setTextureRect(sprite, mn->rect_bouton);
            render_menu(mn, weed);
            for (int i = 0; i < 100000; i++);
            return (1);
        }
    }
    return (0);
}

int menu(screen *weed)
{
    welcome mn;
    int i = 1;
    sfMusic *music_menu = sfMusic_createFromFile( \
                "./ressource/song/halo-theme-song-original.ogg");

    file_struct_menu(&mn);
    sfMusic_play(music_menu);
    while (i) {
        while (sfRenderWindow_pollEvent(weed->window, &mn.evt_menu)) {
            if (mn.evt_menu.key.code == sfKeyEscape ||
                mn.evt_menu.type == sfEvtClosed) {
                sfRenderWindow_close(weed->window);
                i = 2;
            }
            if (gest_coord(mn.sprite_bouton_play, weed, &mn) == 1) {
                i = 0;
                loop_loade(weed, mn);
            } if (gest_coord(mn.sprite_bouton_option, weed, &mn) == 1)
                i = 0;
        }
        if (gest_coord(mn.sprite_bouton_credit, weed, &mn) == 1) {
            i = 2;
            sfRenderWindow_close(weed->window);
        }
        if (i == 2)
            break;
        else if (i == 1)
            render_menu(&mn, weed);
    }
    destroy_menu(&mn, music_menu);
    return (i);
}
