#pragma once

#include <iostream>
#include <vector>

enum Tile
{
	empty,
	wall,
	start,
	end,
};

class Maze
{
public:
	Maze();
	Maze(unsigned int width, unsigned int heigth);
	~Maze();

    void printMaze();
    

private:
	std::vector<std::vector<Tile>> _maze;
};
