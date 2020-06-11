/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** enemy
*/

#ifndef ENEMY_H_
#define ENEMY_H_

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "time.h"
#include <math.h>

typedef struct sprite_enemy enemy;
struct sprite_enemy {
    sfSprite* sprite_enemy;
    sfSprite* sprite_attack_enemy;
    sfIntRect rect_enemy;
    sfIntRect rect_life_bar;
    sfSprite* life_sprite;
    sfClock* t_fire;
    sfClock* clock_rect;
    int is;
    int p_life;
    int dead;
    int i;
    enemy* next;
};

typedef struct borad_game {
    int coin;
    int life;
} game;

typedef struct game_over {
    sfText *game_over;
} over;

/*----------vague-----------------*/
typedef struct vague_enemy {
    int nb_vague;
    sfSprite *wave_bouton;
    sfText *wave_text;
    sfIntRect rect_b_wave;
    int spawn_enemy;
    int rand;
} vague;

void check_vague_nb(vague *vg, enemy *np);
void init_set_vague(vague* vg);
void create_vague(vague *vg, enemy *np);

/*----------tools-----------------*/
sfSprite* create_sprite(char *image);
void set_bar_file(enemy *cur);
int check_wave_enemy(enemy *np);
void delete_node_enemy(enemy *np, int i);
sfIntRect create_rect_enemy(int nb);
void init_enemy(enemy *np, int nb_enemy);

/*----------clock-----------------*/
typedef struct clock_enemy {
    sfClock* clock_spawn;
} chrono;

int clock_sapwn_enemy(chrono *tm, int rand);
void init_clock_enemy(chrono *tm);
sfIntRect clock_rect_enemy2(enemy *cur, sfIntRect rect_enemy, int nb);
sfIntRect clock_rect_enemy(enemy *cur, sfIntRect rect_enemy, int nb);

/*----------ia--------------------*/
void moove_enemy(enemy *cur, game *gm, int o, enemy *np);
/*----------display---------------*/
void display_enemy(enemy *np, chrono *tm, sfRenderWindow* window,
                    vague *vg, game *gm);

/*----------destroy---------------*/
void destroy_enemy(enemy *np);
void destroy_clock_enemy(chrono *tm);

#endif /* !ENEMY_H_ */
