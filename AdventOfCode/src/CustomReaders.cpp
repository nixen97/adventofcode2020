#include "CustomReaders.h"

#include <fstream>

namespace AOC
{
    std::shared_ptr<std::vector<std::tuple<int, int, char, std::string>>> CustomReaders::Task2Reader(std::string path)
    {
        auto out = std::make_shared<std::vector<std::tuple<int, int, char, std::string>>>();

        std::ifstream fileStream;

        fileStream.open(path);

        if (!fileStream.is_open())
            return nullptr;

        int from, to;
        char character;
        std::string password;

        while (!fileStream.eof())
        {
            fileStream >> from;
            fileStream.ignore(1);
            fileStream >> to;

            fileStream >> character;

            fileStream.ignore(1);

            fileStream >> password;

            out->push_back({
                from,
                to,
                character,
                std::move(password)
            });
        }

        return out;
    }
}
