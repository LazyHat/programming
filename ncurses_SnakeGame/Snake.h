#include <ncurses.h>
#include <exception>
#include "Vector2.h"
#include <list>

class Snake
{
public:
    enum Direction
    {
        None,
        Down,
        Up,
        Left,
        Right,
    };

private:
    WINDOW *win;
    std::list<Vector2> body;
    Direction dir;

public:
    Snake(WINDOW *window, int sy, int sx);
    void Update();
    void SetDirection(Direction direction);
    Direction GetDirection() const;
    void Draw() const;
};

Snake::Direction GetDirFKey(int key);