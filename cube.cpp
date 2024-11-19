#include "cube.hpp"
#include <iostream>
using namespace std;

Cube::Cube() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            faces[i][j] = (Colour) i;
        }
    }
}

void Cube::printCube() {
    for (int i = 0; i < 6; i++) {
        printFace(i);
    }
}

void Cube::printFace(int ind) {
    Colour* face = faces[ind];
    for (int i = 0; i < 8; i++) {
        // cout << " ";
        cout << printColour(face[i]);
        if (i == 3)
            cout << " ";
        if (i == 2 || i == 4)
            cout << "\n";
    }
    cout << "\n";
}

char printColour(Colour col) {
    switch (col) {
        case White:
            return 'W';
        case Green:
            return 'G';
        case Red:
            return 'R';
        case Yellow:
            return 'Y';
        case Blue:
            return 'B';
        case Orange:
            return 'O';
    }
    return ' ';
}