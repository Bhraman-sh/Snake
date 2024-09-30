#include "grid.h"

Grid::Grid(int x_s, int y_s)
{
// NOTE: For now we assume that screen width is greater than the screen height

    // Determine the starting position of grid and size of each square grid
    grid_pos_y = ((5.0/100) * y_s);
    length = (((9.0/10) * y_s) / MAX_GRID_Y);
    grid_pos_x = ((x_s/2) - length * MAX_GRID_X/2);

    // std::cout << grid_pos_y << " " << grid_pos_x << " " << length << " " << std::endl;

    // Draw the Grid lines

    max_y = grid_pos_y + length * MAX_GRID_Y;
    max_x = grid_pos_x + length * MAX_GRID_X;
}

void Grid::drawGrid()
{
    for (int i = 1; i < MAX_GRID_X; i++)
    {
        DrawLine(grid_pos_x + length * i, grid_pos_y, grid_pos_x + length * i, max_y, BLUE);
    }

    for (int i = 1; i < MAX_GRID_Y; i++)
    {
        DrawLine(grid_pos_x, grid_pos_y + length * i, max_x, grid_pos_y + length * i, BLUE);
    }

    DrawRectangleLines(grid_pos_x, grid_pos_y, length * MAX_GRID_X, length * MAX_GRID_Y, BLACK);
}

bool Grid_Position::operator== (const Grid_Position pos) const
{
    if (grid_x == pos.getGridX())
    {
        if (grid_y == pos.getGridY())
        {
            return true;
        }
    }
    return false;
}
