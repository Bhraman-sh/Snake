#include "body.h"

Body::Body(Grid grid)
{
    size = grid.getLength();
    inPosX = grid.getGridPositionX();
    inPosY = grid.getGridPositionY();
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
