cmake_minimum_required(VERSION 3.0)
project(Arkanoid)

# Установка стандарта языка программирования
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавление исполняемого файла
add_executable(Arkanoid
    src/main.cpp
    src/Ball.cpp
    src/Battlefield.cpp
    src/bonus.cpp
    src/Grid.cpp
    src/Platform.cpp
)

# Включение папки с заголовочными файлами
target_include_directories(Arkanoid PUBLIC include)

# Указание библиотек для линковки
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(Arkanoid glfw)
target_link_libraries(Arkanoid OpenGL::GL)
