#include "Battlefield.hpp"

Battlefield::Battlefield() {
    // plarform = new Plarform();
    // balls.push_back(new Ball());
    grid = new Grid;
    }

void Battlefield::newIterationBattlefield(){
    this->grid->drawGrid();
    // this->plarform->drawPlarform();
    // for (auto& ball : balls) {
    //     ball->drawBall();
    //     ball->collision(&plarform);
    //     ball->collision(&grid, bonuses);
    //     ball->moveBall();
    // }
    // for (auto& bonus : bonuses){
    //     if (bonus != nullptr){
    //         bonus->drawBonus();
    //         bonus->moveBonus();
    //         if (bonus->collision(&plarform)){
    //             bonus->useBonus(balls);
    //             delete bonus;
    //             bonus = nullptr;
    //         }
    //     }
    // }
        // for (int i = 0; i < balls.size(); i++) {
        //     for (int j = i + 1; j < balls.size(); j++) {
        //         balls[i]->collision(balls[j]);
        //     }
        // }

}
// Plarform* Battlefield::getPlatform() {
//     return plarform;
// }

Battlefield::~Battlefield() {
    delete grid;
    // delete plarform;
    // for (auto& ball : balls) {
    //     delete ball;
    // }
    // for (auto& bonus : bonuses) {
    //     delete bonus;
    // }
}

