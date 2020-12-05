#include "TestTask.h"

#include <sstream>

namespace AOC
{
    std::string TestTask::solution()
    {
        auto[l, N] = readInput<int>();

        return "Test " + std::to_string(N) + " -> " + std::to_string(l->front());
    }
}
