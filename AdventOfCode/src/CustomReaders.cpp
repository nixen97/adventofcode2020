#include "CustomReaders.h"

#include <fstream>
#include <iostream>
#include <sstream>

namespace AOC
{
    Task4Data::Task4DataField Task4Data::getFieldFromStringIdent(const std::string& ident)
    {
        if (ident == "byr")
            return Task4DataField::BYR;
        if (ident == "iyr")
            return Task4DataField::IYR;
        if (ident == "eyr")
            return Task4DataField::EYR;
        if (ident == "hgt")
            return Task4DataField::HGT;
        if (ident == "hcl")
            return Task4DataField::HCL;
        if (ident == "ecl")
            return Task4DataField::ECL;
        if (ident == "pid")
            return Task4DataField::PID;
        if (ident == "cid")
            return Task4DataField::CID;

        return Task4DataField::NONE;
    }

    std::shared_ptr<std::vector<std::tuple<int, int, char, std::string>>> CustomReaders::task2Reader(const std::string& path)
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

    std::shared_ptr<std::tuple<std::vector<std::vector<char>>, size_t, size_t>> CustomReaders::task3Reader(const std::string &path)
    {
        std::ifstream fStream;

        fStream.open(path);

        if (!fStream.is_open())
            return nullptr;

        std::vector<std::vector<char>> outVec;

        size_t width = 0;
        size_t height = 0;
        
        std::string line;

        while (std::getline(fStream, line))
        {
            std::istringstream iss(line);

            std::vector<char> tmp;

            std::copy(
                std::istream_iterator<char>(iss),
                std::istream_iterator<char>(),
                std::back_inserter(tmp)
            );

            width = tmp.size();
            height++;

            outVec.push_back(tmp);
        }

        auto out = std::make_shared<std::tuple<std::vector<std::vector<char>>, size_t, size_t>>();

        *out = { std::move(outVec), width, height };

        return out;
    }

    void CustomReaders::parseField(const std::string& temp, Task4Data& data)
    {
        std::string unit;

        const auto split = temp.find(':'); // Don't bounds check, just fail if not found. Should always be 3.
        const auto ident = temp.substr(0, split);
        const auto value = temp.substr(split + 1, temp.size() - split - 1);

        switch (Task4Data::getFieldFromStringIdent(ident))
        {
        case Task4Data::Task4DataField::BYR: 
            data.byr = std::stoi(value);
            break;
        case Task4Data::Task4DataField::IYR: 
            data.iyr = std::stoi(value);
            break;
        case Task4Data::Task4DataField::EYR: 
            data.eyr = std::stoi(value);
            break;
        case Task4Data::Task4DataField::HGT: 
            data.hgt = std::stoi(value);
            unit = value.substr(value.size() - 2, value.size());
            if (unit == "cm")
                data.hgtUnit = Task4Data::HeightUnit::CM;
            if (unit == "in")
                data.hgtUnit = Task4Data::HeightUnit::IN;
            break;
        case Task4Data::Task4DataField::HCL: 
            data.hcl = value;
            break;
        case Task4Data::Task4DataField::ECL: 
            data.ecl = value;
            break;
        case Task4Data::Task4DataField::PID:
            data.pid = value;
            break;
        case Task4Data::Task4DataField::CID:
            data.cid = std::stoi(value);
            break;
        case Task4Data::Task4DataField::NONE:
            exit(69); // Fail a lot. Input is broken.
        }
    }

    std::shared_ptr<std::vector<Task4Data>> CustomReaders::task4Reader(const std::string& path)
    {
        std::ifstream fStream;

        fStream.open(path);

        if (!fStream.is_open())
            return nullptr;

        auto out = std::make_shared<std::vector<Task4Data>>();

        std::string line;
        std::string temp;

        while (!fStream.eof())
        {
            Task4Data data;

            std::getline(fStream, line);

            while (!line.empty())
            {
                std::stringstream sStream(line);

                while (!sStream.eof())
                {
                    sStream >> temp;

                    parseField(temp, data);
                }
                std::getline(fStream, line);
            }

            out->push_back(data);
        }

        return out;
    }
}
