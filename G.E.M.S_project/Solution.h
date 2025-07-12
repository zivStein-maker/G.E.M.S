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
		/// todo: implement the function to calculate the fitness of the solution
		void mutate();

		std::vector<Direction> getPath() const;
	private:
		std::vector<Direction> _path;
};