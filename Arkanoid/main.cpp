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
    // {1.0f, 1.0f, 0.0f}, // желтый
    // {1.0f, 0.0f, 1.0f}, // фиолетовый
    // {0.0f, 1.0f, 1.0f},  // голубой
    // {0.5f, 0.5f, 0.5f}, // серый
    // {0.75f, 0.25f, 0.0f}, // оранжевый
    // {0.0f, 0.5f, 0.5f}, // бирюзовый
    // {0.5f, 0.0f, 0.5f}, // пурпурный
    // {0.25f, 0.75f, 0.0f}, // салатовый
    // {0.75f, 0.75f, 0.75f}, // светло-серый
    // {0.25f, 0.25f, 0.25f}, // темно-серый
    // {0.9f, 0.9f, 0.9f}, // почти белый
    // {0.6f, 0.2f, 0.8f}, // малиновый
    // {0.4f, 0.6f, 0.2f}, // оливковый
};

struct Square {
    float colorR;
    float colorG;
    float colorB;  // цвет квадрата
    bool destructibility;     // разрушаемость квадрата

    Square(float r, float g, float b, bool destructibility) {
        this->colorR = r;
        this->colorG = g;
        this->colorB = b;
        this->destructibility = destructibility;
    }
};

class Battlefield {
public:
    Battlefield() {
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                grid[i][j] = nullptr;
            }
        }
        for (int i = 1; i < GRID_SIZE/2; i++) {
            for (int j = 1; j < GRID_SIZE-1; j++) {
                int colorIndex =  1 + rand() % (COLORS.size() - 1);
                grid[i][j] = new Square(COLORS[colorIndex][0], COLORS[colorIndex][1], COLORS[colorIndex][2], true);
            }
        }
        for (int i = 0; i < GRID_SIZE; i++) {
            grid[0][i] = new Square(1.0f, 1.0f, 1.0f, false);
        }
        for (int i = 1; i < GRID_SIZE; i++) {
            grid[i][0] = new Square(1.0f, 1.0f, 1.0f, false);
            grid[i][GRID_SIZE-1] = new Square(1.0f, 1.0f, 1.0f, false);
        }

    }
    void drawBattlefield(){
        drawGrid();
    }
    ~Battlefield() {
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                delete grid[i][j];
            }
        }
        
    }

private:
    Square *grid[GRID_SIZE][GRID_SIZE];

    void drawGrid() {
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if ( grid[i][j] != nullptr)
                    drawSquare(i, j, grid[i][j]);
            }
        }
    }

    static void drawSquare(int row, int col, Square* square) {

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
        glColor3f( (*square).colorR,  (*square).colorG,  (*square).colorB);
        glBegin(GL_QUADS);
        glVertex2f(-1.0f + 2.0f * (col) / GRID_SIZE, 1.0f - 2.0f * (row) / GRID_SIZE);
        glVertex2f(-1.0f + 2.0f * (col+1) / GRID_SIZE, 1.0f - 2.0f * (row) / GRID_SIZE);
        glVertex2f(-1.0f + 2.0f * (col+1) / GRID_SIZE, 1.0f - 2.0f * (row+1) / GRID_SIZE);
        glVertex2f(-1.0f + 2.0f * (col) / GRID_SIZE, 1.0f - 2.0f * (row+1) / GRID_SIZE);
        glEnd();
    }
};



int main() {
    
    srand(static_cast<unsigned int>(time(0)));

    // Заполнение сетки случайными значениями
	
    GLFWwindow* window;
    Battlefield battlefield =  Battlefield ();

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

        battlefield.drawBattlefield();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    // delete battlefield;
    glfwTerminate();
    return 0;
}
