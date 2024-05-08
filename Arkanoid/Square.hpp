struct Square {
    float colorR;
    float colorG;
    float colorB;  // цвет квадрата
    bool destructibility;     // разрушаемость квадрата

    Square(float r, float g, float b, bool destructibility) {
        this->colorR = r;
        this->colorG = g;
        this->colorB = b;
        this->destructibility = destructibility;
    }
};
