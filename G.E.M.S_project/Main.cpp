#include "Environment.h"
#include <chrono> 

int main(int args,char** argv)
{
	Maze maze = Maze();
	maze.printMaze();
	Environment god = Environment(maze, 100);
	auto start = std::chrono::high_resolution_clock::now();
	Solution result = god.solveMaze();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	std::cout << "found solution in: " << duration.count() << " seconds." << std::endl;
	std::cout << "solution:" << std::endl;
	result.printSolution(maze);
}