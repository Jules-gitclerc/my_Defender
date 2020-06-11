/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** destroy
*/

#include "defender.h"
#include "map.h"

void destroy(g_s *s_g, place_t *place)
{
    destroy_clock_enemy(s_g->clock);
    sfSprite_destroy(s_g->map->map);
    sfSprite_destroy(s_g->vg->wave_bouton);
    destroy_tower(s_g->tower, place);
    destroy_portal(s_g->map);
    destroy_heart(s_g->map);
    destroy_coin(s_g->map);
    sfRenderWindow_destroy(s_g->screen->window);
}

void render(g_s *g_s, place_t *place, game *gm, ball *misile)
{
    sfRenderWindow_clear(g_s->screen->window, sfBlack);
    display_map(g_s->map, g_s->screen);
    display_coin(g_s->screen, g_s->map);
    display_portal(g_s->map, g_s->screen);
    display_heart(g_s->map, g_s->screen, gm);
    wave_main(g_s, gm, misile);
    display_tower(g_s->tower, g_s->screen, place);
    display_cost_tower(place, g_s->screen);
    display_ball(g_s->screen, misile);
    sfRenderWindow_display(g_s->screen->window);
}

void init_1(game *game, vague *vg, place_t *place)
{
    init_game(game);
    init_set_vague(vg);
    create_tower(place);
    create_cost_tower(place);
}