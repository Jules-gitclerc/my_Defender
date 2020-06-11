/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** gest_event_tower
*/

#include "tower.h"

int change_color_bis(s_tower *tower)
{
    s_tower *target = tower;
    sfVector2f vec_sprite;
    sfVector2f vec;
    sfColor color_red = sfColor_fromRGBA(255, 0, 0, 100);
    sfColor color2 = sfColor_fromRGB(65, 105, 225);

    for (; target->next != NULL; target = target->next);
    if (target->tower_sp == NULL)
        return (0);
    vec_sprite = sfSprite_getPosition(target->tower_sp);
    for (s_tower *cur = tower->next; cur != target; cur = cur->next) {
        vec = sfSprite_getPosition(cur->tower_sp);
        if (vec_sprite.x >= vec.x - 50 && vec_sprite.x <= vec.x + 145
        && vec_sprite.y >= vec.y - 50 && vec_sprite.y <= vec.y + 110) {
            sfCircleShape_setOutlineColor(target->circle, color2);
            sfCircleShape_setFillColor(target->circle, color_red);
        }
    }
    return (1);
}

void change_color_bad_pos(s_tower *tower)
{
    sfVector2f vec;
    sfColor color = sfColor_fromRGBA(135, 206, 235, 100);
    sfColor color_red = sfColor_fromRGBA(255, 0, 0, 100);
    sfColor color2 = sfColor_fromRGB(65, 105, 225);

    for (s_tower *cur = tower->next; cur != NULL; cur = cur->next) {
        vec = sfSprite_getPosition(cur->tower_sp);
        if (cur->statu == 1 && vec.x >= 1550) {
            sfCircleShape_setOutlineColor(cur->circle, color2);
            sfCircleShape_setFillColor(cur->circle, color_red);
        } else if (cur->statu == 1 && vec.x >= 120 && vec.x <= 240
                && vec.y <= 840) {
            sfCircleShape_setOutlineColor(cur->circle, color2);
            sfCircleShape_setFillColor(cur->circle, color_red);
        } else if (cur->statu == 1 && vec.x >= 140 && vec.x <= 560
        && vec.y >= 640 && vec.y <= 780) {
            sfCircleShape_setOutlineColor(cur->circle, color2);
            sfCircleShape_setFillColor(cur->circle, color_red);
        } else {
            sfCircleShape_setOutlineColor(cur->circle, color2);
            sfCircleShape_setFillColor(cur->circle, color);
        }
    }
    change_color_bis(tower);
}

int set_clic_bouton(sfSprite *bouton, int width, int height,
sfRenderWindow *window)
{
    sfVector2f vec_sprite = sfSprite_getPosition(bouton);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f vec = {mouse.x, mouse.y};

    if (sfMouse_isButtonPressed(sfMouseLeft))
        if (vec.x >= vec_sprite.x && vec.x <= vec_sprite.x + width
        && vec.y >= vec_sprite.y && vec.y <= vec_sprite.y + height)
            return (0);
    return (1);
}

void display_bouton_select(s_tower *tower, place_t *place, screen *screen)
{
    sfVector2f vec1 = {660, 800};
    sfVector2f vec2 = {940, 800};
    int i = 0;

    sfSprite_setPosition(place->bouton_down, vec1);
    sfSprite_setPosition(place->bouton_up, vec2);
    for (s_tower *cur = tower; cur != NULL; cur = cur->next) {
        if (cur->selct == 1) {
            if (set_clic_bouton(place->bouton_down, 200, 232,
            screen->window) == 0) {
                delete_node(tower, i);
                remake_selct(tower);
                screen->nb += 2;
            }
            sfRenderWindow_drawSprite(screen->window, place->bouton_down, NULL);
            sfRenderWindow_drawSprite(screen->window, place->bouton_up, NULL);
        }
        i++;
    }
}

void ges_event_tower(s_tower *tower, screen *screen, place_t *place)
{
    sfVector2f vec_sprite;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(screen->window);
    sfVector2f vec = {mouse.x, mouse.y};

    for (s_tower* cur = tower->next; cur != NULL; cur = cur->next) {
        vec_sprite = sfSprite_getPosition(cur->tower_sp);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            if (vec.x >= vec_sprite.x &&
            vec.x <= vec_sprite.x + cur->rect_tower.width
            && vec.y >= vec_sprite.y && vec.y <= vec_sprite.y
            + cur->rect_tower.height && cur->statu == 0
            && cur->selct == 0) {
                remake_selct(tower);
                cur->selct = 1;
            }
        } else if (sfMouse_isButtonPressed(sfMouseRight)) {
            if (vec.x >= vec_sprite.x && vec.x <= vec_sprite.x +
            cur->rect_tower.width && vec.y >= vec_sprite.y &&
            vec.y <= vec_sprite.y + cur->rect_tower.height)
                remake_selct(tower);
        }
    }
    display_bouton_select(tower, place, screen);
}
