#include <bonus.hpp>

void paintBonus(const int row, const int col){

    int paintBonusBlock = 0;
    int rowPaint, colPaint;

    while (true)
    {
        rowPaint = rand() % GRID_SIZE;
        colPaint = rand() % GRID_SIZE;  
        if ((grid[rowPaint][colPaint] > 0)&&
             (abs(rowPaint-row)<=3 || abs(colPaint-col)<=3)){
            grid[rowPaint][colPaint] = -grid[row][col];
            break;
        }    
    }

    while (paintBonusBlock < 2)
    {
        int rowPaint_2 = rand() % GRID_SIZE;
        int colPaint_2 = rand() % GRID_SIZE;  
        if ((abs(rowPaint-rowPaint_2)>1 || abs(colPaint-colPaint_2)>1)&&
            (abs(rowPaint-rowPaint_2)<=3 || abs(colPaint-colPaint_2)<=3)&&(
                grid[rowPaint_2][colPaint_2] > 0)){
            grid[rowPaint_2][colPaint_2] = -grid[row][col];
            paintBonusBlock++;
        }    
    }
}
void BombBonus(const int row, const int col){
    int BombBonusBlock = 0;
    while (BombBonusBlock < 5)
    {
        int rowPaint = rand() % GRID_SIZE;
        int colPaint = rand() % GRID_SIZE;  
        if ((grid[rowPaint][colPaint] > 0)){
            grid[rowPaint][colPaint] = 0;
            BombBonusBlock++;
        }    
    }

}