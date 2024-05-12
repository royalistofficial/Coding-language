#pragma once
#include "const.hpp"
#include "Grid.hpp"
#include "Platform.hpp"
#include "Ball.hpp"
#include "Bonus.hpp"


class Battlefield {
public:
    Battlefield();
    void newIterationBattlefield();
    void MovePlatform(const float dx);
    ~Battlefield();
private:
    Grid *grid;
    Platform *platform;
    std::vector<Ball*> balls;
    std::vector<Bonus*> bonuses;
    int score;
    void drawScore();
    void collisionPlatform(Ball* ball);
    void collisionGrid(Ball* ball);
    void collisionBall(Ball* ball1, Ball* ball2);
    bool collisionBonus(Bonus* bonus);
    bool checkingGrid(int row, int col, Ball* ball);
};
