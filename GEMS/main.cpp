#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int WIDTH = 600;
const int HEIGHT = 600;
const int GRID_SIZE = 10; // размер сетки (GRID_SIZExGRID_SIZE квадратов)
const float SQUARE_SIZE = WIDTH / GRID_SIZE; // размер каждого квадрата

// Цвета квадратов
const std::vector<std::vector<float>> COLORS = {
    {1.0f, 0.0f, 0.0f}, // красный
    {0.0f, 1.0f, 0.0f}, // зеленый
    {0.0f, 0.0f, 1.0f}, // синий
    {1.0f, 1.0f, 0.0f}, // желтый
    {1.0f, 0.0f, 1.0f}, // фиолетовый
    {0.0f, 1.0f, 1.0f}  // голубой
};

std::vector<std::vector<int>> grid(GRID_SIZE, std::vector<int>(GRID_SIZE));

void drawSquare(int row, int col, float r, float g, float b) {
	const float border_width = 5.0f; // Ширина границы

    // Нарисовать границу
    glColor3f(0.0f, 0.0f, 0.0f); // Черный цвет
    glLineWidth(border_width); // Толщина линии
    glBegin(GL_LINE_LOOP);
    glVertex2f(1.0f - 2.0f * (col) / GRID_SIZE, 1.0f - 2.0f * (row) / GRID_SIZE);
    glVertex2f(1.0f - 2.0f * (col+1) / GRID_SIZE, 1.0f - 2.0f * (row) / GRID_SIZE);
    glVertex2f(1.0f - 2.0f * (col+1) / GRID_SIZE, 1.0f - 2.0f * (row+1) / GRID_SIZE);
    glVertex2f(1.0f - 2.0f * (col) / GRID_SIZE, 1.0f - 2.0f * (row+1) / GRID_SIZE);
    glEnd();

    // Нарисовать внутреннюю часть квадрата
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(1.0f - 2.0f * (col) / GRID_SIZE, 1.0f - 2.0f * (row) / GRID_SIZE);
    glVertex2f(1.0f - 2.0f * (col+1) / GRID_SIZE, 1.0f - 2.0f * (row) / GRID_SIZE);
    glVertex2f(1.0f - 2.0f * (col+1) / GRID_SIZE, 1.0f - 2.0f * (row+1) / GRID_SIZE);
    glVertex2f(1.0f - 2.0f * (col) / GRID_SIZE, 1.0f - 2.0f * (row+1) / GRID_SIZE);
    glEnd();
}

void drawGrid() {
	std::cout << "in" << std::endl;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
			drawSquare(i, j, COLORS[grid[i][j]][0], COLORS[grid[i][j]][1], COLORS[grid[i][j]][2]);
			// if (grid[i][j] == -1){
			// 	drawSquare(i, j, 0.0f, 0.0f, 0.0f);
			// }else{
			// 	drawSquare(i, j, COLORS[grid[i][j]][0], COLORS[grid[i][j]][1], COLORS[grid[i][j]][2]);
			// }
        }
    }
	std::cout << "out" << std::endl;
}

int main() {
    std::cout << "+" << std::endl;
    srand(static_cast<unsigned int>(time(0)));

    // Заполнение сетки случайными значениями
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = rand() % COLORS.size();
			std::cout << grid[i][j] << std::endl;
        }
    }
	std::cout << "+" << std::endl;
    // Добавление пустых ячеек внизу сетки
    // for (int j = 0; j < GRID_SIZE; ++j) {
    //     for (int i = 0; i < GRID_SIZE / 2; ++i) {
    //         grid[i][j] = -1;
    //     }
    // }
	std::cout << "+" << std::endl;
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(WIDTH, HEIGHT, "game", NULL, NULL);
	// glViewport(0, 0, GRID_SIZE, GRID_SIZE);
    if (!window) {
        glfwTerminate();
        return -1;
    }

	std::cout << "+" << std::endl;

    glfwMakeContextCurrent(window);

	std::cout << "+" << std::endl;

    while (!glfwWindowShouldClose(window)) {
		std::cout << "-" << std::endl;
        glClear(GL_COLOR_BUFFER_BIT);
		std::cout << "+" << std::endl;
		// drawSquare(0, 0, 1.0f, 1.0f, 1.0f);
        drawGrid();
		std::cout << "+" << std::endl;
        glfwSwapBuffers(window);
		std::cout << "+" << std::endl;
        glfwPollEvents();
		std::cout << "-" << std::endl;
    }

	std::cout << "-" << std::endl;

    glfwTerminate();
    return 0;
}
