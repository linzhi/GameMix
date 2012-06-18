/*
 *  FILE: snake.h
 */

#ifndef SNAKE_H
#define SNAKE_H

struct snake_body_t
{
    int x;
    int y;
};

struct snake_t
{
    int speed;
    int size;
    int direction;
    int score;
    struct snake_body_t *body;
};

extern struct snake_t snake;

void snake_init();
void snake_move_init();
void snake_move();
void snake_increase();
int snake_eat_over();

#endif
