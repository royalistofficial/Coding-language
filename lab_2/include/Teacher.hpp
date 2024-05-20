#pragma once
#include <const.hpp>
#include "Human.hpp"
#include "Student.hpp"

class Teacher : public Human {
private:
    void CraftSolutionVector(const std::vector<std::string*>& inputVector);

public:
    Teacher(const std::vector<std::string*>& inputVector);
    void teach(Student* student);
};