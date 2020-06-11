/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** pause
*/

#ifndef PAUSE_H_
#define PAUSE_H_

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Audio.h>
#include "defender.h"
#include "map.h"

typedef struct pause
{
    sfSprite *background_pause;
    sfSprite *sprite_bouton_resume;
    sfSprite *sprite_bouton_option;
    sfSprite *sprite_bouton_quit;
    sfIntRect rect_bouton;
    sfText *text_resume;
    sfText *text_option;
    sfText *text_quit;
    sfEvent evt;
} s_pause;

void create_text_pause(s_pause *pause);
void destroy_pause(s_pause *ps);
void set_pos_pause(s_pause *ps);
int pause(screen *weed, g_s *g_s, place_t *place);
void render_pause_bis(s_pause *ps, screen *screen);

#endif /* !PAUSE_H_ */
