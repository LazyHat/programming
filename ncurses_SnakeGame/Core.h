#include "GameWindow.h"
#include "GameBar.h"

class Core
{
    GameWindow *game;
    GameBar *bar;
    int sx, sy;
    void update();
    void init();

public:
    Core();
    ~Core();
};