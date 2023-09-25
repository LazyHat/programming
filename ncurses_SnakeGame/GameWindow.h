#include <ncurses.h>
#include <cstdlib>
#include "Snake.h"

class GameWindow
{
    WINDOW *win;
    Snake *snake = nullptr;
    bool gameState = false;

public:
    GameWindow(int y, int x, int by, int bx);
    ~GameWindow();
    void NewDesign();
    void Clear();
    void Update();
    void StartGame();
};