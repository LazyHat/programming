#pragma once
#include <SFML/Graphics.hpp>
#include "Definitions.h"

class Item
{
public:
    virtual void draw() = 0;
};

class SquareItem : public Item
{
    sf::RectangleShape body;

    sf::RenderWindow *window;

public:
    SquareItem(sf::RenderWindow *window)
    {
        this->window = window;
        body.setPosition(WINDOW_RES_X / 2, WINDOW_RES_Y / 2);
        body.setFillColor(sf::Color::Yellow);
        body.setOutlineColor(sf::Color::Blue);
        body.setOutlineThickness(-2);
        body.setSize(sf::Vector2f(30, 30));
        body.setOrigin(15, 15);
        body.setRotation(rand());
    }

    void draw() override
    {
        window->draw(body);
    }
};