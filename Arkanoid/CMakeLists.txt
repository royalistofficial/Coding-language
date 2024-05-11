cmake_minimum_required(VERSION 3.0)
project(Arkanoid)

# Установка стандарта языка программирования
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавление исполняемого файла
add_executable(game
    src/main.cpp
    src/Ball.cpp
    src/Battlefield.cpp
    src/bonus.cpp
    src/Grid.cpp
    src/Plarform.cpp
)

# Указание пути к заголовочным файлам
target_include_directories(game PUBLIC include)

# Указание библиотек для линковки
target_link_libraries(game glfw GL GLU)
