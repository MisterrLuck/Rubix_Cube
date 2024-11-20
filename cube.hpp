#include "move.hpp"


class Cube
{
public:
    Cube();
    void printCube();
    void printOrient();
    void makeMove(Move move);

private:

    Colour whiteFace[8];
    Colour greenFace[8];
    Colour redFace[8];
    Colour yellowFace[8];
    Colour blueFace[8];
    Colour orangeFace[8];
    Colour* faces[6] = {whiteFace, greenFace, redFace, yellowFace, blueFace, orangeFace};

    //* The Top, Front, Right Colour, used for the orientation
    //* 0 -> Top, 1 -> Front, 2 -> Right
    Colour orient[3];

    void printFace(int ind);

    void orientX(Direction dir);
    void orientY(Direction dir);
    void orientZ(Direction dir);

    void leftTurn(Direction dir);
    void rightTurn(Direction dir);
    void upTurn(Direction dir);
    void downTurn(Direction dir);
    void frontTurn(Direction dir);
    void backTurn(Direction dir);

    void (Cube::*moveFunctions[9])(Direction) = {leftTurn, rightTurn, upTurn, downTurn, frontTurn, backTurn, orientX, orientY, orientZ};
};