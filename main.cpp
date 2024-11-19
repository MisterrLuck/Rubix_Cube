#include "cube.hpp"
#include <iostream>
using namespace std;

int main()
{
    Cube cube;

    // // cube.printCube();

    for (Colour c : cube.orient) {
        cout << getColourChar(c);
    }
    cout << "\n";

    Move move(Y, Double);
    cube.makeMove(move);

    for (Colour c : cube.orient) {
        cout << getColourChar(c);
    }
    cout << "\n";

    move = Move(Z, Prime);
    cube.makeMove(move);

    for (Colour c : cube.orient) {
        cout << getColourChar(c);
    }
    cout << "\n";
    return 0;
}