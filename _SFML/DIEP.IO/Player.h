#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>
#include <iostream>
#include "Direction.h"

class Player
{
private:
    sf::RenderWindow *window;
    sf::CircleShape body;
    sf::RectangleShape gun;

    float speed = 500.f;

    sf::Vector2i mousePos;

public:
    Player(sf::RenderWindow *window, sf::Vector2f pos, float r = 40.f)
    {
        this->window = window;
        body.setRadius(r);
        body.setOrigin(r, r);
        body.setPosition(pos);
        body.setFillColor(sf::Color::Cyan);
        gun.setFillColor(sf::Color(0xCC7777FF));
        gun.setOutlineColor(sf::Color(0xAAAAAAFF));
        gun.setOutlineThickness(-1);
        gun.setSize(sf::Vector2f(r / 2, r / 3));
        gun.setRotation(0.f);
        gun.setPosition(pos.x, pos.y - r);
        gun.setOrigin(r / 4, r / 6);
    }

    void draw()
    {
        window->draw(body);
        window->draw(gun);
    }

    void update(float elapsed)
    {
        sf::Vector2f bodyPosition = body.getPosition();
        sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
        float bodyRadius = body.getRadius();
        float rangeX = mousePosition.x - bodyPosition.x;
        float rangeY = mousePosition.y - bodyPosition.y;
        float rangeDiagonal = sqrt(rangeX * rangeX + rangeY * rangeY);
        float cos = rangeX / rangeDiagonal;
        float sin = rangeY / rangeDiagonal;
        float angle = acosf(cos) * (sin / fabs(sin)) * 180 / M_PI;
        gun.setPosition(bodyPosition.x + bodyRadius * cos, bodyPosition.y + bodyRadius * sin);
        gun.setRotation(angle);
    }

    void move(Direction direction, const float elapsed)
    {
        float speedt = elapsed * speed;
        float speedx = 0;

        if (direction.contains(Direction::Left))
            speedx = -speedt;
        else if (direction.contains(Direction::Right))
            speedx = speedt;

        float speedy = 0;

        if (direction.contains(Direction::Up))
            speedy = -speedt;
        else if (direction.contains(Direction::Down))
            speedy = speedt;

        body.move(speedx, speedy);
        gun.move(speedx, speedy);
    }
};