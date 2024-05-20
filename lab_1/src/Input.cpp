#include <Input.hpp>

double Input::getRoot(char const name) {
    double root;
    while (true) {
        std::cout << "Введите коэффициент - " << name << ":" << std::endl;
        if (std::cin >> root) {
            return root;
        } else {
            std::cout << "Вы ввели коэффициент" << name << "с ошибкой" << std::endl;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

Equation Input::getEquation() {
    double a = getRoot('a');
    double b = getRoot('b');
    double c = getRoot('c');

    if (a == 0 && b == 0) {
        std::cout << "Уравнение не имеет смысла" << std::endl;
        return getEquation();
    }

    return Equation(a, b, c);
}