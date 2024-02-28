#include <iostream>
#include <cmath>

using namespace std;

double geting_root(char const name){
    double root;
    while (true){
        cout << "Введите коэффициент - " << name << ":" << endl;
        if (cin >> root){
            return root;
        }else{
            cout << "Вы ввели коэффициент" << name << "с ошибкой" << endl;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void geting_roots(double & a, double & b, double & c){
    cout << "Введите коэффициенты a, b, c для уравнения a x**2 + b x + c = 0: " << endl;
    a = geting_root('a');
    b = geting_root('b');
    c = geting_root('c');
    
    if (a == 0 and b == 0){ 
        cout << "Уравнение не имеет смысла" << endl;
        geting_roots(a, b, c);
    }

}

void solution(double const  a, double const  b, double const  c){
    if (a != 0) {
        double D = b * b - 4 * a * c;

        if (D > 0) {
            double x1 = (-b + sqrt(D)) / (2 * a);
            double x2 = (-b - sqrt(D)) / (2 * a);
            cout << "Уравнение имеет два корня: x1 = " << x1 << ", x2 = " << x2 << endl;
        } else if (D == 0) {
            double x = -b / (2 * a);
            cout << "Уравнение имеет один корень: x = " << x << endl;
        } else {
            cout << "Уравнение не имеет действительных корней." << endl;
        }
    } else {
        double x = - c / b;
        cout << "Уравнение имеет один корень: x = " << x << endl;
    }

};


int main() {
    double a, b, c;
    geting_roots(a, b, c);
    solution(a,b,c);
    return 0;
}

