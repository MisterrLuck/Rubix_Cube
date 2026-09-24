#include "move.hpp"

Move::Move(Side s, Direction d)
{
    side = s;
    dir = d;
}


char getColourChar(Colour col)
{
    switch (col)
    {
    case White:
        return 'W';
    case Green:
        return 'G';
    case Red:
        return 'R';
    case Yellow:
        return 'Y';
    case Blue:
        return 'B';
    case Orange:
        return 'O';
    }
    return ' ';
}

Colour getOpposite(Colour col)
{
    int c = ((int)col + 3) % 6;
    return (Colour)c;
}