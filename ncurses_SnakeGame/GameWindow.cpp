#include "GameWindow.h"

GameWindow::GameWindow(int y, int x, int by, int bx)
{
    win = newwin(y, x, by, bx);
    refresh();
}

GameWindow::~GameWindow()
{
    delwin(win);
}

void GameWindow::NewDesign()
{
    Clear();
    wborder(win, 0, 0, 0, 0, ACS_VLINE, ACS_VLINE, 0, 0);
    wrefresh(win);
}

void GameWindow::Clear()
{
    werase(win);
    wrefresh(win);
}

void GameWindow::Update()
{
    if (gameState)
    {
        keypad(win, true);
        halfdelay(10);
        do
        {
            Snake::Direction dir;
            dir = GetDirFKey(wgetch(win));
            if (dir != Snake::Direction::None)
                snake->SetDirection(dir);
        } while (snake->GetDirection() == Snake::Direction::None);
        nocbreak();
        keypad(win, false);
        snake->Draw();
        snake->Update();
    }
}

void GameWindow::StartGame()
{
    snake = new Snake(
        win,
        1 + (0 % (win->_maxy - 1)),
        1 + (7 % (win->_maxx - 1)));
    gameState = true;
}