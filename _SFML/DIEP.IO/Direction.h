#pragma once

class Direction
{
    unsigned char value = 0;

    Direction(int value);

public:
    Direction();
    static const Direction Up;
    static const Direction Down;
    static const Direction Left;
    static const Direction Right;

    bool isNotNone();
    bool contains(Direction dir);
    inline Direction operator|(Direction a);
    inline Direction operator|=(Direction a);
    int getValue() { return value; }
};

const Direction Direction::Up = Direction(1);
const Direction Direction::Down = Direction(2);
const Direction Direction::Left = Direction(4);
const Direction Direction::Right = Direction(8);

Direction::Direction() {}

Direction::Direction(int value)
{
    this->value = value;
}

bool Direction::isNotNone()
{
    return this->value != 0;
}

bool Direction::contains(Direction obj)
{
    unsigned char a = this->value & obj.value;
    return a != 0;
}

inline Direction Direction::operator|(Direction a)
{
    return Direction(this->value | a.value);
}

inline Direction Direction::operator|=(Direction a)
{
    this->value |= a.value;
    return *this;
}