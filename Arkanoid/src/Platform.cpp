#include "Platform.hpp"

Platform::Platform(){
    this->x = 0;
    this->SizePlatform = 25;
}

void Platform::drawPlatform() {
    draw();
}

void Platform::movePlatform(float dx) {
    if ((dx > 0) && (this->x + (float(SizePlatform - 1) / (GRID_SIZE * 2.0f)) < 1)) {
        this->x += dx;
    } else if ((dx < 0) && (this->x - (float(SizePlatform - 1) / (GRID_SIZE * 2.0f)) > -1)) {
        this->x += dx;
    }
}

float Platform::getX(){
    return x;
}

int Platform::getSizePlatform(){
    return SizePlatform;
}

void Platform::draw() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(this->x - (float(SizePlatform) / (GRID_SIZE * 2.0f)), -1.0f + 1.0f / GRID_SIZE);
    glVertex2f(this->x + (float(SizePlatform) / (GRID_SIZE * 2.0f)), -1.0f + 1.0f / GRID_SIZE);
    glVertex2f(this->x + (float(SizePlatform) / (GRID_SIZE * 2.0f)), -1.0f);
    glVertex2f(this->x - (float(SizePlatform) / (GRID_SIZE * 2.0f)), -1.0f);
    glEnd();
}
