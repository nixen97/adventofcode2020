#pragma once
#include "../Task.h"

namespace AOC
{
    class Task22 : public Task
    {
    public:
        explicit Task22(const std::string& input)
            : Task(2, 2, input)
        {
        }

        ~Task22() override = default;
        
    private:
        std::string solution() override;
    };
}
