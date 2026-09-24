#include "move.hpp"

Move::Move(Side s, Direction d)
{
    side = s;
    dir = d;
}

Move::Move(char s, char d)
{
	side = sideFromChar(s);
	dir = dirFromChar(d);
}

Side sideFromChar(char s)
{
	// TODO: Add error detection for unknown char
	Side side = Side::Right;
	
	switch (s)
	{
		case 'R': case 'r':
			side = Side::Right;
			break;
		case 'L': case 'l':
			side = Side::Left;
			break;
		case 'U': case 'u':
			side = Side::Up;
			break;
		case 'D': case 'd':
			side = Side::Down;
			break;
		case 'B': case 'b':
			side = Side::Back;
			break;
		case 'F': case 'f':
			side = Side::Front;
			break;
		case 'X': case 'x':
			side = Side::X;
			break;
		case 'Y': case 'y':
			side = Side::Y;
			break;
		case 'Z': case 'z':
			side = Side::Z;
			break;
	}

	return side;
}

Direction dirFromChar(char d)
{
	// TODO: Add error detection for unknown char: Maybe just stick to default?

	Direction dir = Direction::Normal;
	switch (d)
	{
		case ' ': case '_':
			dir = Direction::Normal;
			break;
		case '\'':
			dir = Direction::Prime;
			break;
		case '2':
			dir = Direction::Double;
			break;
	}

	return dir;
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
