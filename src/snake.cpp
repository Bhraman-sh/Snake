#include "snake.h"

Snake::Snake() : grid(800, 600), head(grid)
{
    InitWindow(800, 600, "SNAKE");
    time1 = GetTime();
}

Snake::~Snake()
{
    std::cout << "Destructor called" << std::endl;
    for (auto it = bodies.begin(); it != bodies.end(); ++it)
    {
         std::cout << (*it)->getPos().getGridX() << (*it)->getPos().getGridX() << std::endl;
    }
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

        if ((time2 - time1) > 0.2)
        {
            time1 = time2;
            moveSnake();
            foodEaten();
        }
        grid.drawGrid();
        DrawCircle(grid.getGridPositionX() + foodPos.getGridX() * grid.getLength() + grid.getLength()/2, 
                   grid.getGridPositionY() + foodPos.getGridY() * grid.getLength() + grid.getLength()/2,
                   10, BLACK);
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

    /* for (auto it = bodies.begin(); it != bodies.end(); ++it)
    {
        (*it)->move();
    } */
}

void Snake::growSnake() 
{
    Grid_Position pos;

    pos = getNewBodyPos();

    std::cout << " In Grow Snake:" << pos.getGridX() << " " << pos.getGridY() << std::endl;

    bodies.emplace_back(std::make_unique<Body>(grid, pos, temp_face));
}

Grid_Position Snake::getNewBodyPos()
{
    Grid_Position pos;
    if (bodies.empty())
    {
        pos = head.getPos();
        temp_face = head.getFace();
    }
    else 
    {
        pos = bodies.back()->getPos();
        temp_face = bodies.back()->getFace();
    }

    finalPosition(pos, temp_face);

    return pos;
}

void Snake::finalPosition(Grid_Position &pos, Face &face)
{
    switch (face)
    {
        case right:
            pos.moveLeft();
            std::cout << " case right ";
            std::cout << pos.getGridX() << " " << pos.getGridY();
            break;

        case left:
            pos.moveRight();
            std::cout << " case left ";
            std::cout << pos.getGridX() << " " << pos.getGridY();
            break;

        case up:
            pos.moveDown();
            std::cout << " case up"; 
            std::cout << pos.getGridX() << " " << pos.getGridY();
            break;

        case down:
            pos.moveUp();
            std::cout << " case down ";
            std::cout << pos.getGridX() << " " << pos.getGridY();
            break;

        default:
            std::cout << "Default case induced";
            break;
    }
}

void Snake::foodEaten()
{
    if (head.getPos() == foodPos)
    {
        foodPos = randomPositionGenerator(bodies, head);

        growSnake();
    }
}
void Snake::updateInput()
{
    if (IsKeyPressed(KEY_RIGHT)) { head.setFace(right); }
    if (IsKeyPressed(KEY_LEFT)) { head.setFace(left); }
    if (IsKeyPressed(KEY_UP)) { head.setFace(up); }
    if (IsKeyPressed(KEY_DOWN)) { head.setFace(down); }
}

Grid_Position randomPositionGenerator(std::vector<std::unique_ptr<Body>>& bodies, Head hed)
{
    Grid_Position pos;
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis1(0, MAX_GRID_X-1);
    std::uniform_int_distribution<> dis2(0, MAX_GRID_Y-1);

    do
    {
        int x = dis1(gen);
        int y = dis2(gen);
        pos.setGridX(x);
        pos.setGridY(y);
    } 
    while (checkGridSpace(bodies, pos, hed));

    return pos;
}

bool checkGridSpace(std::vector<std::unique_ptr<Body>>&bodies, Grid_Position pos, Head head)
{
    if (pos == head.getPos()) return true;

    for (auto it = bodies.begin(); it != bodies.end(); ++it)
    {
        if (pos == (*it)->getPos())
        {
            return true;
        }
    }
    return false;
}
