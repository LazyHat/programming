#include <SFML/Graphics.hpp>
#define X 800
#define Y 500

using namespace sf;
using namespace std;
int main()
{
    RenderWindow win(VideoMode(X, Y), "HEART");

    while (win.isOpen())
    {
        Event e;
        while (win.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
                win.close();
            }
        }
        win.clear();
        win.display();
    }
}