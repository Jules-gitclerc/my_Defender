/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** set_vague
*/

#include "enemy.h"
#include "defender.h"

int cod_i_wave(sfVector2f vec_bouton, sfVector2f vec,
                sfSprite *sprite, vague *vg)
{
    if (vec.x > vec_bouton.x && vec.x < vec_bouton.x + vg->rect_b_wave.width
        && vec.y > vec_bouton.y &&
        vec.y < vec_bouton.y + vg->rect_b_wave.height) {
        vg->rect_b_wave.left = 425;
        sfSprite_setTextureRect(sprite, vg->rect_b_wave);
    } else {
        vg->rect_b_wave.left = 0;
        sfSprite_setTextureRect(sprite, vg->rect_b_wave);
    }
    return (0);
}

void create_vague(vague *vg, enemy *np)
{
    init_enemy(np, vg->spawn_enemy);
    vg->rand = 0;
}

void init_set_vague(vague* vg)
{
    sfVector2f vec = {763, 100};
    sfVector2f vec_text = {810, 120};
    sfFont *font = sfFont_createFromFile("./ressource/04B_30__.TTF");

    vg->wave_text = sfText_create();
    sfText_setString(vg->wave_text, "Wave");
    sfText_setFont(vg->wave_text, font);
    sfText_setCharacterSize(vg->wave_text, 80);
    sfText_setPosition(vg->wave_text, vec_text);
    vg->wave_bouton = create_sprite("./ressource/sprite_menu/MenuButtons.png");
    sfSprite_setPosition(vg->wave_bouton, vec);
    vg->spawn_enemy = 10;
    vg->rect_b_wave.width = 394;
    vg->rect_b_wave.height = 156;
    vg->rect_b_wave.left = 0;
    vg->rect_b_wave.top = 0;
}

int gest_coord_wave(sfSprite *sprite, screen *weed, vague *vg)
{
    sfVector2f vec_bouton = sfSprite_getPosition(sprite);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(weed->window);
    sfVector2f vec;

    vec.x = mouse.x;
    vec.y = mouse.y;
    cod_i_wave(vec_bouton, vec, sprite, vg);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (vec.x > vec_bouton.x && vec.x < vec_bouton.x + vg->rect_b_wave.width
        && vec.y > vec_bouton.y &&
        vec.y < vec_bouton.y + vg->rect_b_wave.height) {
            return (1);
        }
    }
    return (0);
}

void wave_main(g_s *g_s, game *gm, ball *missile)
{
    static int res = 0;

    if (res == 0) {
        sfRenderWindow_drawSprite(g_s->screen->window,
        g_s->vg->wave_bouton, NULL);
        sfRenderWindow_drawText(g_s->screen->window, g_s->vg->wave_text, NULL);
        if (gest_coord_wave(g_s->vg->wave_bouton, g_s->screen, g_s->vg) == 1)
            res = 1;
    } else if (res == 1) {
        enemy *np = malloc(sizeof(enemy));
        g_s->enemy = np;
        create_vague(g_s->vg, g_s->enemy);
        res = 2;
    } else {
        display_enemy(g_s->enemy, g_s->clock, g_s->screen->window, g_s->vg, gm);
        fire_tower(g_s->tower, g_s->enemy, missile, g_s->screen);
        check_life(g_s->enemy, gm, g_s->screen);
        if (check_wave_enemy(g_s->enemy) <= 1) {
            g_s->vg->nb_vague += 1;
            g_s->vg->spawn_enemy += 5;
            destroy_enemy(g_s->enemy);
            res = 0;
            g_s->enemy = malloc(sizeof(g_s->enemy));
        }
    }
}
