struct Square {
    float colorR;
    float colorG;
    float colorB;  // цвет квадрата
    int destructibility;     // разрушаемость квадрата

    Square(float r, float g, float b, int destructibility) {
        this->colorR = r;
        this->colorG = g;
        this->colorB = b;
        this->destructibility = destructibility;
    }
};
