#include "Task41.h"

namespace AOC
{
    std::string Task41::solution()
    {
        const auto passports = *readWithCustomReader(CustomReaders::task4Reader);

        int count = 0;

        for (const auto& passport : passports)
        {
            if (validPassport(passport))
                count++;
        }

        return std::to_string(count);
    }

    bool Task41::validPassport(const Task4Data& data)
    {
        if (data.byr == -1)
            return false;
        if (data.iyr == -1)
            return false;
        if (data.eyr == -1)
            return false;
        if (data.hgt == -1)
            return false;
        if (data.hcl.empty())
            return false;
        if (data.ecl.empty())
            return false;
        if (data.pid.empty())
            return false;

        return true;
    }
}
