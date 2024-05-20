#pragma once
#include "const.hpp"

class Platform {
public:
    Platform();
    void drawPlatform();
    void movePlatform(float dx);
    float getX();
    int getSizePlatform();

private:
    float x;
    int SizePlatform;
    void draw();
};


