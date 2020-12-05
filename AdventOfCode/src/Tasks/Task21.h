#pragma once
#include "../Task.h"

namespace AOC
{
    class Task21 : public Task
    {
    public:
        explicit Task21(const std::string& input)
            : Task(2, 1, input) { }

        ~Task21() override = default;
        
    private:
        std::string solution() override;
    };
}
