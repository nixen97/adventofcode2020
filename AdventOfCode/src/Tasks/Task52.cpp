#include "Task52.h"

namespace AOC
{
    std::string Task52::solution()
    {
        auto passes = *readWithCustomReader(CustomReaders::task5Reader);

        std::vector<bool> foundMap = std::vector<bool>(879);

        for (int i = 0; i < 54; i++)
            foundMap[i] = true;

        for (auto pass : passes)
            foundMap[pass] = true;

        for (int i = 0; i < foundMap.size(); i++)
            if (!foundMap[i])
                return std::to_string(i);

        return ":(";
    }
}
