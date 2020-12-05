#pragma once
#include "../Task.h"

namespace AOC
{
    class Task11 : public Task
    {
    private:
        int m_Target = 2020;

    public:
        explicit Task11(const std::string& input)
            : Task(1, 1, input) { }

        ~Task11() override = default;

    private:
        std::string solution() override;
    };
    
}
