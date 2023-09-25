#include <SFML/Graphics.hpp>
#define X 500
#define Y 500

using namespace sf;
int main()
{
    srand(time(NULL));
    RenderWindow win(VideoMode(X, Y), "PTUTANKVECTOR");
    CircleShape ptu(3);
    ptu.setPosition(abs(rand()) % X, abs(rand()) % Y);
    RectangleShape tank(Vector2f(3, 3));
    tank.setPosition(abs(rand()) % X, abs(rand()) % Y);
    VertexArray grid(Lines, 4);
    grid[0] = Vector2f(0, Y / 2);
    grid[1] = Vector2f(X, Y / 2);
    grid[2] = Vector2f(X / 2, 0);
    grid[3] = Vector2f(X / 2, Y);
    Clock clk;
    while (win.isOpen())
    {
        double framerate = clk.restart().asMilliseconds() / 1000;
        Event event;
        while (win.pollEvent(event))
        {
            if (event.type == Event::Closed)
                win.close();
        }

        win.clear();
        win.draw(grid);
        win.draw(tank);
        win.draw(ptu);
        win.display();
    }
}