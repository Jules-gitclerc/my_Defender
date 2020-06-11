/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** display_tower
*/

#include "my.h"
#include "enemy.h"
#include "map.h"
#include "tower.h"
#include <stdio.h>

void create_tower(place_t *place)
{
    place->tower_1 = create_sprite(
        "./ressource/sprite_tower/button_1.png");
    place->tower_2 = create_sprite(
        "./ressource/sprite_tower/button_2.png");
    place->tower_3 = create_sprite(
        "./ressource/sprite_tower/button_3.png");
    place->tower_4 = create_sprite(
        "./ressource/sprite_tower/button_4.png");
    place->bouton_down = create_sprite(
        "./ressource/sprite_tower/sell_button.png");
    place->bouton_up = create_sprite(
        "./ressource/sprite_tower/upgrade_button.png");
    sfSprite_setPosition(place->tower_1, (sfVector2f){1725, 200});
    sfSprite_setPosition(place->tower_2, (sfVector2f){1725, 375});
    sfSprite_setPosition(place->tower_3, (sfVector2f){1725, 550});
    sfSprite_setPosition(place->tower_4, (sfVector2f){1725, 725});
    init_card_sprite(place);
}

int set_tower_pos(s_tower *tower, screen *screen)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(screen->window);
    sfVector2f vec = {mouse.x - 70, mouse.y - 126};
    sfVector2f vec1 = {mouse.x - 300, mouse.y - 250};

    for (s_tower *cur = tower; cur != NULL; cur = cur->next) {
        if (cur->statu == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
            sfCircleShape_setPosition(cur->circle, vec1);
            sfSprite_setPosition(cur->tower_sp, vec);
            change_color_bad_pos(tower);
            return (0);
        } else {
            cur->statu = 0;
        }
    }
    return (1);
}

void gest_mouse_dp(s_tower *tower, place_t *place, screen *screen)
{
    sfVector2f vec_sprite = sfSprite_getPosition(place->tower_1);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(screen->window);
    sfVector2f vec;
    static int loop = 1;

    vec.x = mouse.x;
    vec.y = mouse.y;
    while (loop) {
        if (vec.x >= vec_sprite.x && vec.x <= vec_sprite.x + 200 &&
        screen->nb >= 2 && vec.y >= vec_sprite.y
        && vec.y <= vec_sprite.y + 200
        && sfMouse_isButtonPressed(sfMouseLeft)) {
            add_node(1, "./ressource/sprite_tower/tower_gray.png", tower);
            screen->nb -= 2;
            break;
        }
        vec_sprite = sfSprite_getPosition(place->tower_2);
        if (vec.x >= vec_sprite.x && vec.x <= vec_sprite.x + 200 &&
        screen->nb >= 4 && vec.y >= vec_sprite.y && vec.y <= vec_sprite.y + 200
        && sfMouse_isButtonPressed(sfMouseLeft)) {
            add_node(2, "./ressource/sprite_tower/tower_blue.png", tower);
            screen->nb -= 4;
            break;
        }
        vec_sprite = sfSprite_getPosition(place->tower_3);
        if (vec.x >= vec_sprite.x && vec.x <= vec_sprite.x + 200 &&
        screen->nb >= 6 && vec.y >= vec_sprite.y && vec.y <= vec_sprite.y + 200
        && sfMouse_isButtonPressed(sfMouseLeft)) {
            add_node(3, "./ressource/sprite_tower/tower_green.png", tower);
            screen->nb -= 6;
            break;
        }
        vec_sprite = sfSprite_getPosition(place->tower_4);
        if (vec.x >= vec_sprite.x && vec.x <= vec_sprite.x + 200
        && screen->nb >= 8 && vec.y >= vec_sprite.y
        && vec.y <= vec_sprite.y + 200 &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
            add_node(4, "./ressource/sprite_tower/tower_red.png", tower);
            screen->nb -= 8;
            break;
        }
        break;
    }
    loop = set_tower_pos(tower, screen);
}

void display_tower(s_tower *tower, screen *screen, place_t *place)
{
    int o = 0;

    gest_card_display(place, screen);
    anime_tower(tower);
    sfRenderWindow_drawSprite(screen->window, place->tower_1, NULL);
    sfRenderWindow_drawSprite(screen->window, place->tower_2, NULL);
    sfRenderWindow_drawSprite(screen->window, place->tower_3, NULL);
    sfRenderWindow_drawSprite(screen->window, place->tower_4, NULL);
    fill_calc(tower);
    algo_display_tower(tower, screen);
    for (s_tower *cur = tower->next; cur != NULL; cur = cur->next)
        if (cur->statu == 1)
            o += 1;
    if (o == 0)
        ges_event_tower(tower, screen, place);
    gest_mouse_dp(tower, place, screen);
    check_bad_coord(tower);
}

void destroy_tower(s_tower *tower, place_t *place)
{
    s_tower *cur = tower;
    s_tower *next = tower->next;

    sfSprite_destroy(place->bouton_down);
    sfSprite_destroy(place->bouton_up);
    sfSprite_destroy(place->tower_1);
    sfSprite_destroy(place->tower_2);
    sfSprite_destroy(place->tower_3);
    sfSprite_destroy(place->tower_4);
    sfSprite_destroy(place->card_frost);
    sfSprite_destroy(place->card_storm);
    sfSprite_destroy(place->card_poison);
    sfSprite_destroy(place->card_fire);
    sfText_destroy(place->text_t_1);
    sfText_destroy(place->text_t_2);
    sfText_destroy(place->text_t_3);
    sfText_destroy(place->text_t_4);
    sfFont_destroy(place->font);
    while (next != NULL) {
        cur = next;
        next = next->next;
        sfSprite_destroy(cur->tower_sp);
        sfClock_destroy(cur->clock_tower);
        sfCircleShape_destroy(cur->circle);
        free (cur);
    }
    free (tower);
}
