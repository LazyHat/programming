#include <SFML/System.hpp>
#include "Button.h"
#include <X11/Xlib.h>
#include <atomic>
#include <future>
#include <thread>

void Func(sf::RenderWindow *win2)
{
    win2 = new sf::RenderWindow();
    win2->create(sf::VideoMode(800, 600), "second");
    while (win2->isOpen())
    {
        sf::Event e;
        while (win2->pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                win2->close();
                delete win2;
                return;
            }
        }
        win2->clear();
        win2->display();
    }
}

int main()
{
    XInitThreads();
    sf::Font f;
    f.loadFromFile("Ubuntu-L.ttf");
    sf::RenderWindow *win, *win2;
    std::thread second(Func, win2);
    win = new sf::RenderWindow();
    win->create(sf::VideoMode(800, 600), "fsdfs");
    sf::Button button1(sf::Vector2f(400, 300), sf::Vector2f(50, 20), f, "second");
    while (win->isOpen())
    {
        sf::Event e;
        while (win->pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                if (!win2->isOpen())
                    win->close();
            }
            if (button1.GetState() == sf::Button::State::Pressed)
            {
                second.detach();
                button1.CallBack();
            }
        }
        button1.Update(e, *win);
        win->clear(sf::Color::White);
        win->draw(button1);
        win->display();
    }
}