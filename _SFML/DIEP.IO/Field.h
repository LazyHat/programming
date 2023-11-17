#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include "Player.h"
#include "Item.h"

class Field
{

    sf::RenderWindow *window;

    sf::RectangleShape border;

    std::unique_ptr<Player> mainPlayer;

    std::list<std::unique_ptr<Player>> bots;

    std::list<std::unique_ptr<Item>> items;

public:
    Field(sf::RenderWindow *window, sf::Vector2f size);

    void createMainPlayer();

    Player *getMainPlayer();

    void deleteMainPlayer();

    void draw();
    void update(float elapsed);
};

Field::Field(sf::RenderWindow *window, sf::Vector2f size)
{
    this->window = window;
    border.setSize(size);
    border.setFillColor(sf::Color(0x666666FF));
    border.setPosition(0, 0);
    border.setOutlineThickness(-3);
    border.setOutlineColor(sf::Color::Red);
    mainPlayer = std::make_unique<Player>(window, sf::Vector2f(WINDOW_RES_X / 2, WINDOW_RES_Y / 2));
    items.push_back(std::make_unique<SquareItem>(window));
}

void Field::createMainPlayer()
{
    mainPlayer = std::make_unique<Player>(window, sf::Vector2f(WINDOW_RES_X / 2, WINDOW_RES_Y / 2));
}

Player *Field::getMainPlayer()
{
    return mainPlayer.get();
}

void Field::draw()
{
    window->draw(border);
    for (auto it = items.begin(); it != items.end(); it++)
    {
        it->get()->draw();
    }
    mainPlayer->draw();
}

void Field::update(float elapsed)
{
    mainPlayer->update(elapsed);
}