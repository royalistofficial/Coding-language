#include "Student.hpp"

void Student::setResult(float newResult) {
    result = newResult;
}

std::string Student::getResult() {
    return "Ученик по имени " + name + " написал на " + std::to_string(result);
}

std::vector<std::vector<double>*> Student::getSolution(){
    return solutionVector;
}

Student::Student(const std::string& studentName) : name(studentName) {}

void Student::study(const std::vector<std::string*>& inputVector) {
    std::cout << "Student " << name << " is studying." << std::endl;
}


GoodStudent::GoodStudent(const std::string& studentName) : Student(studentName) {}

void GoodStudent::study(const std::vector<std::string*>& inputVector) {
    this->read_file(inputVector);
    for(const auto& Coeff : CoefficientsVector){
        std::vector<double>* ptr = new std::vector<double>(solution(*Coeff));
        solutionVector.push_back(ptr);
    }
}

NormalStudent::NormalStudent(const std::string& studentName) : Student(studentName) {}

void NormalStudent::study(const std::vector<std::string*>& inputVector) {
    this->read_file(inputVector);
    for(const auto& Coeff : CoefficientsVector){
        std::vector<double>* ptr ; 
        if (std::rand() % 100 < 55){
            ptr = new std::vector<double>(solution(*Coeff));
        }else{
            ptr = new std::vector<double>({0, 0});
        }
        solutionVector.push_back(ptr);
    }
}

BadStudent::BadStudent(const std::string& studentName) : Student(studentName) {}

void BadStudent::study(const std::vector<std::string*>& inputVector) {
    this->read_file(inputVector);
    for(const auto& Coeff : CoefficientsVector){
        std::vector<double>* ptr = new std::vector<double>({0, 0});
        solutionVector.push_back(ptr);
    }
}