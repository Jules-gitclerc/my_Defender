/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** main
*/

#include "defender.h"
#include "map.h"
#include "tower.h"
#include "pause.h"

void init_group_struct(g_s *s_g, chrono *clock, screen *screen)
{
    init_clock_enemy(clock);
    s_g->clock = clock;
    s_g->screen = screen;
}

void init_group_struct2(g_s *s_g, s_map *map, vague *vg, s_tower *tower)
{
    create_map(map);
    create_coin(map);
    create_heart(map);
    create_portal(map);
    create_head(tower);
    s_g->map = map;
    s_g->vg = vg;
    s_g->tower = tower;
}

int get_evt(screen *weed, g_s *s_g, place_t *place)
{
    while (sfRenderWindow_pollEvent(weed->window, &weed->evt)) {
        if (weed->evt.key.code == sfKeyEscape ||
            weed->evt.type == sfEvtClosed)
            sfRenderWindow_close(weed->window);
        if (weed->evt.type == sfEvtKeyPressed
            && weed->evt.key.code == sfKeyP)
            if (pause(weed, s_g, place) == 2)
                return (1);
    }
    return (0);
}

int loop(screen *weed, vague *vg, game *gm, s_map *map)
{
    place_t place;
    chrono tm;
    ball *missile = malloc(sizeof(ball));
    s_tower *tower = malloc(sizeof(s_tower));
    g_s s_g;
    int i = 0;

    init_1(gm, vg, &place);
    init_group_struct(&s_g, &tm, weed);
    init_group_struct2(&s_g, map, vg, tower);
    init_head_missile(missile);
    while (sfRenderWindow_isOpen(weed->window)) {
        i = get_evt(weed, &s_g, &place);
        if (i == 1)
            break;
        render(&s_g, &place, gm, missile);
        anim_portal(map);
        if (check_lige(weed, gm) == 1) {
            my_printf("GAME OVER\n");
            break;
        }
    }
    destroy(&s_g, &place);
}

int main(int ac, char **av)
{
    sfVideoMode mode = {1920, 1080, 32};
    screen weed;
    vague vg;
    game gm;
    s_map map;

    if (print_tireh(av[1], ac) == 1)
        return (0);
    weed.nb = 20;
    (void)av;
    if (ac != 1)
        return (84);
    weed.window = sfRenderWindow_create(mode, "MY_DEFENDER", sfResize
                                                | sfClose, NULL);
    if (menu(&weed) == 2) {
        sfRenderWindow_destroy(weed.window);
        return (1);
    }
    loop(&weed, &vg, &gm, &map);
    return (0);
}
