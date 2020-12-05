#include "Task11.h"

namespace AOC
{
    /**
     * Using an hash_map to find pair sum in linear time.
     * O(N) time
     * O(N) space
     *
     * Optimal for time.
     */
    std::string Task11::solution()
    {
        auto[l, N] = readInput<int>();

        std::unordered_map<int, int> neededForSum = {};

        for (int number : *l)
        {
            if (neededForSum.find(number) != neededForSum.end())
                return std::to_string(number * neededForSum[number]);

            neededForSum[m_Target - number] = number;
        }

        return "No result found";
    }
}
