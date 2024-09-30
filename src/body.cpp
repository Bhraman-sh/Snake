#include "body.h"

Body::Body(Grid grid, Grid_Position pos, Face t_face) : size(grid.getLength()), inPosX(grid.getGridPositionX()), inPosY(grid.getGridPositionY()), bodyPos(pos), face(t_face)
{
}

void Body::drawBody()
{
    DrawRectangle(inPosX + size * bodyPos.getGridX(),
                  inPosY + size * bodyPos.getGridY(),
                  size, size, BLACK);
}

void Body::move()
{
    switch (face)
    {
        case left:
            bodyPos.moveLeft();
            break;

        case right:
            bodyPos.moveRight();
            break;

        case down:
            bodyPos.moveDown();
            break;

        case up:
            bodyPos.moveUp();
            break;

        default:
            break;
    }
}


