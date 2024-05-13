#include "Ball.hpp"

int Ball::extraLife;

Ball::Ball() {
    x = 0.0f + 0.1f*(1-2*float(rand()%100)/100);
    y = -0.5f + 0.05f*(1-2*float(rand()%100)/100);
    angle = PI + 0.1f*(1-2*float(rand()%100)/100);
    speed = MINSPEEDBALL;
    numSleepSpeed = -1;
    extraLife = 0;
}

void Ball::drawBall(){
    draw();
}

void Ball::moveBall(){
    this->x += speed*sin(this->angle);
    this->y += speed*cos(this->angle);

    if(this->x > 1)
        x -=  7.5f/ GRID_SIZE;
    else if(this->x < -1)
        x +=  7.5f/ GRID_SIZE;
    else if(this->y > 1)
        y -=  7.5f/ GRID_SIZE;
    else if((this->y < -1) && (extraLife > 0)){
        this->angle = PI - this->angle;
        --extraLife;
    }

    if(numSleepSpeed != -1){
        if (numSleepSpeed == 0)
            this->speed = MINSPEEDBALL;

        numSleepSpeed--;
    }
}

void Ball::SpeedUp(){
    this->speed=MAXSPEEDBALL;
    this->numSleepSpeed = NUMSLEEPSPEED;
}


void Ball::draw(){
    const int num_segments = 16;
    glColor3f(1.0f, 1.0f, 1.0f); 
    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * PI * float(i) / float(num_segments);
        glVertex2f(this->x + BALLRADIUS * cos(theta), this->y + BALLRADIUS * sin(theta));
    }
    glEnd();
}


bool Ball::checkingTouchLine(float x1, float y1, float x2, float y2){
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
    return distance <= BALLRADIUS;
}

float Ball::GetX(){
    return x;
}
float Ball::GetY(){
    return y;
}

float Ball::GetAngle(){
    return angle;
}
void Ball::SetExtraLife(){
    ++extraLife;
}
void Ball::SetAngle(float angle){
    this->angle = angle;
}