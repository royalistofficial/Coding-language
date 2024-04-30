#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <time.h>

const int WIDTH = 600;
const int HEIGHT = 600;
const int GRID_SIZE = 10; // размер сетки (GRID_SIZExGRID_SIZE квадратов)
const float SQUARE_SIZE = WIDTH / GRID_SIZE; // размер каждого квадрата

// Цвета квадратов
const std::vector<std::vector<float>> COLORS = {
    {0.0f, 0.0f, 0.0f}, // черный
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
			drawSquare(i, j, COLORS[grid[i][j]][0], COLORS[grid[i][j]][1], COLORS[grid[i][j]][2]);
        }
    }
}

bool checkSequence(int row, int col) {
   // Проверка горизонтальных линий
    int sequenceLength = 0;
    for (int i = row - 2; i <= row + 2; i++) {
        if (i >= 0 && i < GRID_SIZE && abs(grid[i][col]) == abs(grid[row][col]) && grid[row][col] > 0) {
            sequenceLength++;
            if (sequenceLength >= 3) return true;
        } else {
            sequenceLength = 0;
        }
    }

    // Проверка вертикальных линий
    sequenceLength = 0;
    for (int j = col - 2; j <= col + 2; j++) {
        if (j >= 0 && j < GRID_SIZE && abs(grid[row][j]) == abs(grid[row][col]) && grid[row][col] > 0) {
            sequenceLength++;
            if (sequenceLength >= 3) return true;
        } else {
            sequenceLength = 0;
        }
    }

    return false;
}

void destroySequence() {
    bool sequenceFound = true;
    while (sequenceFound) {
        sequenceFound = false;
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if (checkSequence(i, j)) {
                    grid[i][j] = -grid[i][j];
                    sequenceFound = true;
                }
            }
        }
    }

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] < 0){
                grid[i][j] = 0;
            }
        }
    }
}

void blackBlockUp(){
    bool sequenceBlack = true;
    while (sequenceBlack) {
        sequenceBlack = false;
        for (int i = 1; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if (grid[i][j] == 0 && grid[i-1][j] != 0){
                    sequenceBlack = true;
                    std::swap(grid[i][j], grid[i-1][j]);
                }
            }
        }
    }
}

void cleanBlackkBloc(){
    bool sequenceBlack = true;
    blackBlockUp();
    // drawGrid();
    // sleep(1);
    while (sequenceBlack) {
        sequenceBlack = false;
        for (int i = 0; i < GRID_SIZE; i++) {
            if (grid[0][i] == 0){
                sequenceBlack = true;    
                grid[0][i] = 1 + rand() % (COLORS.size() - 1);
            }           
        }
    }
}

int prevRow = -1, prevCol = -1;

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        int row = static_cast<int>(ypos / SQUARE_SIZE);
        int col = static_cast<int>(xpos / SQUARE_SIZE);

        if ((prevRow != -1 && prevCol != -1) && (abs(prevRow-row) <= 1 && abs(prevCol - col) <= 1)) {
            // свап ячеек
            std::swap(grid[prevRow][prevCol], grid[row][col]);
            prevRow = -1;
            prevCol = -1;
        }else{
            prevRow = row;
            prevCol = col;
        }
    }
}


int main() {
    
    srand(static_cast<unsigned int>(time(0)));

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
