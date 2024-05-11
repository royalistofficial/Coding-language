#pragma once
#include "const.hpp"
#include "Platform.hpp"
#include "Grid.hpp"
#include "Bonus.hpp"


class Ball {
public:
    Ball();
    void drawBall();
    void moveBall();
    void collision(Platform* plarform);
    void collision(Grid* grid, std::vector<Bonus*>& bonuses);

private:
    float x;
    float y;
    float angle;
    float radius;
    float speed;

    void draw();
    bool checkingPlarform(float platformX, int SizePlarform);
    bool checkingGrid(int row, int col);
    bool checkingTouchLine(float x1, float y1, float x2, float y2);
};