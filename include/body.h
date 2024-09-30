#ifndef BODY_H
#define BODY_H

#include "grid.h"
#include "head.h"

class Body
{
public:
    Body(Grid, Grid_Position, Face);
    void drawBody();
    void move();
    Grid_Position getPos() { return bodyPos; }
    Face getFace() { return this->face; }

private:
    Grid_Position bodyPos;
    int size, inPosX, inPosY;
    Face face{left};
};

#endif
