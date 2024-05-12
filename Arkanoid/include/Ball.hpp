#pragma once
#include "const.hpp"
#include "Platform.hpp"
#include "Grid.hpp"

class Ball {
public:
    Ball();
    void drawBall();
    void moveBall();

    void SpeedUp();

    bool checkingTouchLine(float x1, float y1, float x2, float y2);

    float GetX();
    float GetY();
    float GetAngle();
    int GetExtraLife();
    void SetAngle(float angle);
    void SetExtraLife(int i);

private:
    float x;
    float y;
    float angle;
    float speed;
    int extraLife;
    int numSleepSpeed;

    void draw();
};