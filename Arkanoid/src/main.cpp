#include "main.hpp"


Battlefield* battlefield = new Battlefield ();
static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // Проверка, была ли нажата клавиша A или D.

    if (key == GLFW_KEY_A)
    {
        if (action == GLFW_PRESS || action == GLFW_REPEAT)
        {
            // Уменьшение значения x при нажатии клавиши A.
            (*battlefield).MovePlatform(-SPEEDPLATFORM);
        }
    }
    else if (key == GLFW_KEY_D)
    {
        if (action == GLFW_PRESS || action == GLFW_REPEAT)
        {
            // Увеличение значения x при нажатии клавиши D.
            (*battlefield).MovePlatform(SPEEDPLATFORM);
        }
    }
}

int main() {
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(WIDTH, HEIGHT, "game", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyCallback);

    while (!glfwWindowShouldClose(window)) {

        glClear(GL_COLOR_BUFFER_BIT);

        (*battlefield).newIterationBattlefield();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    delete battlefield;
    glfwTerminate();
    return 0;
}
