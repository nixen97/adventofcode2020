#include "Task31.h"

namespace AOC
{
    std::string Task31::solution()
    {
        const int strideX = 3;
        const int strideY = 1;

        const auto in = *readWithCustomReader(CustomReaders::task3Reader);
        const auto& [l, w, h] = in;

        int count = 0;
        int x = strideX; // Assume that width is at least strideX + 1
        int y = strideY;

        while (y < h)
        {
            if (l[y][x] == '#')
                count++;

            x += strideX;
            x %= w;
            y += strideY;
        }

        return std::to_string(count);
    }
}
