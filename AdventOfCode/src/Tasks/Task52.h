#pragma once
#include "../Task.h"

namespace AOC
{
    class Task52 : public Task
    {
    public:
        explicit Task52(const std::string& input)
            : Task(5, 2, input)
        {
        }

        ~Task52() override = default;
        
    private:
        std::string solution() override;
    };
}
