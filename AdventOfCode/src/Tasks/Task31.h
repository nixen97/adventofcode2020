#pragma once
#include "../Task.h"

namespace AOC
{
    class Task31 : public Task
    {
    public:
        explicit Task31(const std::string& input)
            : Task(3, 1, input)
        {
        }

        ~Task31() override = default;
        
    private:
        std::string solution() override;
    };
}
