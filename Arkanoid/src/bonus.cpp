#include "bonus.hpp"

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

bool Bonus::collision(Plarform* plarform) {
    float platformX = (*plarform)->getX();
    int SizePlarform = (*plarform)->getSizePlatform();
    if (std::abs(platformX - this->x) <= SizePlarform + radius && std::abs(this->y + 1) <= radius) {
        return true;
    }
    return false;
}

void Bonus::draw() {
    const int num_segments = 16;
    glColor3f(this->colorR, this->colorG, this->colorB);
    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.14f * float(i) / float(num_segments);
        glVertex2f(this->x + this->radius * cos(theta), this->y + this->radius * sin(theta));
    }
    glEnd();
}

AddBall::AddBall(int row, int col) : Bonus(row, col) {
    colorR = 0.5f;
    colorG = 0.0f;
    colorB = 0.5f;
}

void AddBall::useBonus(std::vector<Ball*>& Balls) {
    Balls.push_back(new Ball());
}