#include <SFML/Graphics.hpp>
#include <iostream>
#define X 800
#define Y 500
#define METR 10

using namespace sf;
using namespace std;

int main()
{
    cout << "m1:";
    int m1;
    cin >> m1;
    cout << "v1:";
    float v1;
    cin >> v1;
    cout << "m2:";
    int m2;
    cin >> m2;
    cout << "v2:";
    float v2;
    cin >> v2;
    v2 *= METR;
    v1 *= METR;
    v2 *= -1;
    RenderWindow win(VideoMode(X, Y), "ELASTICCOLLISION");
    VertexArray walls(Lines, 6);
    Font ubuntuf;
    ubuntuf.loadFromFile("Ubuntu-L.ttf");
    Text fps("Fps: ", ubuntuf, 20);
    fps.setFillColor(Color::Red);
    walls[0].position = Vector2f(X / 16, Y / 2 + Y / 3);
    walls[1].position = Vector2f(X / 16, Y / 2 - Y / 3);
    walls[2].position = Vector2f(X - X / 16, Y / 2 + Y / 3);
    walls[3].position = Vector2f(X - X / 16, Y / 2 - Y / 3);
    CircleShape c1(m1 / 2);
    c1.setPosition(X / 16, Y / 2 - m1 / 2);
    CircleShape c2(m2 / 2);
    c2.setPosition(X - X / 16 - m2, Y / 2 - m2 / 2);
    Clock clk;
    win.setFramerateLimit(120);
    while (win.isOpen())
    {
        float framerate = (float)clk.restart().asMilliseconds() / 1000;
        fps.setString("Fps: " + to_string(1.f / framerate));
        Event e;
        while (win.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
                win.close();
            }
        }
        if (c1.getPosition().x + c1.getRadius() * 2 >= c2.getPosition().x)
        {
            int pv1 = v1;
            v1 = (v1 * (m1 - m2) + 2 * m2 * v2) / (m1 + m2);
            v2 = pv1 + v1 - v2;
        }
        if (walls[0].position.x >= c1.getPosition().x)
        {
            v1 = -v1;
        }
        if (walls[2].position.x <= c2.getPosition().x + c2.getRadius() * 2)
        {
            v2 = -v2;
        }
        c1.move(v1 * framerate, 0);
        c2.move(v2 * framerate, 0);
        win.clear();
        win.draw(walls);
        win.draw(c1);
        win.draw(c2);
        win.draw(fps);
        win.display();
    }
}