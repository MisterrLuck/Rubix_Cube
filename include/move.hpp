enum class Colour
{
    White, Green, Red, Yellow, Blue, Orange
};

char getColourChar(Colour col);
Colour getOpposite(Colour col);


 //* X -> R direction
 //* Y -> U direction
 //* Z -> F direction
enum class Side
{
    Left, Right, Up, Down, Front, Back, X, Y, Z
};

enum class Direction
{
    Normal, Prime, Double
};

struct Move
{
    Side side;
    Direction dir;

    Move(Side s, Direction d = Direction::Normal);
};
