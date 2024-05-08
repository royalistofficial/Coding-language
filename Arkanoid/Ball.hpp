#include "const.hpp"
class Ball {
public:
    void drawBall(){
        draw();
    }
    void moveBall(){
        move();
    }

    void collision(Plarform* plarform){

    }

    void collision(Grid* grid){

    }

private:
    float x = 0.0f;
    float y = -0.75f;
    float angle = 3.14f;
    const float radius = 0.02f;
    const float speed = 0.01f;

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
};
