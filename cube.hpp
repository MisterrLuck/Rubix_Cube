enum Colour {
    White, Green, Red, Yellow, Blue, Orange
};
char printColour(Colour col);

class Cube {
    public:
    Cube();
    void printCube();

    private:
    Colour whiteFace[8];
    Colour greenFace[8];
    Colour redFace[8];
    Colour yellowFace[8];
    Colour blueFace[8];
    Colour orangeFace[8];
    Colour* faces[6] = {whiteFace, greenFace, redFace, yellowFace, blueFace, orangeFace};

    void printFace(int ind);
};