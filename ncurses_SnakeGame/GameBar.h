#include <ncurses.h>

class GameBar
{
    WINDOW *win;

public:
    GameBar(int y, int x, int by, int bx);
    ~GameBar();
    void NewDesign();
    void Clear();
    void Update();
};