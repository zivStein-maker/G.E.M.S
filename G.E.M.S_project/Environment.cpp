#include "Environment.h"

Environment::Environment(const Maze& maze, unsigned int startingPopulationAmount) :_startingPopulationAmount(startingPopulationAmount)
{
    srand(time(NULL)); 
	_maze = maze;
	_isFinished = false;
    std::vector<Solution> population;
    for (int i = 0; i < startingPopulationAmount; i++)
        population.emplace_back(Solution(maze.getHeight(), maze.getWidth()));
	_population = population;
}

Environment::~Environment()
{
}

Solution Environment::solveMaze()
{
    int genrations = 1;
    while (!_isFinished)
    {
        genrations++;
        std::vector<std::pair<int, Solution>> nextGen;
        for (const auto& solution : _population)
        {
            int fitnessSum = 0;
            int fitness = culcFitness(solution);
			fitnessSum += fitness;

            if (fitness == FINISHED_MAZE)
            {
                _isFinished = true;
                std::cout << "found sloution in: " << genrations << " genrations.\n";
                return solution;
            }
            if(fitness == DEAD_END)
				continue;

            nextGen.emplace_back(fitness, solution);
        }
        float averageFitness = _population.size();

        std::sort(nextGen.begin(), nextGen.end(), 
            [](const std::pair<int, Solution>& a, const std::pair<int, Solution>& b) 
        {
            return a.first > b.first;
        });
        
       
        std::cout << "best fitness: " << nextGen[0].first << std::endl;
		std::cout << "population size: " << _population.size() << std::endl;

		std::vector<Solution> newPopulation;
		const int eliteCount = std::max(1, static_cast<int>(nextGen.size() * 0.1));// Keep top 10% to next generation
        for (size_t i = 0; i < eliteCount; i++)
            newPopulation.push_back(nextGen[i].second);
       
        for (int i = 0; i < (nextGen.size() / 3) * 2; i+=2)
        {
            Solution parent1 = nextGen[i].second;
            Solution parent2 = nextGen[i + 1].second;

            int amountOfChildren = (rand() % 3) + 2;

            if(nextGen.size() < _startingPopulationAmount)
				amountOfChildren = 4;
			
            for (int j = 0; j < amountOfChildren; j++)
                newPopulation.emplace_back(Solution(parent1, parent2));
		}

        _population.clear();
		_population = newPopulation;
    }
}

bool Environment::isFinished() const
{
    return _isFinished;
}

float Environment::culcAverageFitness() const
{
    int totalFitness = 0;
    for (const auto& solution : _population)
    {
		int fitness = culcFitness(solution);
		if (fitness == DEAD_END) continue; // Skip dead ends
        totalFitness += fitness;
    }
    return static_cast<float>(totalFitness / _population.size());
}

int Environment::culcFitness(const Solution& solution) const
{
    int score = 0;
    int x = 1;
    int y = 1;
    Direction privDir;
    for (const auto& dir : solution.getPath())
    {
        if(x == 1 && y == 1)
			privDir = dir;
        

        switch (dir)
        {
            case up:
                y--; break;
            case down:
                y++; break;
            case left:
                x--; break;
            case right:
                x++; break;
        }
        try
        {
            if (_maze.getMaze()[y][x] == Tile::empty)
            {
                if (isDeadEnd(x, y, dir))
                    return DEAD_END;

                else if (dir == invertDirection(privDir))
                {
                    score--;
                    continue;
                }

				privDir = dir;
                score++;
            }

            else if (_maze.getMaze()[y][x] == Tile::end)
            {
                
                return FINISHED_MAZE;
            }

            else break;
        }
        catch (...)
        {
            return score;
		}
    }
    return score;
}

Direction Environment::invertDirection(const Direction& direction) const
{
    Direction dir;
    if (direction == up or direction == left)
        dir = Direction((direction) + 1);
    else
        dir = Direction((direction) - 1);
    return dir;
}

bool Environment::isDeadEnd(int x, int y,const Direction& privInstraction) const
{
	Direction movedFrom = invertDirection(privInstraction);
    switch (movedFrom)
    {
        case up:
			return _maze.getMaze()[y - 1][x] == Tile::wall && _maze.getMaze()[y][x - 1] == Tile::wall && _maze.getMaze()[y][x + 1] == Tile::wall;
        case down:
			return _maze.getMaze()[y + 1][x] == Tile::wall && _maze.getMaze()[y][x - 1] == Tile::wall && _maze.getMaze()[y][x + 1] == Tile::wall;
		case left:
            return _maze.getMaze()[y + 1][x] == Tile::wall && _maze.getMaze()[y - 1][x] == Tile::wall && _maze.getMaze()[y][x + 1] == Tile::wall;
		case right:
            return _maze.getMaze()[y + 1][x] == Tile::wall && _maze.getMaze()[y - 1][x] == Tile::wall && _maze.getMaze()[y][x - 1] == Tile::wall;
    }
}

bool Environment::isLooping(int x, int y,const Direction& privInstraction) const
{
    return false;
}
