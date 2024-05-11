#pragma once
#include "const.hpp"
#include "Grid.hpp"
// #include "Platform.hpp"
// #include "Ball.hpp"
// #include "Bonus.hpp"


class Battlefield {
public:
    Battlefield();
    void newIterationBattlefield();
    // Platform* getPlatform();
    ~Battlefield();
private:
    Grid *grid;
    // Platform *plarform;
    // std::vector<Ball*> balls;
    // std::vector<Bonus*> bonuses;
};
