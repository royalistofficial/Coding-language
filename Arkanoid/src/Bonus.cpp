#include "Bonus.hpp"

Bonus::Bonus(int row, int col) {
    this->x = -1.0f + 2.0f * (col + 0.5f) / GRID_SIZE;
    this->y = 1.0f - 2.0f * (row + 0.5f) / GRID_SIZE;
}

void Bonus::moveBonus() {
    this->y -= SPEEDBONUS;
}

void Bonus::drawBonus() {
    draw();
}

float Bonus::GetX(){
    return x;
}
float Bonus::GetY(){
    return y;
}

void Bonus::draw() {
    const int num_segments = 16;
    glColor3f(this->colorR, this->colorG, this->colorB);
    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.14f * float(i) / float(num_segments);
        glVertex2f(this->x + BONUSRADIUS * cos(theta), this->y + BONUSRADIUS * sin(theta));
    }
    glEnd();
}

AddBallBonus::AddBallBonus(int row, int col) : Bonus(row, col) {
    colorR = 0.9f;
    colorG = 0.25f;
    colorB = 0.25f;
}

void AddBallBonus::useBonus(std::vector<Ball*>& Balls) {
    Balls.push_back(new Ball());
}


SpeedUpBonus::SpeedUpBonus(int row, int col) : Bonus(row, col) {
    colorR = 0.75f;
    colorG = 0.5f;
    colorB = 0.25f;
}

void SpeedUpBonus::useBonus(std::vector<Ball*>& balls) {
    for (auto& ball : balls) {
        if (ball != nullptr){
            ball->SpeedUp();
        }
    }
}

ExtraLifeBonus::ExtraLifeBonus(int row, int col) : Bonus(row, col) {
    colorR = 0.75f;
    colorG = 0.25f;
    colorB = 0.0f;
}

void ExtraLifeBonus::useBonus(std::vector<Ball*>& balls) {
    for (auto& ball : balls) {
        if (ball != nullptr){
            ball->SetExtraLife();
        }
    }
}