#include "Task32.h"

namespace AOC
{
    std::string Task32::solution()
    {
        const int strideXs[5] = { 1, 3, 5, 7, 1 };
        const int strideYs[5] = { 1, 1, 1, 1, 2 };

        const auto in = *readWithCustomReader(CustomReaders::task3Reader);
        const auto& [l, w, h] = in;

        unsigned long long result = 1;

        for (int i = 0; i < 5; i++)
            result *= solution31(l, w, h, strideXs[i], strideYs[i]);

        return std::to_string(result);
    }

    int Task32::solution31(const std::vector<std::vector<char>>& l, const size_t w, const size_t h, const int strideX, const int strideY)
    {
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

        return count;
    }
}
