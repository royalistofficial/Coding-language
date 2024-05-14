#include <const.hpp>
#include <bonus.hpp>
#include <draw.hpp>
#include <changesGrid.hpp>
#include <moveSquare.hpp>

std::vector<std::vector<int>> grid(GRID_SIZE, std::vector<int>(GRID_SIZE));

int main() {
    
    // Заполнение сетки случайными значениями
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = 1 + rand() % (COLORS.size() - 1);
        }
    }
	
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(WIDTH, HEIGHT, "game", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetMouseButtonCallback(window, mouse_button_callback);


    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        drawGrid();
        destroySequence();
        cleanBlackkBloc();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
