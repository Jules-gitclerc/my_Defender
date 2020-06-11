/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** pause
*/

#include "defender.h"
#include "map.h"
#include "enemy.h"
#include "pause.h"

void fill_pause(s_pause *ps)
{
    ps->background_pause = create_sprite(
        "./ressource/sprite_menu/MenuBackground.png");
    ps->sprite_bouton_resume = create_sprite(
        "./ressource/sprite_menu/MenuButtons.png");
    ps->sprite_bouton_option = create_sprite(
        "./ressource/sprite_menu/MenuButtons.png");
    ps->sprite_bouton_quit = create_sprite(
        "./ressource/sprite_menu/MenuButtons.png");
    ps->rect_bouton.width = 394;
    ps->rect_bouton.height = 156;
    ps->rect_bouton.left = 0;
    ps->rect_bouton.top = 0;
    create_text_pause(ps);
    set_pos_pause(ps);
}

void render_pause(s_pause *ps, screen *screen, g_s *g_s, place_t *place)
{
    enemy *cur = g_s->enemy->next;

    sfRenderWindow_clear(screen->window, sfBlack);
    display_map(g_s->map, g_s->screen);
    sfRenderWindow_drawSprite(screen->window, place->tower_1, NULL);
    sfRenderWindow_drawSprite(screen->window, place->tower_2, NULL);
    sfRenderWindow_drawSprite(screen->window, place->tower_3, NULL);
    sfRenderWindow_drawSprite(screen->window, place->tower_4, NULL);
    fill_calc(g_s->tower);
    algo_display_tower(g_s->tower, screen);
    render_pause_bis(ps, screen);
}

int cod_i_pause(sfVector2f vec_bouton, sfVector2f vec,
                sfSprite *sprite, s_pause *ps)
{
    if (vec.x > vec_bouton.x && vec.x < vec_bouton.x + ps->rect_bouton.width
        && vec.y > vec_bouton.y &&
        vec.y < vec_bouton.y + ps->rect_bouton.height) {
        ps->rect_bouton.left = 425;
        sfSprite_setTextureRect(sprite, ps->rect_bouton);
    } else {
        ps->rect_bouton.left = 0;
        sfSprite_setTextureRect(sprite, ps->rect_bouton);
    }
    return (0);
}

int gest_coord_pause(sfSprite *sprite, screen *weed, s_pause *ps)
{
    sfVector2f vec_bouton = sfSprite_getPosition(sprite);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(weed->window);
    sfVector2f vec = {mouse.x, mouse.y};

    cod_i_pause(vec_bouton, vec, sprite, ps);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (vec.x > vec_bouton.x && vec.x < vec_bouton.x + ps->rect_bouton.width
        && vec.y > vec_bouton.y &&
        vec.y < vec_bouton.y + ps->rect_bouton.height) {
            return (1);
        }
    }
    return (0);
}

int pause(screen *weed, g_s *g_s, place_t *place)
{
    int i = 1;
    s_pause ps;

    fill_pause(&ps);
    while (i) {
        while (sfRenderWindow_pollEvent(weed->window, &ps.evt)) {
            if (ps.evt.key.code == sfKeyEscape ||
                ps.evt.type == sfEvtClosed) {
                sfRenderWindow_close(weed->window);
                i = 0;
            }
        }
        if (gest_coord_pause(ps.sprite_bouton_resume, g_s->screen, &ps) == 1)
            i = 0;
        if (gest_coord_pause(ps.sprite_bouton_quit, g_s->screen, &ps) == 1) {
            i = 2;
            break;
        }
        render_pause(&ps, g_s->screen, g_s, place);
    }
    destroy_pause(&ps);
    if (i == 2) {
        return (2);
    }
}