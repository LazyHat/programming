#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include "AssetManager.h"
#include "Field.h"
#include "Player.h"

class Engine
{
    AssetManager assetManager;
    std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WINDOW_RES_X, WINDOW_RES_Y), GAME_NAME);

    sf::Font main_font = AssetManager::GetFont(FONT_COMIC_SANS_MS);

    std::unique_ptr<Field> field = std::make_unique<Field>(window.get(), sf::Vector2f(WINDOW_RES_X, WINDOW_RES_Y));

    void input(sf::Time const &dt);
    void update(sf::Time const &dt);
    void draw();

public:
    Engine();

    void run();
};

Engine::Engine()
{
}

void Engine::run()
{
    sf::Clock clock;

    while (window->isOpen())
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*(window.get()));
        sf::Vector2f mousePosCoords = window->mapPixelToCoords(mousePos);
        sf::Time dt = clock.restart();
        input(dt);
        update(dt);
        draw();
    }
}

void Engine::input(sf::Time const &dt)
{
    float elapsed = dt.asMicroseconds() / 1000000.f;
    sf::Event event_play;
    Direction playerDirection;
    while (window->pollEvent(event_play))
    {
        switch (event_play.type)
        {
        case sf::Event::Closed:
        {
            window->close();
            break;
        }

        default:
        {
            break;
        }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        playerDirection |= Direction::Up;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        playerDirection |= Direction::Down;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        playerDirection |= Direction::Left;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        playerDirection |= Direction::Right;
    if (playerDirection.isNotNone())
        field->getMainPlayer()->move(playerDirection, elapsed);
}

void Engine::update(sf::Time const &dt)
{
    float elapsed = dt.asMicroseconds() / 1000000.f;
    field->update(elapsed);
}

void Engine::draw()
{
    window->clear();
    field->draw();
    window->display();
}