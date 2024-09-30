#ifndef GRID_H
#define GRID_H

#include "raylib.h"

#define MAX_GRID_X 20
#define MAX_GRID_Y 20

class Grid
{
public:
    Grid(int screenWidth, int screenHeight);
    int getLength(){ return length; };
    int getGridPositionX(){ return grid_pos_x; };
    int getGridPositionY(){ return grid_pos_y; };
    void drawGrid();
private:
    int grid_pos_x, grid_pos_y, length, max_y, max_x;
};

class Grid_Position
{
public:
    int getGridX(){ return grid_x; };
    int getGridY(){ return grid_y; };

    void setGridX(int i){ grid_x = i; };
    void setGridY(int i){ grid_y = i; };

    void moveRight(){ grid_x++; };
    void moveLeft(){ grid_x--; };
    void moveDown(){ grid_y++; };
    void moveUp(){ grid_y--; };

    void rotate(Grid_Position);
private:
    int grid_x{5}, grid_y{1}; 
};

#endif
