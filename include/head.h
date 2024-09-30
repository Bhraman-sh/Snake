#ifndef HEAD_H
#define HEAD_H

#include "grid.h"

enum Face {left = 1, right, up, down};

class Head
{
public:
    Head(Grid);

    void drawHead(Grid);
    void move();
    void setFace(Face face) { this->face = face; }

private:
    Grid_Position headPos;
    int size;
    Face face{down};
};

#endif
