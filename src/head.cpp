#include "head.h"

Head::Head(Grid grid) : size(grid.getLength()) 
{
}

void Head::drawHead(Grid grid)
{
    int x_i, y_i;
    int x, y;

    x_i = grid.getGridPositionX();
    y_i = grid.getGridPositionY();

    x = headPos.getGridX();
    y = headPos.getGridY();

    switch (face)
    {
        case left:
        DrawRectangle(x_i + size * x, y_i + size * y, size, size, DARKGRAY);
        DrawCircle(x_i + size * x + 0.2 * size, y_i + size * y + 0.2 * size, 0.1 * size, BLACK);
        DrawCircle(x_i + size * x + 0.2 * size, y_i + size * y + 0.6 * size, 0.1 * size, BLACK);
        break;

        case right:
        DrawRectangle(x_i + size * x, y_i + size * y, size, size, DARKGRAY);
        DrawCircle(x_i + size * x + 0.8 * size, y_i + size * y + 0.2 * size, 0.1 * size, BLACK);
        DrawCircle(x_i + size * x + 0.8 * size, y_i + size * y + 0.6 * size, 0.1 * size, BLACK);
        break;

        case up:
        DrawRectangle(x_i + size * x, y_i + size * y, size, size, DARKGRAY);
        DrawCircle(x_i + size * x + 0.3 * size, y_i + size * y + 0.2 * size, 0.1 * size, BLACK);
        DrawCircle(x_i + size * x + 0.7 * size, y_i + size * y + 0.2 * size, 0.1 * size, BLACK);
        break;

        case down:
        DrawRectangle(x_i + size * x, y_i + size * y, size, size, DARKGRAY);
        DrawCircle(x_i + size * x + 0.3 * size, y_i + size * y + 0.8 * size, 0.1 * size, BLACK);
        DrawCircle(x_i + size * x + 0.7 * size, y_i + size * y + 0.8 * size, 0.1 * size, BLACK);
        break;

        default:
        break;
    }
}

void Head::move()
{
    switch (face)
    {
        case left:
            headPos.moveLeft();
            break;

        case right:
            headPos.moveRight();
            break;

        case up:
            headPos.moveUp();
            break;

        case down:
            headPos.moveDown();
            break;

        default:
            break;
    }
}

