#include "Plarform.hpp"
#include "Grid.hpp"
#include "Ball.hpp"
#include "const.hpp"
class Battlefield {
public:
    Battlefield() {
        plarform = new Plarform();
        ball = new Ball();
        grid = new Grid;
    }

    void newIterationBattlefield(){
        this->grid->drawGrid();
        this->plarform->drawPlarform();
        this->ball->drawBall();
        this->ball->moveBall();
    }
    Plarform* getPlatform() {
        return plarform;
    }
    ~Battlefield() {
        delete grid;
        delete plarform;
        delete ball;
    }
    Grid *grid;
    Plarform *plarform;
    Ball *ball;
};
