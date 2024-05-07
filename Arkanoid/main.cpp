#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>

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
        // создание поля
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                grid[i][j] = nullptr;
            }
        }
        // заполнение разрушающимеся блоками
        for (int i = 1; i < GRID_SIZE/2; i++) {
            for (int j = 1; j < GRID_SIZE-1; j++) {
                int colorIndex =  1 + rand() % (COLORS.size() - 1);
                grid[i][j] = new Square(COLORS[colorIndex][0], COLORS[colorIndex][1], COLORS[colorIndex][2], true);
            }
        }
        // граница
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

class Plarform{
    public:
    void drawPlarform(){
        draw();
    }
    void MovePlarform(float dx){ 
        if((dx > 0) && (this->x + (float(SizePlarform - 1) / (GRID_SIZE * 2.0f)) < 1))
            this->x += dx;
        else if ((dx < 0) && (this->x - (float(SizePlarform - 1) / (GRID_SIZE * 2.0f)) > -1))
            this->x += dx;
    }

    private:
    float x = 0;
    int SizePlarform = 50;
    void draw(){
        glColor3f(1.0f,  1.0f,  1.0f);
        glBegin(GL_QUADS);
        glVertex2f(this->x - (float(SizePlarform) / (GRID_SIZE * 2.0f)), -1.0f + 1.0f/ GRID_SIZE);
        glVertex2f(this->x + (float(SizePlarform) / (GRID_SIZE * 2.0f)), -1.0f + 1.0f/ GRID_SIZE);
        glVertex2f(this->x + (float(SizePlarform) / (GRID_SIZE * 2.0f)), -1.0f);
        glVertex2f(this->x - (float(SizePlarform) / (GRID_SIZE * 2.0f)), -1.0f);
        glEnd();

    }
};
class Ball {
public:
    void drawBall(){
        draw();
        move();
    }
private:
    float x = 0.0f;
    float y = -0.75f;
    float angle = 3.14f;
    const float radius = 0.02f;
    const float speed = 0.01f;

    void draw(){
        int num_segments = 16;
        glColor3f(1.0f, 1.0f, 1.0f); 
        glLineWidth(1.0f);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < num_segments; i++) {
            float theta = 2.0f * 3.14f * float(i) / float(num_segments);
            glVertex2f(this->x + this->radius * cos(theta), this->y + this->radius * sin(theta));
        }
        glEnd();
    }
    void move(){
        this->x += speed*sin(this->angle);
        this->y += speed*cos(this->angle);
    }
};

Ball ball = Ball();
Battlefield battlefield =  Battlefield ();
Plarform plarform = Plarform();

static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // Проверка, была ли нажата клавиша A или D.
    if (key == GLFW_KEY_A)
    {
        if (action == GLFW_PRESS || action == GLFW_REPEAT)
        {
            // Уменьшение значения x при нажатии клавиши A.
            plarform.MovePlarform(-0.02f);
        }
    }
    else if (key == GLFW_KEY_D)
    {
        if (action == GLFW_PRESS || action == GLFW_REPEAT)
        {
            // Увеличение значения x при нажатии клавиши D.
            plarform.MovePlarform(0.02f);
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

        battlefield.drawBattlefield();
        plarform.drawPlarform();
        ball.drawBall();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    // delete battlefield;
    glfwTerminate();
    return 0;
}
