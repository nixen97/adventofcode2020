#pragma once
#include <memory>
#include <string>
#include <vector>

namespace AOC
{
    struct Task4Data
    {
        enum class HeightUnit
        {
            INVALID = -1,
            CM,
            IN
        };

        int byr = -1;
        int iyr = -1;
        int eyr = -1;
        int hgt = -1;
        HeightUnit hgtUnit = HeightUnit::INVALID;
        std::string hcl;
        std::string ecl;
        std::string pid;
        int cid = -1;

        enum class Task4DataField
        {
            NONE = -1,
            BYR,
            IYR,
            EYR,
            HGT,
            HCL,
            ECL,
            PID,
            CID
        };

        static Task4DataField getFieldFromStringIdent(const std::string& ident);
    };

    class CustomReaders
    {
    public:
        static std::shared_ptr<std::vector<std::tuple<int, int, char, std::string>>> task2Reader(const std::string& path);
        static std::shared_ptr<std::tuple<std::vector<std::vector<char>>, size_t, size_t>> task3Reader(const std::string &path);
        static std::shared_ptr<std::vector<Task4Data>> task4Reader(const std::string& path);

    private:
        static void parseField(const std::string& temp, Task4Data& data);
    };
}
