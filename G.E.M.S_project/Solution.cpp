#include "Solution.h"

#define MUTATION_FREQUENSE 500 
#define SEARCHD_PART_DOURTION 10

Solution::Solution(unsigned int height, unsigned int wigth)
{  
    _path = std::vector<Direction>(height * wigth, up);//need to change this to make them work in shorter parts
	_endSearchIndex = ( SEARCHD_PART_DOURTION < _path.size() ) ? _path.size() : SEARCHD_PART_DOURTION;

	for (auto& direction : _path)
		direction = static_cast<Direction>(rand() % 4);
}

Solution::Solution(const Solution& father, const Solution& mather)
{
	_path = std::vector<Direction>(father._path.size(), up);

	_startSearchIndex = rand() % 2 == 0 ? father._startSearchIndex : mather._startSearchIndex;
	_endSearchIndex = rand() % 2 == 0 ? father._endSearchIndex : mather._endSearchIndex;

	unsigned int index = rand() % father._path.size();

	for (unsigned int i = 0; i < father._path.size(); i++)
	{
		if (i <= index)
			(_path)[i] = (father._path)[i];
		else
			(_path)[i] = (mather._path)[i];
	}

	mutate();
}

Solution::~Solution()
{
	_path.clear();
}

void Solution::mutate()
{//addes a random mutation to the path (genome).
	
	if(rand() % MUTATION_FREQUENSE == 1)
	{
		int index = rand() % _path.size();
		_path[index] = static_cast<Direction>(rand() % 4);
	}
}

void Solution::printSolution(const Maze& maze)
{
	std::vector<std::vector<char>> pathVisualition;
	for (const auto& row : maze.getMaze())
	{
		std::string line = "";
		for (const auto& tile : row)
		{
			switch (tile)
			{
			case wall:  line += "#"; break;
			case empty: line += " "; break;
			case start: line += "S"; break;
			case end:   line += "E"; break;
			}
		}
		pathVisualition.emplace_back(line.begin(),line.end());
	}

	int x = 1;
	int y = 1;
	for (const auto& dir : _path)
	{
		if (y >= maze.getHeight() or y < 0 or x >= maze.getWidth() or x < 0 or maze.getMaze()[y][x] == Tile::wall or maze.getMaze()[y][x] == Tile::end)
			break;
		switch (dir)
		{
		case up:
			pathVisualition[y][x] = '^';
			y--; break;
		case down:
			pathVisualition[y][x] = 'Y';
			y++; break;
		case left:
			pathVisualition[y][x] = '<';
			x--; break;
		case right:
			pathVisualition[y][x] = '>';
			x++; break;
		}
	}
	for (const auto& row : pathVisualition)
	{
		for (const auto& tile : row)
		{
			std::cout << tile;
		}
		std::cout << '\n';
	}
}

void Solution::advanceSearch()
{
	_startSearchIndex = _endSearchIndex;
	_endSearchIndex = _endSearchIndex + SEARCHD_PART_DOURTION >= _path.size() ? _path.size() - 1 : _endSearchIndex + SEARCHD_PART_DOURTION;
}

std::vector<Direction> Solution::getPath() const
{
	return _path;
}

unsigned int Solution::getStartSearchIndex() const
{
	return _startSearchIndex;
}

unsigned int Solution::getEndSearchIndex() const
{
	return _endSearchIndex;
}
