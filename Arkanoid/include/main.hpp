#pragma once

#include "Battlefield.hpp"
#include "const.hpp"

extern Battlefield* battlefield;
static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
int main();