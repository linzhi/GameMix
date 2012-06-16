/*
 *  File: engine.h
 *
 */

#ifndef ENGINE_H
#define ENGINE_H

struct screen_t
{
    int hei;
    int wid;
    int delay;
};

struct fruit_t
{
    int x_pos;
    int y_pos;
};

void snake_borders_init();
void snake_fruit_init();

void engine_init();
void engine_exit();
void engine_show_game_menu();
void engine_show_snake_game_start();
void engine_show_game_over();

#endif
