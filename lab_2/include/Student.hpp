#pragma once
#include <const.hpp>
#include "Human.hpp"

class Student : public Human{
protected:
    std::string name;
    float result;

public:
    void setResult(float newResult);
    std::string getResult();
    std::vector<std::vector<double>*> getSolution();
    Student(const std::string& studentName);
    virtual void study(const std::vector<std::string*>& inputVector) = 0;
};

class GoodStudent : public Student {
public:
    GoodStudent(const std::string& studentName);
    virtual void study(const std::vector<std::string*>& inputVector) override;
};

class NormalStudent : public Student {
public:
    NormalStudent(const std::string& studentName);
    virtual void study(const std::vector<std::string*>& inputVector) override;
};

class BadStudent : public Student {
public:
    BadStudent(const std::string& studentName);
    virtual void study(const std::vector<std::string*>& inputVector) override;
};