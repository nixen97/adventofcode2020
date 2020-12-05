#pragma once
#include "../Task.h"

namespace AOC
{

    class Task12 : public Task
    {
    private:
        int m_Target = 2020;

    public:
        explicit Task12(const std::string& input)
            : Task(1, 2, input) { }

        ~Task12() override = default;

    private:
        std::string solution() override;
    
    };
}
