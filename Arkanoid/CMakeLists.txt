cmake_minimum_required(VERSION 3.22)
project(Game)

set(STB_SOURCES
    stb-master/stb_vorbis.c
)

add_executable(Game
    src/main.cpp
    src/Battlefield.cpp
    src/Grid.cpp
    src/Platform.cpp
    src/Ball.cpp
    src/Bonus.cpp
    src/RenderText.cpp
)

target_include_directories(Game PRIVATE include)
target_include_directories(Game PRIVATE stb-master)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(Game glfw)
target_link_libraries(Game OpenGL::GL)
