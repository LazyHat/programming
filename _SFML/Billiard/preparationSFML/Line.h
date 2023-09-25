#pragma once
#include "DrawShape.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class Line : public DrawShape
{
    sf::RectangleShape *rect;

public:
    Line(const sf::Vector2f position, const float length, const float angleR, const float thickness = 2)
    {
        rect = new sf::RectangleShape();
        rect->setOrigin(0, thickness / 2);
        rect->setPosition(position);
        rect->rotate(angleR * 180 / M_PI);
    }
    ~Line() { delete rect; }
    void Draw(sf::RenderWindow *win) override
    {
        win->draw(*rect);
    }
};