#pragma once
#include "Maze.h"
#include <vector>
#include <iostream>
#include <random>
#include <ctime>

enum Direction
{
	up,
	down,
	left,
	right
};

class Solution // this class represents the population of solutions for the algorithm.
{
	public:
		Solution(unsigned int higth, unsigned int wigth);
		Solution(const Solution& father, const Solution& mather);// breeding function
		~Solution();
		void mutate();
		void printSolution(const Maze& maze);
		void advanceSearch();

		std::vector<Direction> getPath() const;
		unsigned int getStartSearchIndex() const;
		unsigned int getEndSearchIndex() const;

	private:
		std::vector<Direction> _path;
		unsigned int _startSearchIndex = 0;
		unsigned int _endSearchIndex;
};