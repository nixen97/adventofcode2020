#include "Task61.h"

namespace AOC
{
    std::string Task61::solution()
    {
        auto answers = *readWithCustomReader(CustomReaders::task6Reader);

        uint32_t count = 0;

        for (auto answer : answers)
            count += answer.count;

        return std::to_string(count);
    }
}
