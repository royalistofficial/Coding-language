#include <changesGrid.hpp>
#include <bonus.hpp>
#include <draw.hpp>

bool checkSequence(int row, int col) {
    if (grid[row][col] <= 0)
        return false;
    int sequenceLength = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        if(i >= 0 && i < GRID_SIZE){
            if(grid[i][col] == -grid[row][col]) return true;
            if (grid[i][col] == grid[row][col]) sequenceLength++;
        }
    }

    for (int j = col - 2; j <= col + 2; j++) {
         if (j >= 0 && j < GRID_SIZE){
            if(grid[row][j] == -grid[row][col]) return true;
            if (grid[row][j] == grid[row][col]) sequenceLength++;
         }
    }
    if (sequenceLength >= 4)return true;

    // для 3 в ряд 
    // // Проверка горизонтальных линий
    // int sequenceLength = 0;
    // for (int i = row - 2; i <= row + 2; i++) {
    //     if (i >= 0 && i < GRID_SIZE && abs(grid[i][col]) == abs(grid[row][col]) && grid[row][col] > 0) {
    //         sequenceLength++;
    //         if (sequenceLength >= 3) return true;
    //     } else {
    //         sequenceLength = 0;
    //     }
    // }

    // // Проверка вертикальных линий
    // sequenceLength = 0;
    // for (int j = col - 2; j <= col + 2; j++) {
    //     if (j >= 0 && j < GRID_SIZE && abs(grid[row][j]) == abs(grid[row][col]) && grid[row][col] > 0) {
    //         sequenceLength++;
    //         if (sequenceLength >= 3) return true;
    //     } else {
    //         sequenceLength = 0;
    //     }
    // }

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
                int randBonus = rand() % 10; 
                if (randBonus == 0)  paintBonus(i, j);
                else if (randBonus == 1)  BombBonus(i, j);
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
                    drawGrid();
                }
            }
        }
    }
}

void cleanBlackkBloc(){
    bool sequenceBlack = true;
    while (sequenceBlack) {
        blackBlockUp();
        sequenceBlack = false;
        for (int i = 0; i < GRID_SIZE; i++) {
            if (grid[0][i] == 0){
                sequenceBlack = true;    
                grid[0][i] = 1 + rand() % (COLORS.size() - 1);
            }           
        }
    }
}
