#include "Solution.h"

Solution::Solution(unsigned int higth, unsigned int wigth)  
{  
	srand(time(NULL));

    _path = std::vector<Direction>(higth * wigth, up);

	for (auto& direction : _path)
		direction = static_cast<Direction>(rand() % 4);
}

Solution::Solution(const Solution& father, const Solution& mather)
{
	srand(time(NULL));

	_path = std::vector<Direction>(father._path.size(), up);

	for (unsigned int i = 0; i < father._path.size(); ++i)
	{
		if (rand() % 2 == 0)
			(_path)[i] = (father._path)[i];
		else
			(_path)[i] = (mather._path)[i];
	}
}

Solution::~Solution()
{
	_path.clear();
}

void Solution::mutate()
{//addes a random mutation to the path (genome).
	int index = rand() % _path.size();
	_path[index] = static_cast<Direction>(rand() % 4);
}

std::vector<Direction> Solution::getPath() const
{
	return _path;
}
