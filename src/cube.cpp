#include "cube.hpp"
#include <iostream>
#include <string>
// using namespace std;
using std::cout, std::string;

Cube::Cube()
{
	// Creating the solved cube state
    for (int face = 0; face < 6; face++)
    {
        for (int cubelet = 0; cubelet < 8; cubelet++)
        {
            faces[face][cubelet] = (Colour) face;
        }
    }

	// HACK: This randomises the Green face for testing purposes
		//   for (int i = 0; i < 8; i++)
		//   {
		//       faces[(int) Colour::Green][i] = (Colour)(i%6);
		//
		// // NOTE: Is this commented code better?
		//       // faces[(int) Green][i] = static_cast<Colour>(i);
		//   }

	// Set the default orientation
	// NOTE: Might not need the third designation
    orient[0] = Colour::White;
    orient[1] = Colour::Green;
    orient[2] = Colour::Red;
}

void Cube::makeMoveSet(string moves)
{
	int size = moves.length();
	if (size %= 2)
		return; // TODO: Make an error probably
	
	for (int i = 0; i < size; i += 2)
	{
		char side = moves[i];
		char dir = moves[i+1];

		Move move(side, dir);

		makeMove(move);
	}
}

void Cube::printCube()
{
	// TODO: Make the printing differ based on orientation
    for (int i = 0; i < 6; i++)
    {
        printFace((Colour) i);
    }
}

void Cube::printFace(Colour ind)
{
    // TODO: Print different orient based on orientation
	Colour* face = faces[(int) ind];

    for (int i = 0; i < 3; i++)
    {
        cout << getColourChar(face[i]) << " ";
    }
    cout << "\n" << getColourChar(face[7]) << " " << getColourChar((Colour) ind) << " " << getColourChar(face[3]) << "\n";

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

	// FIX: IDK if I need the `this` keyword
    (this->*moveFunctions[(int) side])(dir);
}

//* Move cube in 'R' direction; On the X-axis
void Cube::orientX(Direction dir)
{
    Colour temp;
    switch (dir)
    {
		case Direction::Normal:
			temp = orient[0];
			orient[0] = orient[1];
			orient[1] = getOpposite(temp);
			break;
		case Direction::Prime:
			temp = orient[1];
			orient[1] = orient[0];
			orient[0] = getOpposite(temp);
			break;
		case Direction::Double:
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
		case Direction::Normal:
			temp = orient[1];
			orient[1] = orient[2];
			orient[2] = getOpposite(temp);
			break;
		case Direction::Prime:
			temp = orient[2];
			orient[2] = orient[1];
			orient[1] = getOpposite(temp);
			break;
		case Direction::Double:
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
		case Direction::Normal:
			temp = orient[2];
			orient[2] = orient[0];
			orient[0] = getOpposite(temp);
			break;
		case Direction::Prime:
			temp = orient[0];
			orient[0] = orient[2];
			orient[2] = getOpposite(temp);
			break;
		case Direction::Double:
			orient[0] = getOpposite(orient[0]);
			orient[2] = getOpposite(orient[2]);
    }
}

void Cube::leftTurn(Direction dir)
{
	// Opposite of right face
    int faceInd = (int) getOpposite(orient[2]);

    rotateFace(faceInd, dir);
}

void Cube::rightTurn(Direction dir)
{
	int faceInd = (int) orient[2];

	rotateFace(faceInd, dir);
}

void Cube::upTurn(Direction dir)
{
	int faceInd = (int) orient[0];

	rotateFace(faceInd, dir);
}

void Cube::downTurn(Direction dir)
{
	int faceInd = (int) getOpposite(orient[0]);

	rotateFace(faceInd, dir);
}

void Cube::frontTurn(Direction dir)
{
	int faceInd = (int) orient[1];

	rotateFace(faceInd, dir);
}

void Cube::backTurn(Direction dir)
{
	int faceInd = (int) getOpposite(orient[1]);

	rotateFace(faceInd, dir);
}

void Cube::printOrient()
{
	// Top face
	cout << " " << getColourChar(orient[0]) << "\n";
	// Left and front
	cout << getColourChar(getOpposite(orient[2])) << getColourChar(orient[1])
	// Right and back
		<< getColourChar(orient[2]) << getColourChar(getOpposite(orient[1])) << "\n";
	// Bottom
	cout << " " << getColourChar(getOpposite(orient[0])) << "\n";
}

// HACK: IDK how efficient this is
void Cube::rotateFace(int ind, Direction dir)
{
    Colour* face = faces[ind];
    Colour temp[2];
    switch (dir)
    {
		case Direction::Normal:
			temp[0] = face[6];
			temp[1] = face[7];
			for (int i = 7; i > 1; i--)
			{
				face[i] = face[i-2];
			}
			face[1] = temp[1];
			face[0] = temp[0];
			break;
		case Direction::Prime:
			temp[0] = face[0];
			temp[1] = face[1];
			for (int i = 0; i < 6; i--)
			{
				face[i] = face[i+2];
			}
			face[6] = temp[0];
			face[7] = temp[1];
			break;
		case Direction::Double:
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
