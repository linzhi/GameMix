/*
 *  FILE: keyinput.c
 *
 */

#include <stdio.h>
#include <curses.h>
#include "keyinput.h"

#define KEY_ESC 27
#define KEY_SPACE 32

int snake_game;
int tank_game;
int pushbox_game;
int esc_key;
int key_enter;
int key_up;
int key_down;
int key_left;
int key_right;

extern void engine_exit();

void key_input()
{
    int input = getch();

    switch(input)
    {
        case ERR:
            break;

        // snake
        case '1':
            snake_game = 1;
            break;

        // press the space key to start snake game
        case KEY_SPACE:
            break;

        // tank
        case '2':
            tank_game = 1;
            break;

        // pushbox
        case '3':
            pushbox_game = 1;
            break;

        case KEY_UP:
            key_up = 1;
            break;

        case KEY_DOWN:
            key_down = 1;
            break;

        case KEY_LEFT:
            key_left = 1;
            break;

        case KEY_RIGHT:
            key_right = 1;
            break;

        case KEY_BACKSPACE:
            break;

        case KEY_ENTER:
            key_enter = 1;

        // quit to the terminal
        case KEY_ESC:
            esc_key = 1;
            break;

        default:
            break;
    }
    
}
