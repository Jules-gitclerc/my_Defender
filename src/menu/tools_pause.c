/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tools_pause
*/

#include "pause.h"
#include "defender.h"

void set_pos_text(s_pause *ps)
{
    sfVector2f vec_text_play = {885, 390};
    sfVector2f vec_text_option = {850, 590};
    sfVector2f vec_text_credit = {850, 790};

    sfText_setPosition(ps->text_resume, vec_text_play);
    sfText_setPosition(ps->text_option, vec_text_option);
    sfText_setPosition(ps->text_quit, vec_text_credit);
}

void set_pos_pause(s_pause *ps)
{
    sfVector2f vec_back = {520, 80};
    sfVector2f vec_bouton_play = {800, 350};
    sfVector2f vec_bouton_option = {800, 550};
    sfVector2f vec_bouton_credit = {800, 750};

    sfSprite_setTextureRect(ps->sprite_bouton_resume, ps->rect_bouton);
    sfSprite_setTextureRect(ps->sprite_bouton_option, ps->rect_bouton);
    sfSprite_setTextureRect(ps->sprite_bouton_quit, ps->rect_bouton);
    sfSprite_setPosition(ps->background_pause, vec_back);
    sfSprite_setPosition(ps->sprite_bouton_resume, vec_bouton_play);
    sfSprite_setPosition(ps->sprite_bouton_option, vec_bouton_option);
    sfSprite_setPosition(ps->sprite_bouton_quit, vec_bouton_credit);
    set_pos_text(ps);
}

void create_text_pause(s_pause *ps)
{
    sfFont *font = sfFont_createFromFile("./ressource/American Captain.ttf");

    ps->text_resume = sfText_create();
    ps->text_option = sfText_create();
    ps->text_quit = sfText_create();
    sfText_setString(ps->text_resume, "RESUME");
    sfText_setString(ps->text_option, "OPTIONS");
    sfText_setString(ps->text_quit, "QUIT");
    sfText_setFont(ps->text_resume, font);
    sfText_setFont(ps->text_option, font);
    sfText_setFont(ps->text_quit, font);
    sfText_setCharacterSize(ps->text_resume, 80);
    sfText_setCharacterSize(ps->text_option, 80);
    sfText_setCharacterSize(ps->text_quit, 80);
}

void render_pause_bis(s_pause *ps, screen *screen)
{
    sfRenderWindow_drawSprite(screen->window, ps->background_pause, NULL);
    sfRenderWindow_drawSprite(screen->window, ps->sprite_bouton_option, NULL);
    sfRenderWindow_drawSprite(screen->window, ps->sprite_bouton_quit, NULL);
    sfRenderWindow_drawSprite(screen->window, ps->sprite_bouton_resume, NULL);
    sfRenderWindow_drawText(screen->window, ps->text_option, NULL);
    sfRenderWindow_drawText(screen->window, ps->text_quit, NULL);
    sfRenderWindow_drawText(screen->window, ps->text_resume, NULL);
    sfRenderWindow_display(screen->window);
}

void destroy_pause(s_pause *ps)
{
    sfSprite_destroy(ps->background_pause);
    sfSprite_destroy(ps->sprite_bouton_option);
    sfSprite_destroy(ps->sprite_bouton_quit);
    sfSprite_destroy(ps->sprite_bouton_resume);
    sfText_destroy(ps->text_option);
    sfText_destroy(ps->text_quit);
    sfText_destroy(ps->text_resume);
}