#include "Environment.h"

bool Environment::isFinished() const
{
    return _isFinished;
}

float Environment::culcAverageFitness() const
{
    int totalFitness = 0;
    for (const auto& solution : _population)
        totalFitness += culcFitness(solution);
    return static_cast<float>(totalFitness / _population.size());
}

unsigned int Environment::culcFitness(const Solution& solution) const
{
    int score = 0;
    int x = 1;
    int y = 1;
    for (const auto& dir : solution.getPath())
    {
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
        if (_maze.getMaze()[x][y] != wall)
            score++;
    }
    return score;
}
