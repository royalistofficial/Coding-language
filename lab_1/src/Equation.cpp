#include <Equation.hpp>


Equation::Equation(double a, double b, double c) : a(a), b(b), c(c) {}

void Equation::getRoots() {
    if (a != 0) {
        double D = b * b - 4 * a * c;

        if (D > 0) {
            double x1 = (-b + sqrt(D)) / (2 * a);
            double x2 = (-b - sqrt(D)) / (2 * a);
            std::cout << "Уравнение имеет два корня: x1 = " << x1 << ", x2 = " << x2 << std::endl;
        } else if (D == 0) {
            double x = -b / (2 * a);
            std::cout << "Уравнение имеет один корень: x = " << x << std::endl;
        } else {
            std::cout << "Уравнение не имеет действительных корней." << std::endl;
        }
    } else {
        double x = -c / b;
        std::cout << "Уравнение имеет один корень: x = " << x << std::endl;
    }
}