#include <iostream>
#include <cstdlib>
#include <fstream>

int randomInt(const int min, const int max) {
    int randNum = min + std::rand() % (max - min + 1);
    if (randNum != 0){
        return randNum;
    }else{
        return randomInt(min, max);
    }
}

void gettingСoefficient(int & a, int & b,int & c){
    //(k1 * x - k2)(k3 * x - k4) = 0
    //k1*k3 x**2 - (k1 * k4 + k3 * k2)*x + k2 * k4 = 0
    int k1 = randomInt(-10, 10); 
    int k2 = randomInt(-10, 10); 
    int k3 = randomInt(-10, 10); 
    int k4 = randomInt(-10, 10); 

    a = k1 * k3;
    b = -(k1 * k4 + k3 * k2);
    c = k2 * k4;
}

int main() {
    std::ofstream file("input.txt");

    if (file.is_open()) {        
        const int numEquations = 100000; 

        for (int i = 0; i < numEquations; ++i) {
            
            int a, b, c;
            gettingСoefficient(a, b, c);

            if (a >= 0) {
               file << a << " * x^2 ";
            } else {
                file << "-" << -a << " * x^2 ";
            }

            if (b >= 0) {
                file << " + " << b << " * x ";
            } else {
                file << " - " << -b << " * x ";
            }
            if (c >= 0) {
                file << " + " << c;
            } else {
                file << " - " << -c;
            }
            file << " = 0\n";
        }
        
        file.close();
    } else {
    }

    return 0;
}
