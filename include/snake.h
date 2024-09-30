#ifndef SNAKE_H
#define SNAKE_H

#include "grid.h"
#include "head.h"
#include "body.h"

#include <vector>
#include <list>
#include <memory>
#include <random>

struct movement
{
    int a;
    Face face;
};

class Snake
{
public:
    Snake();

    void run();
    void draw();
    void moveSnake();
    void growSnake();

    void updateInput();

private:
    Grid grid;
    Grid_Position last;
    Head head;
    std::vector<std::unique_ptr<Body>> bodies; 
    std::list<movement> move;

    float time1;
    float time2;

    Grid_Position foodPos;
};

Grid_Position randomPositionGenerator(std::vector<std::unique_ptr<Body>>&);
bool checkGridSpace(std::vector<std::unique_ptr<Body>>&, Grid_Position);

#endif
