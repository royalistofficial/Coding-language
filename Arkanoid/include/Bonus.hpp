#pragma once 
#include "const.hpp"
#include "Ball.hpp"

class Bonus {
public:
    Bonus(int row, int col);
    void moveBonus();
    void drawBonus();
    float GetX();
    float GetY();
    float GetR();
    virtual void useBonus(std::vector<Ball*>& Balls) = 0;

protected:
    float x;
    float y;
    float colorR;
    float colorG;
    float colorB;
    void draw();
};

class AddBallBonus : public Bonus {
public:
    AddBallBonus(int row, int col);
    void useBonus(std::vector<Ball*>& Balls) override;
};

class SpeedUpBonus : public Bonus {
public:
    SpeedUpBonus(int row, int col);
    void useBonus(std::vector<Ball*>& Balls) override;
};

class ExtraLifeBonus: public Bonus {
public:
    ExtraLifeBonus(int row, int col);
    void useBonus(std::vector<Ball*>& Balls) override;
};
