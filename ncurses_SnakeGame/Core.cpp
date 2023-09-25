#include "Core.h"

Core::Core()
{
    getmaxyx(stdscr, sy, sx);
    game = new GameWindow(sy - 3, sx, 3, 0);
    bar = new GameBar(3, sx, 0, 0);
    init();
    while (true)
    {
        update();
    }
}

Core::~Core()
{
    delete game;
    delete bar;
}

void Core::update()
{
    game->Update();
}

void Core::init()
{
    bar->NewDesign();
    game->NewDesign();
    game->StartGame();
}