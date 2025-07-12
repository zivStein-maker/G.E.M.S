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
}

Maze::Maze(unsigned int width,unsigned int height)
{
    _maze = std::vector<std::vector<Tile>>(height, std::vector<Tile>(width, empty));
	generateMaze(width, height);
}

Maze::~Maze()
{
    
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