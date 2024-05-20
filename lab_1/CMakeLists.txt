cmake_minimum_required(VERSION 3.22)
project(lab1)


# Добавление исполняемого файла
add_executable(lab1
    src/main.cpp
    src/Equation.cpp
    src/Input.cpp
)

# Добавляем папку с заголовочными файлами
target_include_directories(lab1 PRIVATE include)
