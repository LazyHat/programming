#include "Snake.h"

Snake::Snake(WINDOW *window, int sy, int sx)
{
    win = window;
    body.push_front(Vector2(sy, sx));
    body.push_front(Vector2(sy, sx + 1));
    dir = None;
}

void Snake::SetDirection(Direction direction) { dir = direction; }

Snake::Direction Snake::GetDirection() const { return dir; }

void Snake::Update()
{
    if (dir == Direction::None)
        throw std::exception();
    int y = (--body.end())->y, x = (--body.end())->x;
    mvwdelch(win, (--body.end())->y, (--body.end())->y);
    wrefresh(win);
    switch (dir)
    {
    case Down:
        body.push_front(Vector2(body.begin()->y + 1, body.begin()->x));
        break;
    case Up:
        body.push_front(Vector2(body.begin()->y - 1, body.begin()->x));
        break;
    case Left:
        body.push_front(Vector2(body.begin()->y, body.begin()->x - 1));
        break;
    case Right:
        body.push_front(Vector2(body.begin()->y, body.begin()->x + 1));
        break;
    default:
        break;
    }
    mvwaddch(win, body.begin()->y, body.begin()->x, '#');
    wrefresh(win);
    body.pop_back();
}

void Snake::Draw() const
{
    // for (auto point : body)
    // {
    //     mvwaddch(win, point.y, point.x, ' ');
    // }
    // wrefresh(win);
}

Snake::Direction GetDirFKey(int key)
{
    switch (key)
    {
    case KEY_DOWN:
        return Snake::Direction::Down;
    case KEY_UP:
        return Snake::Direction::Up;
    case KEY_LEFT:
        return Snake::Direction::Left;
    case KEY_RIGHT:
        return Snake::Direction::Right;

    default:
        return Snake::Direction::None;
        break;
    }
}