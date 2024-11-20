#include "cube.hpp"
#include <iostream>
using namespace std;

int main()
{
    Cube cube;

    // // cube.printCube();

    cube.printOrient();

    Move move(Y, Double);
    cube.makeMove(move);

    cube.printOrient();

    move = Move(Z, Prime);
    cube.makeMove(move);

    cube.printOrient();
    
    return 0;
}