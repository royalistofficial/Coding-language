#include "Teacher.hpp"

void Teacher::CraftSolutionVector(const std::vector<std::string*>& inputVector) {
    this->read_file(inputVector);
    for(const auto& Coeff : CoefficientsVector){
        std::vector<double>* ptr = new std::vector<double>(solution(*Coeff));
        solutionVector.push_back(ptr);
    }
}

Teacher::Teacher(const std::vector<std::string*>& inputVector) {
    this->CraftSolutionVector(inputVector);
}

void Teacher::teach(Student* student) {
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
        }else{
            for (int j = 0; j < vec1->size(); j++) {
                if (std::abs((*vec1)[j] - (*vec2)[j]) > eps) {
                    similar = false;
                    break;
                }
            }
        }

        if (similar) {
            numSimilar++;
        }
    }

    float result = (static_cast<float>(numSimilar) / solutionVector.size()) * 100.0f;
    student->setResult(result);
}
