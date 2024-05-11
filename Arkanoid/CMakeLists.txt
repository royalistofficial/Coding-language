cmake_minimum_required(VERSION 3.22)
project(Game)

add_executable(Game
    src/main.cpp
    src/Battlefield.cpp
    src/Grid.cpp
    src/Platform.cpp
    # src/Bonus.cpp
)

target_include_directories(Game PRIVATE include)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(Game glfw)
target_link_libraries(Game OpenGL::GL)
