#include <draw.hpp>

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
