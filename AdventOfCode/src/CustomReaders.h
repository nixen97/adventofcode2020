#pragma once
#include <memory>
#include <string>
#include <vector>

namespace AOC
{
    class CustomReaders
    {
    public:
        static std::shared_ptr<std::vector<std::tuple<int, int, char, std::string>>> Task2Reader(std::string path);
    };
}
