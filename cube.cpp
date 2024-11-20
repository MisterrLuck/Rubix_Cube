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
    for (int i = 0; i < 8; i++)
    {
        faces[(int) Green][i] = (Colour)(i%6);
        // faces[(int) Green][i] = static_cast<Colour>(i);
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

    for (int i = 0; i < 3; i++)
    {
        cout << getColourChar(face[i]) << " ";
    }
    cout << "\n" << getColourChar(face[7]) << "   " << getColourChar(face[3]) << "\n";

    for (int i = 6; i > 3; i--)
    {
        cout << getColourChar(face[i]) << " ";
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

void Cube::leftTurn(Direction dir)
{
    int ind = getOpposite(orient[2]);
    Colour* face = faces[ind];

    rotateFace(ind, dir);
}

void Cube::rightTurn(Direction dir) {}
void Cube::upTurn(Direction dir) {}
void Cube::downTurn(Direction dir) {}
void Cube::frontTurn(Direction dir) {}
void Cube::backTurn(Direction dir) {}

void Cube::printOrient()
{
    for (Colour c : orient)
    {
        cout << getColourChar(c);
    }
    cout << "\n";
}

void Cube::rotateFace(int ind, Direction dir)
{
    Colour* face = faces[ind];
    Colour temp[2];
    switch (dir)
    {
    case Normal:
        temp[0] = face[6];
        temp[1] = face[7];
        for (int i = 7; i > 1; i--)
        {
            face[i] = face[i-2];
        }
        face[1] = temp[1];
        face[0] = temp[0];
        break;
    case Prime:
        temp[0] = face[0];
        temp[1] = face[1];
        for (int i = 0; i < 6; i--)
        {
            face[i] = face[i+2];
        }
        face[6] = temp[0];
        face[7] = temp[1];
        break;
    case Double:
        for (int i = 0; i < 4; i++)
        {
            int opp = (i+4) % 8;
            temp[0] = face[i];
            face[i] = face[opp];
            face[opp] = temp[0];
        }
        break;
    }
}