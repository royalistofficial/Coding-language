#pragma once
#include "const.hpp"
#include "Grid.hpp"
#include "Platform.hpp"
// #include "Ball.hpp"
// #include "Bonus.hpp"


class Battlefield {
public:
    Battlefield();
    void newIterationBattlefield();
    void MovePlatform(const float dx);
    ~Battlefield();
private:
    Grid *grid;
    Platform *platform;
    // std::vector<Ball*> balls;
    // std::vector<Bonus*> bonuses;
};
