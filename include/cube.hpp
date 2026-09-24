#pragma once
#include "move.hpp"
#include <string>
using std::string;

class Cube
{
public:
    Cube();
    void printCube();
    void printFace(Colour ind);
    void printOrient();
    void makeMove(Move move);
	
	// TODO: Change this function name its kinda bad: (makeMoveSet)
	void makeMoveSet(string moves);
	
	Side getSideFromColour(Colour col);
	Colour getColourFromSide(Side side);

private:
    //* [0, 1, 2, 3, 4, 5, 6, 7]
    //*
    //* 0 1 2
    //* 7   3
    //* 6 5 4

    Colour whiteFace[8];
    Colour greenFace[8];
    Colour redFace[8];
    Colour yellowFace[8];
    Colour blueFace[8];
    Colour orangeFace[8];
    Colour* faces[6] = {whiteFace, greenFace, redFace, yellowFace, blueFace, orangeFace};

    //* The Top, Front, Right Colour, used for the orientation
	// NOTE: Default conf is White, Green, Red
    //* 0 -> Top, 1 -> Front, 2 -> Right
    Colour orient[3];

    void rotateFace(int ind, Direction dir);

    void orientX(Direction dir);
    void orientY(Direction dir);
    void orientZ(Direction dir);

    void leftTurn(Direction dir);
    void rightTurn(Direction dir);
    void upTurn(Direction dir);
    void downTurn(Direction dir);
    void frontTurn(Direction dir);
    void backTurn(Direction dir);

	// void (*ptr[9])(Direction);
	void (Cube::*moveFunctions[9])(Direction) = {&Cube::leftTurn, &Cube::rightTurn, &Cube::upTurn,
		&Cube::downTurn, &Cube::frontTurn, &Cube::backTurn, &Cube::orientX, &Cube::orientY, &Cube::orientZ};
};
