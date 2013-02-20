#include <stdio.h>
#include "engine.h"
#include "keyinput.h"
#include "snake/snake.h"

extern int snake_game;
extern int tank_game;
extern int pushbox_game;
extern int esc_key;

int main(int argc, char *argv[])
{

    engine_init();
    engine_show_game_menu();

    while (1)
    {
        //waiting for the key
        key_input();

        //snake game start
        if (snake_game)
        {
            engine_show_snake_game_start();
            snake_borders_init();
            snake_fruit_init();
            snake_init();

            while (1)
            {
                snake_move();
                if (esc_key)
                {
                    engine_exit();
                }
            }

            snake_game = 0;
        }
        
        //tank game start
        else if (tank_game)
        {
            tank_game = 0;
        }

        //pushbox game start
        else if (pushbox_game)
        {
            pushbox_game = 0;
        }

        //quit all of the games
        else if (esc_key)
        {
            engine_exit();
        }
    }

    engine_exit();

    return 0;
}
