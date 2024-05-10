#include "const.hpp"
#include "Plarform.hpp"
#include "Grid.hpp"
#include "Ball.hpp"
#include "bonus.hpp"

class Battlefield {
public:
    Battlefield() {
        plarform = new Plarform();
        balls.push_back(new Ball());
        grid = new Grid;
    }

    void newIterationBattlefield(){
        this->grid->drawGrid();
        this->plarform->drawPlarform();
        for (auto& ball : balls) {
            ball->drawBall();
            ball->collision(&plarform);
            ball->collision(&grid, bonuses);
            ball->moveBall();
        }
        for (auto& bonus : bonuses){
            bonus->drawBonus();
            bonus->moveBonus();
        }
        // for (int i = 0; i < balls.size(); i++) {
        //     for (int j = i + 1; j < balls.size(); j++) {
        //         balls[i]->collision(balls[j]);
        //     }
        // }

    }
    Plarform* getPlatform() {
        return plarform;
    }
    ~Battlefield() {
        delete grid;
        delete plarform;
        for (auto& ball : balls) {
            delete ball;
        }
        for (auto& bonus : bonuses) {
            delete bonus;
        }
    }
private:
    Grid *grid;
    Plarform *plarform;
    std::vector<Ball*> balls;
    std::vector<Bonus*> bonuses;
};
