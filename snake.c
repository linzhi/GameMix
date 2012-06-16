/*
 *  FILE: snake.c
 *
 *
 */

#include <stdio.h>
#include <curses.h>
#include "snake.h"

static char SNAKE_BODY_CHAR = 'O';
static char SNAKE_HEAD_CHAR = 'X';

struct snake_t snake;
struct snake_body_t snake_body;

extern void key_input();
extern void engine_show_game_over();
extern void engine_show_game_menu();

extern enum Colors { BLUE_BLACK = 1, YELLOW_BLACK, RED_BLACK,
                     WHITE_BLACK, GREEN_BLACK, GREEN_RED };
extern int key_up;
extern int key_down;
extern int key_left;
extern int key_right;
extern int key_enter;

void snake_init()
{
    attroff(COLOR_PAIR(RED_BLACK));
    attron(COLOR_PAIR(BLUE_BLACK));
    
    int i = 0;
    snake.score = 0;
    snake.speed = 1;
    snake.size = 8;
    snake.body = malloc((snake.size) * sizeof(struct snake_body_t));

    if (snake.body == NULL)
    {
        ;
    }
    
    int m = COLS / 2;
    int n = LINES / 2;

    snake.body[0].x = m;
    snake.body[0].y = n;

    mvaddch(snake.body[0].y, snake.body[0].x, SNAKE_HEAD_CHAR);

    for (i = 1; i < snake.size; i++)
    {
        m++;
        snake.body[i].x = m;
        snake.body[i].y = n;
        mvaddch(snake.body[i].y, snake.body[i].x, SNAKE_BODY_CHAR);
    }

    refresh();
}

void snake_move()
{
    key_input();
    int i, j;

    if (key_up)
    {
        mvaddch(snake.body[snake.size-1].y, 
                snake.body[snake.size-1].x, ' ');

        for (i = (snake.size - 1); i > 0; i--)
        {
            snake.body[i].x = snake.body[i-1].x;
            snake.body[i].y = snake.body[i-1].y;
        }

        snake.body[0].y = snake.body[0].y - snake.speed;

        mvaddch(snake.body[0].y, snake.body[0].x, SNAKE_HEAD_CHAR);

        for (j = 1; j < snake.size; j++)
        {
            mvaddch(snake.body[j].y, snake.body[j].x, 
                    SNAKE_BODY_CHAR);
        }

        if (snake.body[0].y == 0)
        {
            engine_show_game_over();
            sleep(3);
            engine_show_game_menu();
        }

        refresh();
        key_up = 0;
    }

    else if (key_down)
    {
        mvaddch(snake.body[snake.size-1].y, 
                snake.body[snake.size-1].x, ' ');

        for (i = (snake.size - 1); i > 0; i--)
        {
            snake.body[i].x = snake.body[i-1].x;
            snake.body[i].y = snake.body[i-1].y;
        }

        snake.body[0].y = snake.body[0].y + snake.speed;

        mvaddch(snake.body[0].y, snake.body[0].x, SNAKE_HEAD_CHAR);

        for (j = 1; j < snake.size; j++)
        {
            mvaddch(snake.body[j].y, snake.body[j].x, 
                    SNAKE_BODY_CHAR);
        }

        if (snake.body[0].y == LINES - 1)
        {
            engine_show_game_over();
            sleep(3);
            engine_show_game_menu();
        }

        refresh();
        key_down = 0;
    }

    else if (key_left)
    {
        mvaddch(snake.body[snake.size-1].y, 
                snake.body[snake.size-1].x, ' ');

        for (i = (snake.size - 1); i > 0; i--)
        {
            snake.body[i].x = snake.body[i-1].x;
            snake.body[i].y = snake.body[i-1].y;
        }

        snake.body[0].x = snake.body[0].x - snake.speed;

        mvaddch(snake.body[0].y, snake.body[0].x, SNAKE_HEAD_CHAR);

        for (j = 1; j < snake.size; j++)
        {
            mvaddch(snake.body[j].y, snake.body[j].x,
                    SNAKE_BODY_CHAR);
        }
        
        if (snake.body[0].x == 0)
        {
            engine_show_game_over();
            sleep(3);
            engine_show_game_menu();
        }

        refresh();
        key_left = 0;
    }

    else if (key_right)
    {
        mvaddch(snake.body[snake.size-1].y, 
                snake.body[snake.size-1].x, ' ');

        for (i = (snake.size - 1); i > 0; i--)
        {
            snake.body[i].x = snake.body[i-1].x;
            snake.body[i].y = snake.body[i-1].y;
        }

        snake.body[0].x = snake.body[0].x + snake.speed;

        mvaddch(snake.body[0].y, snake.body[0].x, SNAKE_HEAD_CHAR);

        for (j = 1; j < snake.size; j++)
        {
            mvaddch(snake.body[j].y, snake.body[j].x, 
                    SNAKE_BODY_CHAR);
        }
        
        if (snake.body[0].x == COLS - 1)
        {
            engine_show_game_over();
            sleep(3);
            engine_show_game_menu();
        }

        refresh();
        key_right = 0;
    }

}

void snake_increase()
{

}

void snake_over()
{
    
}

int snake_hit_borders()
{


}
