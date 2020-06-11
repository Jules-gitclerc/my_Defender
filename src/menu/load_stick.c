/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** load_stick.c
*/

#include "menu.h"
#include "enemy.h"

void set_pos_loader(set_loader *loader)
{
    sfVector2f vec_loader_on = {605, 524};
    sfVector2f vec_loader_off = {605, 510};
    sfVector2f vec_stick_loader = {600, 520};

    sfSprite_setPosition(loader->loader_on, vec_loader_on);
    sfSprite_setPosition(loader->loader_off, vec_loader_off);
    sfSprite_setPosition(loader->stick_loader, vec_stick_loader);
}

void init_loader(set_loader *loader)
{
    loader->stick_loader = create_sprite(
        "./ressource/sprite_menu/LoadingBar.png");
    loader->loader_on = create_sprite(
        "./ressource/sprite_menu/LoadingBar.png");
    loader->loader_off = create_sprite(
        "./ressource/sprite_menu/LoadingBar.png");
    cod_i_init_loader(loader);
}

int clock_loader(sfClock *clock, set_loader *loader)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float sec = (float) time.microseconds / 10000000.0;

    if (sec >= 0.002) {
        loader->rect_loader.width += 5;
        sfClock_restart(clock);
    }
    if (loader->rect_loader.width >= 691)
        return (1);
    else
        return (0);
}

int render_loader(set_loader *loader, screen *weed, sfClock *clock)
{
    sfRenderWindow_clear(weed->window, sfBlack);

    if (clock_loader(clock, loader) == 1)
        return (1);
    sfSprite_setTextureRect(loader->loader_on, loader->rect_loader);
    sfRenderWindow_drawSprite(weed->window, loader->stick_loader, NULL);
    sfRenderWindow_drawSprite(weed->window, loader->loader_off, NULL);
    sfRenderWindow_drawSprite(weed->window, loader->loader_on, NULL);
    display_monster_menu(loader, weed);
    anim_monster_menu(loader);
    sfRenderWindow_display(weed->window);
    return (0);
}

int loop_loade(screen *weed, welcome mn)
{
    set_loader loader;
    sfClock *clock = sfClock_create();

    init_loader(&loader);
    create_anim_menu(&loader);
    while (1) {
        while (sfRenderWindow_pollEvent(weed->window, &mn.evt_menu)) {
            if (mn.evt_menu.key.code == sfKeyEscape ||
                mn.evt_menu.type == sfEvtClosed) {
                sfRenderWindow_close(weed->window);
                return (0);
            }
        }
        if (render_loader(&loader, weed, clock) == 1)
            break;
    }
    return (0);
}
