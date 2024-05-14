#include "Battlefield.hpp"
#include "RenderText.hpp"
Battlefield::Battlefield() {
    platform = new Platform();
    balls.push_back(new Ball());
    grid = new Grid;
    score = 0;
}

void Battlefield::newIterationBattlefield(){
    this->grid->drawGrid();
    this->platform->drawPlatform();
    for (auto& ball : balls) {
        if (ball != nullptr){
            ball->drawBall();
            collisionPlatform(ball);
            collisionGrid(ball);
            ball->moveBall();
            if(ball->GetY() < -1.1){
                delete ball;
                ball = nullptr;
            }
        }
    }

    for (auto& bonus : bonuses){
        if (bonus != nullptr){
            bonus->drawBonus();
            bonus->moveBonus();
            if (collisionBonus(bonus)){
                bonus->useBonus(balls);
                delete bonus;
                bonus = nullptr;
            }
        }
    }
    for (int i = 0; i < balls.size(); i++) {
        for (int j = i + 1; j < balls.size(); j++) {
            if (balls[i] != nullptr && balls[j] != nullptr)
                collisionBall(balls[i],balls[j]);
        }
    }
    drawScore();
}
void Battlefield::drawScore(){
    char text[10];
    snprintf(text, sizeof(text), "%d", score);
    print_string(0.01f, -0.95f, -0.95f, text, 0.95f, 0.95f, 0.95f);
}

void Battlefield::MovePlatform(const float dx) {
    this->platform->movePlatform(dx);
}

void Battlefield::collisionPlatform(Ball* ball){
    float platformX = platform->getX();
    int SizePlarform = platform->getSizePlatform();
    float x1 = platformX - (float(SizePlarform) / (GRID_SIZE * 2.0f));
    float x2 = platformX + (float(SizePlarform) / (GRID_SIZE * 2.0f));
    float y1 = -1.0f + 1.0f/ GRID_SIZE;
    float y2 = -1.0f;
    if( ball->checkingTouchLine(x1,y1,x2,y1)){
        ball->SetAngle( PI - ball->GetAngle() - (platformX - ball->GetX())/2); 
        ball->moveBall();
    }  
}

void Battlefield::collisionGrid(Ball* ball){
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if ( grid->getGrid(i,j) != nullptr && checkingGrid(i, j, ball)){ 
                this->score += 1;
                if (grid->deleteSquare(i,j)){
                    int randomBonus = rand() % 4;
                    if (randomBonus == 0)
                        bonuses.push_back(new AddBallBonus(i, j));
                    else if (randomBonus == 1)
                        bonuses.push_back(new SpeedUpBonus(i, j));
                    else if (randomBonus == 2)
                        bonuses.push_back(new ExtraLifeBonus(i, j));
                }
                ball->moveBall();
            }
        }
    }
}

bool Battlefield::checkingGrid(int row, int col, Ball* ball){
    float x1 = -1.0f + 2.0f * (col) / GRID_SIZE;
    float x2 = -1.0f + 2.0f * (col+1) / GRID_SIZE;
    float y1 = 1.0f - 2.0f * (row) / GRID_SIZE;
    float y2 = 1.0f - 2.0f * (row+1) / GRID_SIZE;
    bool top = ball->checkingTouchLine(x1, y2, x2, y2);
    bool low = ball->checkingTouchLine(x1, y1, x2, y1);
    bool left = ball->checkingTouchLine(x1, y1, x1, y2);
    bool right = ball->checkingTouchLine(x2, y1, x2, y2);
    if (top || low){
        ball->SetAngle(PI - ball->GetAngle()); 
        return true;
    }else if (left || right){
        ball->SetAngle(2* PI - ball->GetAngle()); 
        return true;
    }
    return false;
}

bool Battlefield::collisionBonus(Bonus* bonus) {
    float platformX = platform->getX();
    int Sizeplatform = platform->getSizePlatform();
    if (std::abs(platformX - bonus->GetX()) <= (Sizeplatform + BONUSRADIUS) && std::abs(bonus->GetY() + 1) <= BONUSRADIUS) {
        return true;
    }
    return false;
}
void Battlefield::collisionBall(Ball* ball1, Ball* ball2){
    float dx = std::abs(ball1->GetX()-ball2->GetX());
    float dy = std::abs(ball1->GetY()-ball2->GetY());
    if(std::sqrt(dx*dx+dy*dy)<2*BALLRADIUS){
        float sumsin = std::sin(ball1->GetAngle()) + std::sin(ball2->GetAngle());
        float sumcos = std::cos(ball1->GetAngle()) + std::cos(ball2->GetAngle());
        float atg= std::atan(sumsin/sumcos);
        float sumsqrt = std::sqrt(sumsin*sumsin + sumcos*sumcos)/2;
        ball1->SetAngle(atg+sumsqrt);
        ball2->SetAngle(atg-sumsqrt);
        ball1->moveBall();
        ball1->moveBall();
    }
}
Battlefield::~Battlefield() {
    delete grid;
    delete platform;
    for (auto& ball : balls) {
        delete ball;
    }
    for (auto& bonus : bonuses) {
        delete bonus;
    }
}
