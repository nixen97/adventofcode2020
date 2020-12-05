#include "Task.h"
#include <chrono>

namespace AOC
{
    void Task::addSolutionToStream(std::ostream& stream)
    {
        const auto result = getSolutionWithTiming();

        stream << "Task " << m_MajorVersion << "." << m_MinorVersion << ": <" << result.first << "> in " << result.second << " ms" << std::endl;
    }

    std::pair<std::string, long long> Task::getSolutionWithTiming()
    {
        const auto start = std::chrono::steady_clock::now();

        std::pair<std::string, long long> result = { solution(), 0 };

        result.second = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();

        return result;
    }
}
