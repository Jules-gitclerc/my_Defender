/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tools_tower
*/

#include "my.h"
#include "enemy.h"
#include "map.h"
#include "tower.h"

void init_card_sprite(place_t *place)
{
    sfVector2f vec = {0, 680};

    place->card_fire = create_sprite(
        "./ressource/sprite_tower/des_card_fire.png");
    place->card_frost = create_sprite(
        "./ressource/sprite_tower/des_card_ice.png");
    place->card_poison = create_sprite(
        "./ressource/sprite_tower/des_card_poison.png");
    place->card_storm = create_sprite(
        "./ressource/sprite_tower/des_card_storm.png");
    sfSprite_setPosition(place->card_frost, vec);
    sfSprite_setPosition(place->card_poison, vec);
    sfSprite_setPosition(place->card_fire, vec);
    sfSprite_setPosition(place->card_storm, vec);
}

void gest_card_display(place_t *place, screen *screen)
{
    sfVector2f vec_sprite = sfSprite_getPosition(place->tower_1);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(screen->window);
    sfVector2f vec = {mouse.x, mouse.y};

    if (vec.x >= vec_sprite.x && vec.x <= vec_sprite.x + 200 &&
    vec.y >= vec_sprite.y && vec.y <= vec_sprite.y + 200)
        sfRenderWindow_drawSprite(screen->window, place->card_storm, NULL);
    vec_sprite = sfSprite_getPosition(place->tower_2);
    if (vec.x >= vec_sprite.x && vec.x <= vec_sprite.x + 200 &&
    vec.y >= vec_sprite.y && vec.y <= vec_sprite.y + 200)
        sfRenderWindow_drawSprite(screen->window, place->card_frost, NULL);
    vec_sprite = sfSprite_getPosition(place->tower_3);
    if (vec.x >= vec_sprite.x && vec.x <= vec_sprite.x + 200 &&
    vec.y >= vec_sprite.y && vec.y <= vec_sprite.y + 200)
        sfRenderWindow_drawSprite(screen->window, place->card_poison, NULL);
    vec_sprite = sfSprite_getPosition(place->tower_4);
    if (vec.x >= vec_sprite.x && vec.x <= vec_sprite.x + 200 &&
    vec.y >= vec_sprite.y && vec.y <= vec_sprite.y + 200)
        sfRenderWindow_drawSprite(screen->window, place->card_fire, NULL);
}

void create_head(s_tower *tower)
{
    tower->prev = NULL;
    tower->next = NULL;
    tower->statu = 0;
    tower->t_tower = 0;
    tower->attack_seepd = 0;
    tower->dammage = 0;
    tower->crital = 0;
    tower->i = 0;
    tower->tower_sp = NULL;
    tower->clock_tower = NULL;
    tower->selct = 0;
}

void add_node(int t_tower, char *img, s_tower *tower)
{
    s_tower *cur = tower;
    sfIntRect rect = {0, 0, 140, 253};

    for (; cur->next != NULL; cur = cur->next);
    cur->next = malloc(sizeof(s_tower));
    cur->next->prev = cur;
    cur = cur->next;
    cur->next = NULL;
    cur->statu = 1;
    cur->selct = 0;
    cur->i = 0;
    cur->clock_tower = sfClock_create();
    cur->rect_tower = rect;
    cur->tower_sp = create_sprite(img);
    cur->t_tower = t_tower;
    change_spe(cur, t_tower);
    cur->circle = sfCircleShape_create();
    set_circle(cur);
    sfSprite_setTextureRect(cur->tower_sp, cur->rect_tower);
}

void delete_node(s_tower *tower, int i)
{
    s_tower *target = tower;
    s_tower *cur = tower;

    int o = 0;
    for (; o < i - 1; o++) {
        target = target->next;
        cur = cur->next;
    }
    target = target->next;
    cur->next = cur->next->next;
    sfSprite_destroy(target->tower_sp);
    sfClock_destroy(target->clock_tower);
    sfCircleShape_destroy(target->circle);
    free (target);
}
