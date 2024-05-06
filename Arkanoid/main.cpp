#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

const int WIDTH = 600;
const int HEIGHT = 600;
const int GRID_SIZE = 100; // размер сетки (GRID_SIZExGRID_SIZE квадратов)
const float SQUARE_SIZE = WIDTH / GRID_SIZE; // размер каждого квадрата

// Цвета квадратов
const std::vector<std::vector<float>> COLORS = {
    {0.0f, 0.0f, 0.0f}, // черный
    {1.0f, 0.0f, 0.0f}, // красный
    {0.0f, 1.0f, 0.0f}, // зеленый
    {0.0f, 0.0f, 1.0f}, // синий
    {1.0f, 1.0f, 0.0f}, // желтый
    {1.0f, 0.0f, 1.0f}, // фиолетовый
    {0.0f, 1.0f, 1.0f},  // голубой
    {0.5f, 0.5f, 0.5f}, // серый
    {0.75f, 0.25f, 0.0f}, // оранжевый
    {0.0f, 0.5f, 0.5f}, // бирюзовый
    {0.5f, 0.0f, 0.5f}, // пурпурный
    {0.25f, 0.75f, 0.0f}, // салатовый
    {0.75f, 0.75f, 0.75f}, // светло-серый
    {0.25f, 0.25f, 0.25f}, // темно-серый
    {0.9f, 0.9f, 0.9f}, // почти белый
    {0.6f, 0.2f, 0.8f}, // малиновый
    {0.4f, 0.6f, 0.2f}, // оливковый
};

struct Square {
    std::vector<float> color;  // цвет квадрата
    float destructibility;     // разрушаемость квадрата

    Square(const std::vector<float>& color, float destructibility)
        : color(color), destructibility(destructibility) {}
};

std::vector<std::vector<Square>> grid(GRID_SIZE, std::vector<Square>(GRID_SIZE));


void drawSquare(int row, int col, Square square) {

    float r = square.color[0];
    float g = square.color[1];
    float b = square.color[2];
	const float border_width = 5.0f; // Ширина границы

    // Нарисовать границу
    glColor3f(0.0f, 0.0f, 0.0f); // Черный цвет
    glLineWidth(border_width); // Толщина линии
    glBegin(GL_LINE_LOOP);
    glVertex2f(-1.0f + 2.0f * (col) / GRID_SIZE, 1.0f - 2.0f * (row) / GRID_SIZE);
    glVertex2f(-1.0f + 2.0f * (col+1) / GRID_SIZE, 1.0f - 2.0f * (row) / GRID_SIZE);
    glVertex2f(-1.0f + 2.0f * (col+1) / GRID_SIZE, 1.0f - 2.0f * (row+1) / GRID_SIZE);
    glVertex2f(-1.0f + 2.0f * (col) / GRID_SIZE, 1.0f - 2.0f * (row+1) / GRID_SIZE);
    glEnd();

    // Нарисовать внутреннюю часть квадрата
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f + 2.0f * (col) / GRID_SIZE, 1.0f - 2.0f * (row) / GRID_SIZE);
    glVertex2f(-1.0f + 2.0f * (col+1) / GRID_SIZE, 1.0f - 2.0f * (row) / GRID_SIZE);
    glVertex2f(-1.0f + 2.0f * (col+1) / GRID_SIZE, 1.0f - 2.0f * (row+1) / GRID_SIZE);
    glVertex2f(-1.0f + 2.0f * (col) / GRID_SIZE, 1.0f - 2.0f * (row+1) / GRID_SIZE);
    glEnd();
}

void drawGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
			drawSquare(i, j, grid[i][j]);
        }
    }
}


int main() {
    
    srand(static_cast<unsigned int>(time(0)));

    // Заполнение сетки случайными значениями
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i < 50)
                grid[i][j] = Square(COLORS[1 + rand() % (COLORS.size() - 1)], true);
            else
                grid[i][j] = Square(COLORS[0], true);
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
    // glfwSetMouseButtonCallback(window, mouse_button_callback);

    while (!glfwWindowShouldClose(window)) {

        glClear(GL_COLOR_BUFFER_BIT);

        drawGrid();


        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
