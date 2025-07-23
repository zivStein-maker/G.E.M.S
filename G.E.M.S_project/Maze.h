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
	Maze(int type);//temp smaller maze.
	Maze(unsigned int width, unsigned int heigth);
	~Maze();

	std::vector<std::vector<Tile>> getMaze() const;
	unsigned int getWidth() const;
	unsigned int getHeight() const;

    void printMaze();
    

private:
	unsigned int _width;
	unsigned int _height;
	std::vector<std::vector<Tile>> _maze;
};
