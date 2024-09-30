#ifndef BODY_H
#define BODY_H

#include "grid.h"
#include "head.h"

class Body
{
public:
    Body(Grid);
    void drawBody();
    void move();

private:
    Grid_Position bodyPos;
    int size, inPosX, inPosY;
    Face face;
};

#endif
