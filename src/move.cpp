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
		case Colour::White:
			return 'W';
		case Colour::Green:
			return 'G';
		case Colour::Red:
			return 'R';
		case Colour::Yellow:
			return 'Y';
		case Colour::Blue:
			return 'B';
		case Colour::Orange:
			return 'O';
	}
    return ' ';
}

Colour getOpposite(Colour col)
{
    int c = ((int) col + 3) % 6;
    return (Colour)c;
}
