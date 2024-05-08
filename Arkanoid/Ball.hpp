#include "const.hpp"
class Ball {
public:
    void drawBall(){
        draw();
    }
    void moveBall(){
        move();
    }

    void collision(Plarform** plarform){
        float platformX = (*plarform)->getX();
        int SizePlarform = (*plarform)->getSizePlarform();
        if( checkingPlarform(platformX, SizePlarform)){
            angle += 3.14f - (platformX - this->x)/2; 
            move(); 
            }            
    }

    void collision(Grid** grid){
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if ( (*grid)->getGrid(i,j) != nullptr && checkingGrid(i, j)){
                    move(); 
                    (*grid)->deleteSquare(i,j);
                    return;
                }
            }
        }
    }

private:
    float x = 0.0f;
    float y = -0.75f;
    float angle = 3.14f;
    const float radius = 0.02f;
    const float speed = 0.03f;

    void draw(){
        int num_segments = 16;
        glColor3f(1.0f, 1.0f, 1.0f); 
        glLineWidth(1.0f);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < num_segments; i++) {
            float theta = 2.0f * 3.14f * float(i) / float(num_segments);
            glVertex2f(this->x + this->radius * cos(theta), this->y + this->radius * sin(theta));
        }
        glEnd();
    }
    void move(){
        this->x += speed*sin(this->angle);
        this->y += speed*cos(this->angle);
    }
    bool checkingPlarform(float platformX, int SizePlarform){
        float x1 = platformX - (float(SizePlarform) / (GRID_SIZE * 2.0f));
        float x2 = platformX + (float(SizePlarform) / (GRID_SIZE * 2.0f));
        float y1 = -1.0f + 1.0f/ GRID_SIZE;
        float y2 = -1.0f;
        return checkingTouchLine(x1, y1, x2, y2);
    }

    bool checkingGrid(int row, int col){
        float x1 = -1.0f + 2.0f * (col) / GRID_SIZE;
        float x2 = -1.0f + 2.0f * (col+1) / GRID_SIZE;
        float y1 = 1.0f - 2.0f * (row) / GRID_SIZE;
        float y2 = 1.0f - 2.0f * (row+1) / GRID_SIZE;
        if (checkingTouchLine(x1, y1, x2, y1) || checkingTouchLine(x1, y2, x2, y2)){
            angle += 3.14f; 
            return true;
        }else if (checkingTouchLine(x1, y1, x1, y2) || checkingTouchLine(x2, y1, x2, y2)){
            angle += 3.14f/2; 
            return true;
        }
        return false;
    }

    bool checkingTouchLine(float x1, float y1, float x2, float y2){
        float dx = x2 - x1;
        float dy = y2 - y1;
        float t = ((this->x - x1) * dx + (this->y - y1) * dy) / (dx * dx + dy * dy);
        if (t < 0) {
            t = 0;
        } else if (t > 1) {
            t = 1;
        }
        float closestX = x1 + t * dx;
        float closestY = y1 + t * dy;
        float distance = sqrt(pow(this->x - closestX, 2) + pow(this->y - closestY, 2));
    return distance <= this->radius;
    }
};
