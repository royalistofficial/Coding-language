#pragma once 
#include "const.hpp"
#include "Platform.hpp"
#include "Ball.hpp"

class Bonus {
public:
    Bonus(int row, int col);
    virtual void moveBonus() = 0;
    virtual void drawBonus() = 0;
    virtual void useBonus(std::vector<Ball*>& Balls) = 0;
    bool collision(Platform* plarform);

protected:
    float x;
    float y;
    float colorR;
    float colorG;
    float colorB;
    const float radius = 0.01f;
    void draw();
};

class AddBall : public Bonus {
public:
    AddBall(int row, int col);
    void useBonus(std::vector<Ball*>& Balls) override;
};

