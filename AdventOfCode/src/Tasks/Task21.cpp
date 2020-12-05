#include "Task21.h"

namespace AOC
{
    std::string Task21::solution()
    {
        const auto l = readWithCustomReader(CustomReaders::Task2Reader);

        int overallCount = 0;

        for (const auto&[from, to, character, password] : *l)
        {
            int count = 0;

            for (const auto c : password)
            {
                if (c == character)
                    count++;
            }

            if (from <= count && count <= to)
                overallCount++;
        }

        return std::to_string(overallCount);
    }
}
