#include "Task51.h"

namespace AOC
{
    std::string Task51::solution()
    {
        auto passes = *readWithCustomReader(CustomReaders::task5Reader);

        int maxPass = 0;

        for (int pass : passes)
            maxPass = std::max(pass, maxPass);

        return std::to_string(maxPass);
    }
}
