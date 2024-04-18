#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Student.hpp"

std::vector<std::string*> readFile(const std::string& filename) {
    std::ifstream input(filename);
    std::string line;
    std::vector<std::string*> inputVector;

    while (std::getline(input, line)) {
        std::string* ptr = new std::string(line);
        inputVector.push_back(ptr);
        //std::cout << ptr << std::endl;
    }

    input.close();

    return inputVector;
}

int main() {
    std::vector<std::string*> inputVector = readFile("../input.txt");

    std::vector< Student*> StudentList;
    for(int i = 0; i<100; i++){
        int category = rand() % 3;
        std::string result = "Name" + std::to_string(i);
        Student* student = nullptr;
        switch (category) {
            case 0:
                student = new GoodStudent(result);
                break;
            case 1:
                student = new NormalStudent(result);
                break;
            case 2:
                student = new BadStudent(result);
                break;
        }
        StudentList.push_back(student);
    }


    Teacher* teacher = new Teacher(inputVector);
    for (const auto& student : StudentList) {
        student->study(inputVector);
    }

    for (const auto& student : StudentList) {
        teacher->teach(student);
    }
    for (const auto& student : StudentList) {
        std::cout << student->getResult() << std::endl;
    }

    //std::ofstream file("input.txt");
    
    // Освобождаем память, выделенную для студентов
    for (const auto& student : StudentList) {
        delete student;
    }
    delete teacher;
    for (const auto& strPtr : inputVector) {
        delete strPtr;
    }

    return 0;
}
