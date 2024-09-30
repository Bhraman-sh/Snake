#include "snake.h"

Snake::Snake() : grid(800, 600), head(grid)
{
    InitWindow(800, 600, "SNAKE");
    time1 = GetTime();
}

void Snake::run()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        draw();
        time2 = GetTime();
        updateInput();
        if ((time2 - time1) > 0.5)
        {
            time1 = time2;
            moveSnake();
        }
        grid.drawGrid();
        EndDrawing();
    }
}

void Snake::draw()
{
    head.drawHead(grid);

    for (auto it = bodies.begin(); it != bodies.end(); ++it)
    {
        (*it)->drawBody();
    }
}

void Snake::moveSnake()
{
    head.move();
}

void Snake::growSnake() {}

void Snake::updateInput()
{
    if (IsKeyPressed(KEY_RIGHT)) { head.setFace(right); }
    if (IsKeyPressed(KEY_LEFT)) { head.setFace(left); }
    if (IsKeyPressed(KEY_UP)) { head.setFace(up); }
    if (IsKeyPressed(KEY_DOWN)) { head.setFace(down); }
}

Grid_Position randomPositionGenerator(std::vector<std::unique_ptr<Body>>& bodies)
{
    Grid_Position pos;
    std::mt19937 gen;

    std::uniform_int_distribution<> dis1(0, MAX_GRID_X);
    std::uniform_int_distribution<> dis2(0, MAX_GRID_X);

    do
    {
        int x = dis1(gen);
        int y = dis2(gen);
        pos.setGridX(x);
        pos.setGridY(y);
    } 
    while (checkGridSpace(bodies, pos));

    return pos;
}

bool checkGridSpace(std::vector<std::unique_ptr<Body>>&bodies, Grid_Position pos)
{
    for (auto it = bodies.begin(); it != bodies.end(); ++it)
    {
        if (pos == (*it).getPos())
    }
}
