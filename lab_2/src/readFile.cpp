#include <readFile.hpp>


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