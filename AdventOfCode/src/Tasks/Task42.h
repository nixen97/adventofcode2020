#pragma once
#include "../Task.h"

namespace AOC
{
    class Task42 : public Task
    {
    private:
        static inline std::array<std::string, 7> s_ValidEyeColours = { "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };

    public:
        explicit Task42(const std::string& input)
            : Task(4, 2, input)
        {
        }

        ~Task42() override = default;
        
    private:
        std::string solution() override;

        static bool validPassport(const Task4Data& data);
    };
}
