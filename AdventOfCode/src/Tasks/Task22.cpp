#include "Task22.h"

namespace AOC
{
    std::string Task22::solution()
    {
        const auto l = readWithCustomReader(CustomReaders::Task2Reader);

        int overallCount = 0;

        for (const auto&[pos1, pos2, character, password] : *l)
        {
            const char first = password[pos1-1];
            const char second = password[pos2-1];

            if ((first != character) != (second != character))
                overallCount++;
        }

        return std::to_string(overallCount);
    }
}
