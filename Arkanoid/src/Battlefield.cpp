#include "Battlefield.hpp"

Battlefield::Battlefield() {
    platform = new Platform();
    // balls.push_back(new Ball());
    grid = new Grid;
    }

void Battlefield::newIterationBattlefield(){
    this->grid->drawGrid();
    this->platform->drawPlatform();
    // for (auto& ball : balls) {
    //     ball->drawBall();
    //     ball->collision(&platform);
    //     ball->collision(&grid, bonuses);
    //     ball->moveBall();
    // }
    // for (auto& bonus : bonuses){
    //     if (bonus != nullptr){
    //         bonus->drawBonus();
    //         bonus->moveBonus();
    //         if (bonus->collision(&platform)){
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

void Battlefield::MovePlatform(const float dx) {
    this->platform->movePlatform(dx);
}

Battlefield::~Battlefield() {
    delete grid;
    delete platform;
    // for (auto& ball : balls) {
    //     delete ball;
    // }
    // for (auto& bonus : bonuses) {
    //     delete bonus;
    // }
}
