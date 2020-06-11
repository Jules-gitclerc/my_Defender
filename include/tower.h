/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tower
*/

#ifndef TOWER_H_
#define TOWER_H_

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Audio.h>
#include "map.h"
#include "enemy.h"

typedef struct tower s_tower;
struct tower
{
    sfSprite *tower_sp;
    int t_tower;
    int statu;
    int dammage;
    int calc;
    float crital;
    float attack_seepd;
    sfClock *clock_tower;
    sfIntRect rect_tower;
    int selct;
    int i;
    s_tower *next;
    s_tower *prev;
    sfCircleShape *circle;
};

typedef struct projectile ball;
struct projectile
{
    sfSprite *fire;
    sfClock *clock_moove;
    sfClock *bonus;
    sfVector2f vec_initial;
    sfVector2f vec_end;
    ball *next;
};

typedef struct place_tower
{
    sfSprite *tower_1;
    sfSprite *tower_2;
    sfSprite *tower_3;
    sfSprite *tower_4;
    sfSprite *card_storm;
    sfSprite *card_fire;
    sfSprite *card_poison;
    sfSprite *card_frost;
    sfText *text_t_1;
    sfText *text_t_2;
    sfText *text_t_3;
    sfText *text_t_4;
    sfFont *font;
    sfSprite *bouton_up;
    sfSprite *bouton_down;
} place_t;

void set_circle(s_tower *cur);
void create_tower(place_t *place);
void change_color_bad_pos(s_tower *tower);
void display_tower(s_tower *tower, screen *screen, place_t *place);
void ges_fir_enemy(enemy *np, s_tower *tower);
void destroy_tower(s_tower *tower, place_t *place);
void ges_fire_enemy(enemy *np, s_tower *tower);
void add_node(int t_tower, char *img, s_tower *tower);
void management_tower(s_tower *tower, sfVector2f mouse, int i);
void create_head(s_tower *tower);
void create_cost_tower(place_t *cost);
void gest_card_display(place_t *place, screen *screen);
void display_cost_tower(place_t *cost, screen *screen);
void destroy_cost_tower(place_t *cost);
void anime_tower(s_tower *tower);
void init_head_missile(ball *missile);
void fill_calc(s_tower *tower);
void init_card_sprite(place_t *place);
void algo_display_tower(s_tower *tower, screen *screen);
int fire_tower(s_tower *tower, enemy *np, ball *misile, screen *screen);
void destroy_node_ball(ball *missile, int i);
int display_ball(screen *screen, ball *missile);
void add_node_missile(ball *missile, sfSprite *tower, sfSprite *enemy);
int change_spe(s_tower *cur, int nb);
void destroy_node_ball(ball *missile, int i);
void remake_selct(s_tower *tower);
void check_bad_coord(s_tower *tower);
void delete_node(s_tower *tower, int i);
void ges_event_tower(s_tower *tower, screen *screen, place_t *place);

#endif /* !TOWER_H_ */
