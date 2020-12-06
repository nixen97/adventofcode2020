#include <iostream>
#include <unordered_map>

#include "Task.h"
#include "Tasks/Task11.h"
#include "Tasks/Task12.h"
#include "Tasks/Task21.h"
#include "Tasks/Task22.h"
#include "Tasks/Task31.h"
#include "Tasks/Task32.h"
#include "Tasks/Task41.h"
#include "Tasks/Task42.h"

using namespace AOC;

int main(int argc, char* argv)
{
    std::unordered_map<std::string, std::string> inputs = {
        { "task1", "res/1.in" },
        { "task2", "res/2.in" },
        { "task3", "res/3.in" },
        { "task4", "res/4.in" }
    };

    std::vector<Task*> tasks = {
        new Task11(inputs["task1"]),
        new Task12(inputs["task1"]),
        new Task21(inputs["task2"]),
        new Task22(inputs["task2"]),
        new Task31(inputs["task3"]),
        new Task32(inputs["task3"]),
        new Task41(inputs["task4"]),
        new Task42(inputs["task4"])
    };

    for (Task* task : tasks)
    {
        task->addSolutionToStream(std::cout);
    }

    // Cleanup
    for (Task* task : tasks)
    {
        delete task;
    }

    return 0;
}
