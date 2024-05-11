cmake_minimum_required(VERSION 3.22)
project(Game)


# Добавление исполняемого файла
add_executable(Game
    src/main.cpp
    src/bonus.cpp
    src/draw.cpp
    src/changesGrid.cpp
    src/moveSquare.cpp
)

# Добавляем папку с заголовочными файлами
target_include_directories(Game PRIVATE include)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(Game glfw)
target_link_libraries(Game OpenGL::GL)
