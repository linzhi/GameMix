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

void snake_init();
void snake_move();
void snake_increase();
void snake_over();
int snake_hit_borders();

#endif
