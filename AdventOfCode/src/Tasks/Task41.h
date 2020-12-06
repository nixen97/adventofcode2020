#pragma once
#include "../Task.h"

namespace AOC
{
    class Task41 : public Task
    {
    public:
        explicit Task41(const std::string& input)
            : Task(4, 1, input)
        {
        }

        ~Task41() override = default;
        
    private:
        std::string solution() override;

        static bool validPassport(const Task4Data& data);
    };
}
