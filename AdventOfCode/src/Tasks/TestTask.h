#pragma once
#include "../Task.h"

namespace AOC
{
    class TestTask : public Task
    {
    public:
        TestTask(const std::string& path)
            : Task(0, 0, path)
        {
        }

        ~TestTask() override = default;

    private:
        std::string solution() override;

    };    
}
