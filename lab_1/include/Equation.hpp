#pragma once
#include <const.hpp>

class Equation {
private:
    double a, b, c;

public:
    Equation(double a, double b, double c);
    void getRoots();
};
