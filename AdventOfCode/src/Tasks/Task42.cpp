#include "Task42.h"

namespace AOC
{
    std::string Task42::solution()
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

    bool Task42::validPassport(const Task4Data& data)
    {
        if (data.byr < 1920 || data.byr > 2002)
            return false;

        if (data.iyr < 2010 || data.iyr > 2020)
            return false;

        if (data.eyr < 2020 || data.eyr > 2030)
            return false;

        if (data.hgtUnit == Task4Data::HeightUnit::INVALID)
            return false;
        if (data.hgtUnit == Task4Data::HeightUnit::CM && (data.hgt < 150 || data.hgt > 193))
            return false;
        if (data.hgtUnit == Task4Data::HeightUnit::IN && (data.hgt < 59 || data.hgt > 76))
            return false;

        if (data.hcl.size() != 7)
            return false;
        if (data.hcl[0] != '#')
            return false;
        for (char c : data.hcl.substr(1, data.hcl.size() - 1))
            if (!isalnum(c))
                return false;

        if (!std::any_of(s_ValidEyeColours.begin(), s_ValidEyeColours.end(), [data](const std::string& VEC){ return VEC == data.ecl; }))
            return false;

        if (data.pid.size() != 9)
            return false;

        return true;
    }
}