#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

struct Coefficients {
    int a;
    int b;
    int c;
    Coefficients() : a(0), b(0), c(0) {}
};
class Human {
protected:
    std::vector<Coefficients*> CoefficientsVector;
    std::vector<std::vector<double>*> solutionVector;
    //  Правильное решение
    std::vector<double> solution(Coefficients const coeffs) {
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
    // чтение строки
    Coefficients read(const std::string& line) {
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

    // чтение файла
    void read_file(const std::vector<std::string*>& inputVector){
        for (const auto& strPtr : inputVector) {
            if (strPtr) {
                Coefficients coeffs = this->read(*strPtr);
                Coefficients* ptr = new Coefficients(coeffs);
                this->CoefficientsVector.push_back(ptr);
            }
        }
    }
public:
    // Деструктор класса
    ~Human() {
        // std::cout << "Human delete" << std::endl;
        for (const auto& Coeff : this->CoefficientsVector) {
            delete Coeff;
        }
        for (const auto& sol : this->solutionVector) {
            delete sol;
        }
    }

};
class Student : public Human{
protected:
    std::string name;
    float result;
public:
    void setResult(float newResult) {
        result = newResult;
    }
    std::string getResult() {
        return "Ученик по имени " + name + " написал на " + std::to_string(result);
    }
    std::vector<std::vector<double>*> getSolution(){
        return solutionVector;
    } 
    // Конструктор класса
    Student(const std::string& studentName) : name(studentName){
    }

    // Виртуальная функция для учебы
    virtual void study(const std::vector<std::string*>& inputVector) {
        std::cout << "Student " << name << " is studying." << std::endl;
    }
};

class GoodStudent : public Student {
public:
    // Конструктор класса
    GoodStudent(const std::string& studentName) : Student(studentName) {}

    // Переопределение виртуальной функции study для хорошего студента
    virtual void study(const std::vector<std::string*>& inputVector) override {
        // std::cout << "Good student " << name << " is studying." << std::endl;
        this->read_file(inputVector);
        for(const auto& Coeff : this->CoefficientsVector){
            std::vector<double>* ptr = new std::vector<double>(solution(*Coeff));
            solutionVector.push_back(ptr);
        }
    }
};

class NormalStudent : public Student {
public:
    // Конструктор класса
    NormalStudent(const std::string& studentName) : Student(studentName) {}

    // Переопределение виртуальной функции study для нормального студента
    virtual void study(const std::vector<std::string*>& inputVector) override {
        // std::cout << "Normal student " << name << " is studying." << std::endl;
        this->read_file(inputVector);
        for(const auto& Coeff : this->CoefficientsVector){
            std::vector<double>* ptr ; 
            if (std::rand() % 100 < 55){
                ptr = new std::vector<double>(solution(*Coeff));
            }else{
                ptr = new std::vector<double>({0, 0});
            }
            solutionVector.push_back(ptr);
        }
    }
};

class BadStudent : public Student {
public:
    // Конструктор класса
    BadStudent(const std::string& studentName) : Student(studentName) {}

    // Переопределение виртуальной функции study для плохого студента
    virtual void study(const std::vector<std::string*>& inputVector) override {
        // std::cout << "Bad student " << name << " is studying." << std::endl;
        this->read_file(inputVector);
        for(const auto& Coeff : this->CoefficientsVector){
            std::vector<double>* ptr = new std::vector<double>({0, 0});
            solutionVector.push_back(ptr);
        }
    }
};

class Teacher : public Human{
private:
    void CraftSolutionVector(const std::vector<std::string*>& inputVector) {
        this->read_file(inputVector);
        for(const auto& Coeff : this->CoefficientsVector){
            std::vector<double>* ptr = new std::vector<double>(solution(*Coeff));
            solutionVector.push_back(ptr);
        }
    }
public:
    Teacher(const std::vector<std::string*>& inputVector) {
        this->CraftSolutionVector(inputVector);
    }

    void teach(Student* student) {
        std::vector<std::vector<double>*> solutionVector = student->getSolution();
        if (solutionVector.size() != this->solutionVector.size()) {
            return;
        }

        int numSimilar = 0;
        const double eps = 0.001;

        for (int i = 0; i < solutionVector.size(); i++) {
            const std::vector<double>* vec1 = solutionVector[i];
            const std::vector<double>* vec2 = this->solutionVector[i];

            bool similar = true;

            if (vec1->size() != vec2->size()) {
                similar = false; // Вложенные векторы имеют разную длину, не совпадают
            }

            for (int j = 0; j < vec1->size(); j++) {
                if (std::abs((*vec1)[j] - (*vec2)[j]) > eps) {
                    similar = false;
                    break;
                }
            }

            if (similar) {
                numSimilar++;
            }
        }

        float result = (static_cast<float>(numSimilar) / solutionVector.size()) * 100.0f;
        student->setResult(result);
    }
};


#endif // STUDENT_H
