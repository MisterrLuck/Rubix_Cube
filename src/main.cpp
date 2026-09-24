#include "cube.hpp"
#include <iostream>
using namespace std;

int main()
{
    Cube cube;

    cube.printFace(Green);

    Move move(Y);
    cube.makeMove(move);

    move = Move(Left);
    cube.makeMove(move);
    cube.printFace(Green);

    move = Move(Left, Double);
    cube.makeMove(move);
    cube.printFace(Green);

    cube.printOrient();

    move = Move(Y, Double);
    cube.makeMove(move);
    cube.printOrient();

    move = Move(Z, Prime);
    cube.makeMove(move);
    cube.printOrient();
    
    return 0;
}
