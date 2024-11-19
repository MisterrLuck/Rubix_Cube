#include "cube.hpp"
#include <iostream>
using namespace std;

Cube::Cube() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            faces[i][j] = (Colour) i;
        }
    }
    // // for (int i = 0; i < 9; i++) {
    // //     whiteFace[i] = White;
    // // }
    // // for (int i = 0; i < 9; i++) {
    // //     greenFace[i] = Green;
    // // }
    // // for (int i = 0; i < 9; i++) {
    // //     redFace[i] = Red;
    // // }
    // // for (int i = 0; i < 9; i++) {
    // //     yellowFace[i] = Yellow;
    // // }
    // // for (int i = 0; i < 9; i++) {
    // //     blueFace[i] = Blue;
    // // }
    // // for (int i = 0; i < 9; i++) {
    // //     orangeFace[i] = Orange;
    // // }
}

void Cube::printCube() {
    for (int i = 0; i < 6; i++) {
        printFace(i);
    }
}

void Cube::printFace(int ind) {
    Colour* face = faces[ind];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << printColour(face[i+(j*3)]);
        }
        cout << "\n";
    }
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