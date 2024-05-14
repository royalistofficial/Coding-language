#include "Grid.hpp"
#include "const.hpp"

Grid::Grid() {
    // создание поля
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = nullptr;
        }
    }

    // граница
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[0][i] = new Square(1.0f, 1.0f, 1.0f, -1);
    }
    for (int i = 1; i < GRID_SIZE; i++) {
        grid[i][0] = new Square(1.0f, 1.0f, 1.0f, -1);
        grid[i][GRID_SIZE-1] = new Square(1.0f, 1.0f, 1.0f, -1);
    }
    // заполнение разрушающимеся блоками
    for (int i = 1; i < GRID_SIZE/2; i++) {
        for (int j = 1; j < GRID_SIZE-1; j++) {
            int colorIndex = 1 + rand() % 3;
            grid[i][j] = new Square(COLORS[colorIndex][0], COLORS[colorIndex][1], COLORS[colorIndex][2], colorIndex);
        }
    }

    // заполнение разрушающимеся блоками
    // for (int i = 1; i < GRID_SIZE/4; i++) {
    //     for (int j = 1; j < GRID_SIZE-1; j++) {
    //         int colorIndex =  1 + rand() % (COLORS.size() - 1);
    //         grid[i][j] = new Square(COLORS[colorIndex][0], COLORS[colorIndex][1], COLORS[colorIndex][2], colorIndex);
    //     }
    // }
    // for (int i = 1; i < GRID_SIZE-1; i++) {
    //     if (i != GRID_SIZE/2 -1  && i != GRID_SIZE/2)
    //         grid[GRID_SIZE/2][i] = new Square(1.0f, 1.0f, 1.0f, -1);
    // }
}

void Grid::drawGrid(){
    draw();
}

bool Grid::deleteSquare(int i, int j){
    if (grid[i][j]-> destructibility != -1){
        grid[i][j]->destructibility --;
        if (grid[i][j]->destructibility ==0){
            delete grid[i][j];
            grid[i][j] = nullptr;
            
            return true;
        }
        grid[i][j]->colorR = COLORS[grid[i][j]-> destructibility][0];
        grid[i][j]->colorG = COLORS[grid[i][j]-> destructibility][1];
        grid[i][j]->colorB = COLORS[grid[i][j]-> destructibility][2];
    }
    return false;
}

Square* Grid::getGrid(int i, int j) {
    return grid[i][j];
}

Grid::~Grid(){
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            delete grid[i][j];
        }
    }
}

void Grid::draw() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if ( grid[i][j] != nullptr)
                drawSquare(i, j);
        }
    }
}

void Grid::drawSquare(int row, int col) {
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
    glColor3f( (*this->grid[row][col]).colorR,  (*this->grid[row][col]).colorG,  (*this->grid[row][col]).colorB);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f + 2.0f * (col) / GRID_SIZE, 1.0f - 2.0f * (row) / GRID_SIZE);
    glVertex2f(-1.0f + 2.0f * (col+1) / GRID_SIZE, 1.0f - 2.0f * (row) / GRID_SIZE);
    glVertex2f(-1.0f + 2.0f * (col+1) / GRID_SIZE, 1.0f - 2.0f * (row+1) / GRID_SIZE);
    glVertex2f(-1.0f + 2.0f * (col) / GRID_SIZE, 1.0f - 2.0f * (row+1) / GRID_SIZE);
    glEnd();
}