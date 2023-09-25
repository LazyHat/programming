#pragma once
#include <SFML/Graphics.hpp>
#include "DrawShape.h"
#include "Line.h"
#include <vector>

class Core
{
    sf::RenderWindow *window;
    std::vector<std::unique_ptr<DrawShape>> shapes;

    void Update()
    {
    }
    void Draw()
    {
        window->clear();
        for (auto &s : shapes)
        {
            s.get()->Draw(window);
        }
        window->display();
    }

public:
    Core() : Core(1000, 600) {}
    Core(int w, int h)
    {
        window = new sf::RenderWindow(sf::VideoMode(w, h), "Billiard");
        Begin();
    }
    ~Core()
    {
        delete window;
        window = nullptr;
    }
    void Begin()
    {
        shapes.push_back(std::make_unique<Line>(sf::Vector2f(200, 100), 100, M_PI / 3, 2));
        while (window->isOpen())
        {
            sf::Event e;
            while (window->pollEvent(e))
            {
                if (e.type == sf::Event::Closed)
                {
                    window->close();
                }
            }
            Update();
            Draw();
        }
    }
};