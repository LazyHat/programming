#include <ncurses.h>
#include <ctime>
#include "Core.h"

int main()
{
    srand(time(NULL));
    initscr();
    curs_set(0);
    Core snakeGame;
    endwin();
}