#pragma once

#include "Maze.h"
#include "Solution.h"
#include <set>

class Environment
{
public:
	Environment(unsigned int startingPopulationAmount);
	~Environment();

	bool isFinished() const;
	float culcAverageFitness() const;

private:

	unsigned int culcFitness(const Solution& solution) const;

	Maze _maze;
	std::set<Solution> _population;
	bool _isFinished = false;
};
