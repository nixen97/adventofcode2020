#pragma once
#include "../Task.h"

namespace AOC
{
    class Task51 : public Task
    {
    public:
        explicit Task51(const std::string& input)
            : Task(5, 1, input)
        {
        }

        ~Task51() override = default;
        
    private:
        std::string solution() override;
    };
}
