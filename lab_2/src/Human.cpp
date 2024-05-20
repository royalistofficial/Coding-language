#include "Human.hpp"

std::vector<double> Human::solution(Coefficients const coeffs) {
    double D = coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c;
    std::vector<double> roots;

    if (D > 0) {
        double x1 = (-coeffs.b + sqrt(D)) / (2 * coeffs.a);
        double x2 = (-coeffs.b - sqrt(D)) / (2 * coeffs.a);
        roots.push_back(x1);
        roots.push_back(x2);
    } else if (D == 0) {
        double x = -coeffs.b / (2 * coeffs.a);
        roots.push_back(x);
    }
    return roots;
}

Coefficients Human::read(const std::string& line) {
    Coefficients coeffs;
    int a, b, c;
    char signB, signC;

    sscanf(line.c_str(), "%d * x^2 %c %d * x %c %d", &a, &signB, &b, &signC, &c);
    if (signB == '-') { b = -b; }
    if (signC == '-') { c = -c; }

    coeffs.a = a;
    coeffs.b = b;
    coeffs.c = c;

    return coeffs;
}

void Human::read_file(const std::vector<std::string*>& inputVector){
    for (const auto& strPtr : inputVector) {
        if (strPtr) {
            Coefficients coeffs = this->read(*strPtr);
            Coefficients* ptr = new Coefficients(coeffs);
            CoefficientsVector.push_back(ptr);
        }
    }
}

Human::~Human() {
    for (const auto& Coeff : CoefficientsVector) {
        delete Coeff;
    }
    for (const auto& sol : solutionVector) {
        delete sol;
    }
}