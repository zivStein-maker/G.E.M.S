#pragma once

#include "Maze.h"
#include "Solution.h"
#include <algorithm>
#include <set>

#define FINISHED_MAZE -999
#define DEAD_END -1

class Environment
{
public:
	Environment(const Maze& maze, unsigned int startingPopulationAmount);
	~Environment();


	Solution solveMaze();
	bool isFinished() const;
	float culcAverageFitness() const;

private:

	int culcFitness(const Solution& solution) const;

	Direction invertDirection(const Direction& direction) const;
	bool isDeadEnd(int x, int y, const Direction& PrivInstraction) const;
	bool isLooping(int x, int y,const Direction& privInstraction) const;

	Maze _maze;
	std::vector<Solution> _population;
	bool _isFinished = false;
	const int _startingPopulationAmount;
};
