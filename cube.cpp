#include "cube.hpp"
#include <iostream>
using namespace std;

Cube::Cube()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            faces[i][j] = (Colour) i;
        }
    }
    orient[0] = White;
    orient[1] = Green;
    orient[2] = Red;
}

void Cube::printCube()
{
    for (int i = 0; i < 6; i++)
    {
        printFace(i);
    }
}

void Cube::printFace(int ind)
{
    Colour* face = faces[ind];
    for (int i = 0; i < 8; i++)
    {
        // cout << " ";
        cout << getColourChar(face[i]);
        if (i == 3)
            cout << " ";
        if (i == 2 || i == 4)
            cout << "\n";
    }
    cout << "\n";
}

void Cube::makeMove(Move move)
{
    Side side = move.side;
    Direction dir = move.dir;

    (this->*moveFunctions[(int) side])(dir);
}

//* Move cube in 'R' direction; On the X-axis
void Cube::orientX(Direction dir)
{
    Colour temp;
    switch (dir)
    {
    case Normal:
        temp = orient[0];
        orient[0] = orient[1];
        orient[1] = getOpposite(temp);
        break;
    case Prime:
        temp = orient[1];
        orient[1] = orient[0];
        orient[0] = getOpposite(temp);
        break;
    case Double:
        orient[1] = getOpposite(orient[1]);
        orient[0] = getOpposite(orient[0]);
    }
}

//* Move cube in 'U' direction; On the Y-axis
void Cube::orientY(Direction dir)
{
    Colour temp;
    switch (dir)
    {
    case Normal:
        temp = orient[1];
        orient[1] = orient[2];
        orient[2] = getOpposite(temp);
        break;
    case Prime:
        temp = orient[2];
        orient[2] = orient[1];
        orient[1] = getOpposite(temp);
        break;
    case Double:
        orient[1] = getOpposite(orient[1]);
        orient[2] = getOpposite(orient[2]);
    }
}

//* Move cube in 'F' direction; On the Z-axis
void Cube::orientZ(Direction dir)
{
    Colour temp;
    switch (dir)
    {
    case Normal:
        temp = orient[2];
        orient[2] = orient[0];
        orient[0] = getOpposite(temp);
        break;
    case Prime:
        temp = orient[0];
        orient[0] = orient[2];
        orient[2] = getOpposite(temp);
        break;
    case Double:
        orient[0] = getOpposite(orient[0]);
        orient[2] = getOpposite(orient[2]);
    }
}

void Cube::leftTurn(Direction dir) {
    Colour* face = faces[getOpposite(orient[2])];
}

void Cube::rightTurn(Direction dir) {}
void Cube::upTurn(Direction dir) {}
void Cube::downTurn(Direction dir) {}
void Cube::frontTurn(Direction dir) {}
void Cube::backTurn(Direction dir) {}

void Cube::printOrient() {
    for (Colour c : orient) {
        cout << getColourChar(c);
    }
    cout << "\n";
}