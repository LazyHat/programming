#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#define X 800
#define Y 500

using namespace sf;
using namespace std;

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
    Vector2f getCenter() { return Vector2f((this->l[1].position.x + this->l[0].position.x) / 2,
                                           (this->l[1].position.y + this->l[0].position.y) / 2); }
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

class Trg
{
    VertexArray l;

public:
    Trg() { l = VertexArray(Triangles, 3); }
    Trg(Vector2f p1, Vector2f p2, Vector2f p3, Color col)
    {
        this->l = VertexArray(Triangles, 3);
        this->l[0].position = p1;
        this->l[0].color = col;
        this->l[1].position = p2;
        this->l[1].color = col;
        this->l[2].position = p3;
        this->l[2].color = col;
    }
    Color getcolor() const { return l[0].color; }
    Vector2f getp1() const { return this->l[0].position; }
    Vector2f getp2() const { return this->l[1].position; }
    Vector2f getp3() const { return this->l[2].position; }
    line getline12() const { return line(this->l[0].position, this->l[1].position); }
    line getline13() const { return line(this->l[0].position, this->l[2].position); }
    line getline23() const { return line(this->l[1].position, this->l[2].position); }
    VertexArray getinvlY(const float Yresolution) const
    {
        VertexArray trgs = this->l;
        trgs[0].position = Vector2f(this->l[0].position.x, Yresolution - this->l[0].position.y);
        trgs[1].position = Vector2f(this->l[1].position.x, Yresolution - this->l[1].position.y);
        trgs[2].position = Vector2f(this->l[2].position.x, Yresolution - this->l[2].position.y);
        return trgs;
    }
};

class Ftree
{
    Color col;
    Trg *t = nullptr;
    Ftree *next1 = nullptr;
    Ftree *next2 = nullptr;
    Ftree *next3 = nullptr;

public:
    Ftree(Vector2f p1, Vector2f p2, Vector2f p3, Color color)
    {
        this->col = color;
        this->t = new Trg(p1, p2, p3, col);
    }
    void Fnext()
    {
        this->next1 = new Ftree(this->t->getline12().getCenter(), this->t->getline13().getCenter(), this->t->getp1(), this->getcolor());
        this->next2 = new Ftree(this->t->getline12().getCenter(), this->t->getline23().getCenter(), this->t->getp2(), this->getcolor());
        this->next3 = new Ftree(this->t->getline23().getCenter(), this->t->getline13().getCenter(), this->t->getp3(), this->getcolor());
        delete this->t;
        this->t = nullptr;
    }
    void deltrg()
    {
        delete this->t;
        this->t = nullptr;
    }
    Trg *gettrg() { return this->t; }
    void settrg(Trg *newtrg) { this->t = newtrg; }
    Ftree *getnext1() const { return this->next1; }
    Ftree *getnext2() const { return this->next2; }
    Ftree *getnext3() const { return this->next3; }
    void setnext1(Ftree *next) { this->next1 = next; }
    void setnext2(Ftree *next) { this->next2 = next; }
    void setnext3(Ftree *next) { this->next3 = next; }
    Color getcolor() const { return this->col; }
    void drawinvY(RenderWindow &w, float Yres)
    {
        w.draw(this->t->getinvlY(Yres));
    }
};

void FractalSerpinsky(Ftree &t)
{
    if (t.gettrg() == nullptr)
    {
        FractalSerpinsky(*(t.getnext1()));
        FractalSerpinsky(*(t.getnext2()));
        FractalSerpinsky(*(t.getnext3()));
    }
    else
    {
        t.setnext1(new Ftree(t.gettrg()->getline12().getCenter(), t.gettrg()->getline13().getCenter(), t.gettrg()->getp1(), t.getcolor()));
        t.setnext2(new Ftree(t.gettrg()->getline12().getCenter(), t.gettrg()->getline23().getCenter(), t.gettrg()->getp2(), t.getcolor()));
        t.setnext3(new Ftree(t.gettrg()->getline23().getCenter(), t.gettrg()->getline13().getCenter(), t.gettrg()->getp3(), t.getcolor()));
        t.deltrg();
    }
}

void DrawTree(Ftree t, RenderWindow &w, float Yres)
{
    if (t.gettrg() == nullptr)
    {
        DrawTree(*(t.getnext1()), w, Yres);
        DrawTree(*(t.getnext2()), w, Yres);
        DrawTree(*(t.getnext3()), w, Yres);
    }
    else
    {
        t.drawinvY(w, Yres);
    }
}

int main()
{
    RenderWindow win(VideoMode(X, Y), "FRACTALS");
    Ftree tree(Vector2f(0, 0), Vector2f(X / 2, Y), Vector2f(X, 0), Color::White);
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
                    FractalSerpinsky(tree);
                break;
            }
        }
        win.clear();
        DrawTree(tree, win, Y);
        win.display();
    }
}