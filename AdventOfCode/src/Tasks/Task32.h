#pragma once
#include "../Task.h"

namespace AOC
{
    class Task32 : public Task
    {
    public:
        explicit Task32(const std::string& input)
            : Task(3, 2, input)
        {
        }

        ~Task32() override = default;
        
    private:
        std::string solution() override;
        static int solution31(const std::vector<std::vector<char>>& l, size_t w, size_t h, int strideX, int strideY);
    };
}
