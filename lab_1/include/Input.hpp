#pragma once
#include <const.hpp>
#include <Equation.hpp>

class Input {
public:
    static double getRoot(char const name);
    static Equation getEquation();
};