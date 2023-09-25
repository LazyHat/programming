#include "GameBar.h"

GameBar::GameBar(int y, int x, int by, int bx)
{
    win = newwin(y, x, by, bx);
    refresh();
}

GameBar::~GameBar()
{
    delwin(win);
}

void GameBar::NewDesign()
{
    wborder(win, 0, 0, 0, ' ', 0, 0, ACS_VLINE, ACS_VLINE);
    wrefresh(win);
}

void GameBar::Clear()
{
    werase(win);
    wrefresh(win);
}

void Update()
{
}