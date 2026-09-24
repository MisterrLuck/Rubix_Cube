#include "cube.hpp"
#include <iostream>
using namespace std;

int main()
{
    Cube cube;
	
	cout << "Print Green Face\n";
    cube.printFace(Colour::Green);

	cout << "\nMove Y\n";
	// This makes green on the left
    Move move(Side::Y);
    cube.makeMove(move);
	
	cout << "\nMove Left and Print Green Face\n";
    move = Move(Side::Left);
    cube.makeMove(move);
    cube.printFace(Colour::Green);

	cout << "\nMove Left 2 and Print Green Face\n";
    move = Move(Side::Left, Direction::Double);
    cube.makeMove(move);
    cube.printFace(Colour::Green);

	cout << "\nPrint Orient\n";
    cube.printOrient();

	cout << "\nMove Y 2 and Print Orient\n";
    move = Move(Side::Y, Direction::Double);
    cube.makeMove(move);
    cube.printOrient();

	cout << "\nMove Z' and Print Orient\n";
    move = Move(Side::Z, Direction::Prime);
    cube.makeMove(move);
    cube.printOrient();
    
    return 0;
}
