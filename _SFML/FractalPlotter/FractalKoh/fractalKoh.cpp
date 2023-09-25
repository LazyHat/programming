#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#define X 800
#define Y 500

using namespace sf;
using namespace std;

float tantocos(float tan)
{
    if (tan > 0.f)
        return 1 / sqrt(tan * tan + 1);
    else if (tan < 0.f)
        return -1 / sqrt(tan * tan + 1);
    else
        return 1;
}
float tantosin(float tan)
{
    return 1 / sqrt((1 / tan) * (1 / tan) + 1);
}

class line
{
    Vertex l[2];

public:
    line(Vector2f start, Vector2f end)
    {
        this->l[0].position = start;
        this->l[1].position = end;
    }
    line(Vector2f start, float rangle, float length)
    {
        this->l[0].position = start;
        this->l[1].position = Vector2f(start.x + length * std::cos(rangle),
                                       start.y + length * std::sin(rangle));
    }
    Vector2f getstart() const { return this->l[0].position; }
    Vector2f getend() const { return this->l[1].position; }
    float getstartx() const { return this->l[0].position.x; }
    float getstarty() const { return this->l[0].position.y; }
    float getendx() const { return this->l[1].position.x; }
    float getendy() const { return this->l[1].position.y; }
    void setstart(Vector2f start) { this->l[0].position = start; }
    void setend(Vector2f end) { this->l[1].position = end; }
    void resize(float nsize)
    {
        float cos = this->cos();
        float sin = this->sin();
        this->l[1].position.x = this->getstartx() + nsize * cos;
        this->l[1].position.y = this->getstarty() + nsize * sin;
    }
    float uxsize() const { return abs(this->l[1].position.x - this->l[0].position.x); }
    float uysize() const { return abs(this->l[1].position.y - this->l[0].position.y); }
    float xsize() const { return this->l[1].position.x - this->l[0].position.x; }
    float ysize() const { return this->l[1].position.y - this->l[0].position.y; }
    float length() const { return sqrt(xsize() * xsize() + ysize() * ysize()); }
    float tan() const { return this->ysize() / this->xsize(); }
    float ctan() const { return 1 / tan(); }
    float cos() const
    {
        if (this->getendx() > this->getstartx())
            return 1 / sqrt(tan() * tan() + 1);
        else if (this->getendx() < this->getstartx())
            return -1 / sqrt(tan() * tan() + 1);
        else
            return 0;
    }
    float sin() const
    {
        if (this->getendy() > this->getstarty())
        {
            return 1 / sqrt(ctan() * ctan() + 1);
        }
        else if (this->getendy() < this->getstarty())
        {
            return -1 / sqrt(ctan() * ctan() + 1);
        }
        else
            return 0;
    }
    float rangle()
    {
        if (this->cos() > 0)
            return atan(this->tan());
        else
            return atan(this->tan()) + M_PI;
    }
    VertexArray getinvlY(const float Yresolution) const
    {
        VertexArray lines(Lines, 2);
        lines[0].position = Vector2f(this->getstartx(), Yresolution - this->getstarty());
        lines[1].position = Vector2f(this->getendx(), Yresolution - this->getendy());
        return lines;
    }
};

void insert(vector<line> &ls, unsigned int i, line l)
{
    auto it = ls.begin() + i;
    ls.insert(it, l);
}

void FractalKoh(vector<line> &ls)
{
    for (int i = 0; i < ls.size(); i++)
    {
        ls[i].resize(ls[i].length() / 3.f);
        insert(ls, ++i, line(ls[i].getend(), ls[i].rangle() + M_PI / 3, ls[i].length()));
        insert(ls, ++i, line(ls[i].getend(), ls[i].rangle() - 2 * M_PI / 3, ls[i].length()));
        insert(ls, ++i, line(ls[i].getend(), ls[i].rangle() + M_PI / 3, ls[i].length()));
    }
}

int main()
{
    RenderWindow win(VideoMode(X, Y), "FRACTALS");
    vector<line> lines;
    lines.push_back(line(Vector2f(0, Y * 1 / 3), 0, X));
    while (win.isOpen())
    {
        Event e;
        while (win.pollEvent(e))
        {
            switch (e.type)
            {
            case Event::Closed:
                win.close();
                break;
            case Event::KeyReleased:
                if (e.key.code == Keyboard::Enter)
                {
                    FractalKoh(lines);
                }
                break;
            }
        }
        win.clear();
        for (auto &&i : lines)
        {
            win.draw(i.getinvlY(Y));
        }
        win.display();
    }
}