#pragma once
#include "const.hpp"

struct Square {
    float colorR;
    float colorG;
    float colorB;  // цвет квадрата
    int destructibility;     // разрушаемость квадрата

    Square(float r, float g, float b, int destructibility) {
        this->colorR = r;
        this->colorG = g;
        this->colorB = b;
        this->destructibility = destructibility;
    }
};


class Grid {
public:
    Grid();
    void drawGrid();
    bool deleteSquare(int i, int j);
    Square* getGrid(int i, int j);
    ~Grid();

private:
    Square *grid[GRID_SIZE][GRID_SIZE];
    void draw();
    void drawSquare(int row, int col);
};