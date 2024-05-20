#pragma once
#include <const.hpp>
#include <Coefficients.hpp>

class Human {
public:
    ~Human();
protected:
    std::vector<Coefficients*> CoefficientsVector;
    std::vector<std::vector<double>*> solutionVector;

    std::vector<double> solution(Coefficients const coeffs);
    Coefficients read(const std::string& line);
    void read_file(const std::vector<std::string*>& inputVector);
};