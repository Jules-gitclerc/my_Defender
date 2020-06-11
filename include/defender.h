/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** defender
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my.h"
#include "enemy.h"
#include "map.h"
#include "tower.h"

typedef struct g_struct
{
    enemy *enemy;
    s_map *map;
    chrono *clock;
    vague *vg;
    screen *screen;
    s_tower *tower;
} g_s;

typedef struct score_defender
{
    int score_new;
    char **score_board;
} score;

int menu(screen *weed);
int check_lige(screen *screen, game *gm);
void init_gmae(game *gm);
char **recup_score(void);
void wave_main(g_s *g_s, game *gm, ball *missile);
void render(g_s *g_s, place_t *place, game *gm, ball *misile);
void destroy(g_s *s_g, place_t *place);
void init_1(game *game, vague *vg, place_t *place);
int print_tireh(char *str, int ac);
void init_game(game *gm);

#endif /* !DEFENDER_H_ */
