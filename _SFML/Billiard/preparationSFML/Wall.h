#pragma once
#include <SFML/Graphics.hpp>
#include "Line.h"

class Wall
{
    sf::ConvexShape pol[2];
    sf::RectangleShape rect;

public:
    Wall(Line)
    {
    }
    void Draw(sf::RenderWindow *win)
    {
        win->draw(pol[0]);
        win->draw(pol[1]);
        win->draw(rect);
    }
};