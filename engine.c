/*
 *  FILE: engine.c
 */

#include <stdio.h>
#include <curses.h>
#include "engine.h"
#include "snake/snake.h"

enum Colors { BLUE_BLACK = 1, YELLOW_BLACK, RED_BLACK, 
              WHITE_BLACK, GREEN_BLACK, GREEN_RED };

void engine_init()
{
    initscr();

    if (has_colors() == false)
    {
        engine_exit();
        printf("%s", "Your terminal does not support colors.\n" );
    }

    start_color();

    init_pair(BLUE_BLACK, COLOR_BLUE, COLOR_BLACK);
    init_pair(RED_BLACK, COLOR_RED, COLOR_BLACK);
    init_pair(WHITE_BLACK, COLOR_WHITE, COLOR_BLACK);
    init_pair(GREEN_BLACK, COLOR_GREEN, COLOR_BLACK);
    init_pair(GREEN_RED, COLOR_GREEN, COLOR_RED);
    init_pair(YELLOW_BLACK, COLOR_YELLOW, COLOR_BLACK);

    raw();

    curs_set (0);
    //to use key
    keypad(stdscr, true);

    noecho();
    //refurbish the display
    refresh();
}

void engine_exit()
{
    clear();
    refresh();
    endwin();
}

void engine_show_game_menu()
{
    clear();

    attron(COLOR_PAIR(GREEN_BLACK));
    
    box(stdscr, ACS_VLINE, ACS_HLINE);
    
    mvprintw(3, 21,  " _______  _______  ________  _______ ");
    mvprintw(4, 21,  "|       ||   _   ||        ||       |");
    mvprintw(5, 21,  "|   ____||  |_|  ||  _  _  ||   ____|");
    mvprintw(6, 21,  "|  | ___ |       || | || | ||  |____ ");
    mvprintw(7, 21,  "|  ||_  ||   _   || | || | ||   ____|");
    mvprintw(8, 21,  "|  |__| ||  | |  || | || | ||  |____ ");
    mvprintw(9, 21,  "|_______||__| |__||_| || |_||_______|");
    mvprintw(10, 21, "                                     ");
    mvprintw(11, 21, "|        Welcom to the GameMix      |");
    mvprintw(12, 21, "|                                   |");
    mvprintw(13, 21, "|                                   |");
    mvprintw(14, 21, "|              1 Snake              |");
    mvprintw(15, 21, "|              2 Tank               |");
    mvprintw(16, 21, "|              3 PushBox            |");
    mvprintw(17, 21, "|___________________________________|");
    
    refresh();
}

void engine_show_game_over()
{
    clear();

    attroff(A_NORMAL);
    attron(COLOR_PAIR(RED_BLACK));

    box(stdscr, ACS_VLINE, ACS_HLINE);

    mvprintw(2, 21,  " _______  _______  ________  _______ ");
    mvprintw(3, 21,  "|       ||   _   ||        ||       |");
    mvprintw(4, 21,  "|   ____||  |_|  ||  _  _  ||   ____|");
    mvprintw(5, 21,  "|  | ___ |       || | || | ||  |____ ");
    mvprintw(6, 21,  "|  ||_  ||   _   || | || | ||   ____|");
    mvprintw(7, 21,  "|  |__| ||  | |  || | || | ||  |____ ");
    mvprintw(8, 21,  "|_______||__| |__||_| || |_||_______|");
    mvprintw(9, 21,  " _______  __   __  ________  _______ ");
    mvprintw(10, 21, "|       ||  | |  ||        ||  ___  |");
    mvprintw(11, 21, "|   _   ||  |_|  ||     ___|| |___| |");
    mvprintw(12, 21, "|  | |  ||       ||    |___ |  ___  |");
    mvprintw(13, 21, "|  |_|  | |     | |     ___|| |   | |");
    mvprintw(14, 21, "|       |  |   |  |    |___ | |   | |");
    mvprintw(15, 21, "|_______|   |_|   |________||_|   |_|");
    mvprintw(16, 21, " ___________________________________ ");
    mvprintw(17, 21, "|                                   |");
    mvprintw(18, 21, "|      Please waiting to retry      |");
    mvprintw(19, 21, "|      Your score:         %d       |", snake.score);
    mvprintw(20, 21, "|___________________________________|");
    
    refresh();
}

void engine_show_snake_game_start()
{
    int count = 6;

    clear();
    
    attroff(COLOR_PAIR(GREEN_BLACK));

    while (count--)
    {
        attron(COLOR_PAIR(YELLOW_BLACK));
        
        box(stdscr, ACS_VLINE, ACS_HLINE);
        
        mvprintw(2, 13,  " ________   _        _       _       _         _______ ");
        mvprintw(3, 13,  "|  ______| | ||     | |     | |     | |    _  |  _____|");
        mvprintw(4, 13,  "| |        | |||    | |    || ||    | |   | | | |      ");
        mvprintw(5, 13,  "| |______  | | ||   | |   ||   ||   | |  _| | | |_____ ");
        mvprintw(6, 13,  "|______  | | |  ||  | |  ||_____||  | |_| __| |  _____|");
        mvprintw(7, 13,  "       | | | |   || | | |_________| |  _  __  | |      ");
        mvprintw(8, 13,  " ______| | | |    ||| | ||       || | | |_  | | |_____ ");
        mvprintw(9, 13,  "|________| |_|     ||_| ||       || |_|   |_| |_______|");
        mvprintw(10, 13, "                                                       ");
        mvprintw(11, 13, "                                                       ");
        mvprintw(12, 13, "                                                       ");
        mvprintw(13, 13, "                 Game Loading... %d                    ", count);
        
        refresh();
        sleep(1);
    }
}
