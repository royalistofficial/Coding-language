#include "const.hpp"

class Ball {
public:
    void drawBall(){
        draw();
    }
    void moveBall(){
        this->x += speed*sin(this->angle);
        this->y += speed*cos(this->angle);

        if(this->x > 1)
            x -=  5.0f/ GRID_SIZE;
        else if(this->x < -1)
            x +=  5.0f/ GRID_SIZE;
        else if(this->y > 1)
            y -=  5.0f/ GRID_SIZE;
    }

    void collision(Plarform** plarform){
        float platformX = (*plarform)->getX();
        int SizePlarform = (*plarform)->getSizePlarform();
        if( checkingPlarform(platformX, SizePlarform)){
            angle = 3.14f - angle - (platformX - this->x)/2; 
            }            
    }

    void collision(Grid** grid, std::vector<Bonus*>& bonuses){
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if ( (*grid)->getGrid(i,j) != nullptr && checkingGrid(i, j)){ 
                    (*grid)->deleteSquare(i,j, bonuses);
                    moveBall();
                }
            }
        }
    }

private:
    float x = 0.0f;
    float y = -0.75f;
    float angle = 3.14f;
    float radius = 0.015f;
    float speed = 0.01f;

    void draw(){
        const int num_segments = 16;
        glColor3f(1.0f, 1.0f, 1.0f); 
        glLineWidth(1.0f);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < num_segments; i++) {
            float theta = 2.0f * 3.14f * float(i) / float(num_segments);
            glVertex2f(this->x + this->radius * cos(theta), this->y + this->radius * sin(theta));
        }
        glEnd();
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
        bool top = checkingTouchLine(x1, y2, x2, y2);
        bool low = checkingTouchLine(x1, y1, x2, y1);
        bool left = checkingTouchLine(x1, y1, x1, y2);
        bool right = checkingTouchLine(x2, y1, x2, y2);
        // if (top && left){
        //     angle = 3.14f - 2 * angle; 
        //     return true;
        // }else if (top && right){
        //     angle = 3.14f - 2 * angle; 
        //     return true;
        // }else if (low && left ){
        //     angle =  3.14f - 2 * angle; 
        //     return true;
        // }else if (low && right){
        //     angle = 3.14f - 2 * angle; 
        //     return true;
        // }else 
        if (top || low){
            angle = 3.14f - angle; 
            return true;
        }else if (left || right){
            angle = 2* 3.14f - angle; 
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
