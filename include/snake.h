#ifndef SNAKE_H
#define SNAKE_H

#include "grid.h"
#include "head.h"
#include "body.h"

#include <vector>
#include <list>
#include <memory>
#include <random>
#include <iostream>

struct movement
{
    int a;
    Face face;
};

class Snake
{
public:
    Snake();
    ~Snake();

    // Basic snake related function
    void run();
    void draw();
    void moveSnake();

    // Growing the snake after eating
    void growSnake();
    Grid_Position getNewBodyPos();
    void finalPosition(Grid_Position&, Face&);
    void foodEaten();

    // General update
    void updateInput();

private:
    Grid grid;
    Grid_Position last;
    Head head;
    std::vector<std::unique_ptr<Body>> bodies; 
    std::list<movement> move;

    Face temp_face;

    float time1;
    float time2;

    Grid_Position foodPos;
};

Grid_Position randomPositionGenerator(std::vector<std::unique_ptr<Body>>&, Head);
bool checkGridSpace(std::vector<std::unique_ptr<Body>>&, Grid_Position, Head);

#endif
