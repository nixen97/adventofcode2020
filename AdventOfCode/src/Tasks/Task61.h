#pragma once
#include "../Task.h"

namespace AOC
{
    class Task61 : public Task
    {
    public:
        explicit Task61(const std::string& input)
            : Task(6, 1, input)
        {
        }

        ~Task61() override = default;
        
    private:
        std::string solution() override;
    };
}
