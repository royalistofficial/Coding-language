#include "const.hpp"

class Plarform{
    public:
    void drawPlarform(){
        draw();
    }
    void MovePlarform(float dx){ 
        if((dx > 0) && (this->x + (float(SizePlarform - 1) / (GRID_SIZE * 2.0f)) < 1))
            this->x += dx;
        else if ((dx < 0) && (this->x - (float(SizePlarform - 1) / (GRID_SIZE * 2.0f)) > -1))
            this->x += dx;
    }

    float getX() {
        return x;
    }
    int getSizePlarform() {
        return SizePlarform;
    }


    private:
    float x = 0;
    int SizePlarform = 50;
    void draw(){
        glColor3f(1.0f,  1.0f,  1.0f);
        glBegin(GL_QUADS);
        glVertex2f(this->x - (float(SizePlarform) / (GRID_SIZE * 2.0f)), -1.0f + 1.0f/ GRID_SIZE);
        glVertex2f(this->x + (float(SizePlarform) / (GRID_SIZE * 2.0f)), -1.0f + 1.0f/ GRID_SIZE);
        glVertex2f(this->x + (float(SizePlarform) / (GRID_SIZE * 2.0f)), -1.0f);
        glVertex2f(this->x - (float(SizePlarform) / (GRID_SIZE * 2.0f)), -1.0f);
        glEnd();

    }
};
