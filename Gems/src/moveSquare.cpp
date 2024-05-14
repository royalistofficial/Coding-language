#include <moveSquare.hpp>
int prevRow = -1, prevCol = -1;

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        int row = static_cast<int>(ypos / SQUARE_SIZE);
        int col = static_cast<int>(xpos / SQUARE_SIZE);

        if ((prevRow != -1 && prevCol != -1) && (abs(prevRow-row) <= 1 && abs(prevCol - col) <= 1 && !(abs(prevRow-row) == 1 && abs(prevCol - col) == 1))) {
            // свап ячеек
            std::swap(grid[prevRow][prevCol], grid[row][col]);
            // if  (!(checkSequence(row, col) || checkSequence(prevRow, prevCol))) std::swap(grid[prevRow][prevCol], grid[row][col]);
            prevRow = -1;
            prevCol = -1;
        }else{
            prevRow = row;
            prevCol = col;
        }
    }
}