#include <map>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;
struct Vector2
{
    long long x = 0, y = 0;
    Vector2() {}
    Vector2(string strv)
    {
        if (strv.find('_') != string::npos)
        {
            this->x = stol(strv.substr(0, strv.find('_')));
            this->y = stol(strv.substr(strv.find('_') + 1));
        }
    }
    Vector2(const long long x, const long long y)
    {
        this->x = x;
        this->y = y;
    }
    bool operator!=(const Vector2 other) const
    {
        return other.x != this->x || other.y != this->y;
    }
    bool operator==(const Vector2 other) const
    {
        return other.x == this->x && other.y == this->y;
    }
    bool operator>(const Vector2 other) const
    {
        return this->x > other.x && this->y > other.y;
    }
    bool operator<(const Vector2 other) const
    {
        return this->x < other.x && this->y < other.y;
    }
    bool operator>=(const Vector2 other) const
    {
        return this->x >= other.x && this->y >= other.y;
    }
    bool operator<=(const Vector2 other) const
    {
        return this->x <= other.x && this->y <= other.y;
    }
    void operator+=(const long long val)
    {
        this->x += val;
        this->y += val;
    }
    void operator-=(const long long val)
    {
        this->x -= val;
        this->y -= val;
    }
    Vector2 operator+(const long long val) const
    {
        return Vector2(this->x + val, this->y + val);
    }
    Vector2 operator-(const long long val) const
    {
        return Vector2(this->x - val, this->y - val);
    }
    string str() const { return to_string(this->x) + "_" + to_string(this->y); }
    operator string() const { return to_string(this->x) + "_" + to_string(this->y); }
};

struct Matrix
{
    map<string, long long> mx;
    Vector2 size;
    Matrix(Vector2 size)
    {
        this->size = size;
    }
    void print()
    {
        for (int y = 1; y <= this->size.y; y++)
        {
            for (int x = 1; x <= this->size.x; x++)
            {
                if (mx.count(Vector2(x, y)) != 0)
                    cout << mx[Vector2(x, y)] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
    void printl()
    {
        for (int y = 1; y <= this->size.y; y++)
        {
            for (int x = 1; x <= this->size.x; x++)
            {
                if (mx.count(Vector2(x, y)) != 0)
                    cout << mx[Vector2(x, y)] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void setValue(Vector2 pos, long long val)
    {
        if (this->size >= pos)
        {
            mx[pos] = val;
        }
        else
        {
            cout << "out of bounds\n";
        }
    }
    void setValue(long long x, long long y, long long val)
    {
        Vector2 pos(x, y);
        if (this->size >= pos)
        {
            mx[pos] = val;
        }
        else
        {
            cout << "out of bounds\n";
        }
    }
    Matrix operator+(Matrix other) const
    {
        assert(this->size == other.size);
        Matrix result(this->size);
        for (int y = 1; y <= this->size.y; y++)
        {
            for (int x = 1; x <= this->size.x; x++)
            {
                Vector2 p(x, y);
                if (this->mx.find(p) != this->mx.end() && other.mx.find(p) != other.mx.end())
                {
                    result.mx[p] = this->mx.at(p) + other.mx[p];
                }
                else if (this->mx.find(p) != this->mx.end())
                {
                    result.mx[p] = this->mx.at(p);
                }
                else if (other.mx.find(p) != other.mx.end())
                {
                    result.mx[p] = other.mx[p];
                }
            }
        }
        return result;
    }
    Matrix operator*(long long other) const
    {
        Matrix result(this->size);
        for (int y = 1; y <= this->size.y; y++)
        {
            for (int x = 1; x <= this->size.x; x++)
            {
                Vector2 p(x, y);
                if (this->mx.find(p) != this->mx.end())
                {
                    result.mx[p] = this->mx.at(p) * other;
                }
            }
        }
        return result;
    }
    Matrix &operator*=(long long val)
    {
        for (int y = 1; y <= this->size.y; y++)
        {
            for (int x = 1; x <= this->size.x; x++)
            {
                Vector2 p(x, y);
                if (this->mx.find(p) != this->mx.end())
                {
                    this->mx.at(p) *= val;
                }
            }
        }
        return *this;
    }
    Matrix operator*(Matrix other) const
    {
        assert(this->size.x == other.size.y);
        Matrix result(Vector2(other.size.x, this->size.y));
        for (int bx = 1; bx <= other.size.x; bx++)
        {
            for (int ty = 1; ty <= this->size.y; ty++)
            {
                for (int bt = 1; bt <= this->size.x; bt++)
                {
                    Vector2 rp(bx, ty);
                    Vector2 ap(bt, ty);
                    Vector2 bp(bx, bt);
                    if (this->mx.find(ap) != this->mx.end() && other.mx.find(bp) != other.mx.end())
                    {
                        result.mx[rp] += this->mx.at(ap) * other.mx[bp];
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    Matrix m(Vector2(3, 2));
    m.setValue(Vector2(1, 1), 5);
    m.setValue(Vector2(2, 1), 6);
    m.setValue(Vector2(3, 1), 4);
    m.setValue(Vector2(1, 2), 3);
    m.setValue(Vector2(2, 2), 1);
    m.setValue(Vector2(3, 2), 3);
    m.printl();
    Matrix k(Vector2(4, 3));
    k.setValue(Vector2(1, 1), 11);
    k.setValue(Vector2(2, 1), 8);
    k.setValue(Vector2(3, 1), 1);
    k.setValue(Vector2(4, 1), 2);
    k.setValue(Vector2(1, 2), 9);
    k.setValue(Vector2(2, 2), 10);
    k.setValue(Vector2(3, 2), 7);
    k.setValue(Vector2(4, 2), 4);
    k.setValue(Vector2(1, 3), 3);
    k.printl();
    Matrix b = m * k;
    b.printl();
}