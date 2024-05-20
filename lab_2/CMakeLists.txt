cmake_minimum_required(VERSION 3.22)
project(lab2)

# Добавление исполняемого файла "craft"
add_executable(craft
    src/craft.cpp
)

# Добавление исполняемого файла "lab1"
add_executable(lab2
    src/main.cpp
    src/Human.cpp
    src/Student.cpp
    src/Teacher.cpp
    src/readFile.cpp
)

# Добавление папки с заголовочными файлами 
target_include_directories(lab2 PRIVATE include)
