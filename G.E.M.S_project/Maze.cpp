#include "Maze.h"


Maze::Maze()
{
    _maze = 
    {
        { wall, wall, wall, wall, wall, wall, wall, wall, wall, wall },
        { wall, start, empty, empty, wall, empty, empty, empty, empty, wall },
        { wall, wall, empty, wall, wall, empty, wall, wall, empty, wall },
        { wall, empty, empty, empty, empty, empty, wall, empty, empty, wall },
        { wall, wall, wall, wall, empty, wall, wall, wall, empty, wall },
        { wall, empty, empty, empty, empty, wall, empty, empty, empty, wall },
        { wall, empty, wall, wall, empty, wall, wall, empty, wall, wall },
        { wall, empty, empty, empty, wall, empty, empty, empty, empty, wall },
        { wall, wall, empty, wall, wall, wall, empty, wall, empty, wall },
        { wall, wall, wall, wall, wall, wall, wall, wall, end, wall }
    };
	_width = _maze[0].size();
	_height = _maze.size();
}

Maze::Maze(int type)
{
    _maze = {
        {wall,wall,wall,wall,wall},
        {wall, start,empty,wall,wall},
        {wall, empty, wall,empty,wall},
        {wall, empty, empty ,empty,wall},
        {wall,wall,wall,end,wall }
    };
    _width = _maze[0].size();
    _height = _maze.size();
}

Maze::Maze(unsigned int width,unsigned int height)
{
    _maze = std::vector<std::vector<Tile>>(height, std::vector<Tile>(width, empty));
    _width = _maze[0].size();
    _height = _maze.size();
}

Maze::~Maze()
{
    
}

std::vector<std::vector<Tile>> Maze::getMaze() const
{
    return _maze;
}

unsigned int Maze::getWidth() const
{
    return _width;
}

unsigned int Maze::getHeight() const
{
    return _height;
}

void Maze::printMaze()
{
    for (const auto& row : _maze)
    {
        for (const auto& tile : row)
        {
            switch (tile) 
            {
                case wall:  std::cout << "#"; break;
                case empty: std::cout << " "; break;
                case start: std::cout << "S"; break;
                case end:   std::cout << "E"; break;
            }
        }
        std::cout << '\n';
    }
}