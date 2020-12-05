#include <iostream>
#include <unordered_map>

#include "Task.h"
#include "Tasks/Task11.h"
#include "Tasks/Task12.h"
#include "Tasks/Task21.h"
#include "Tasks/Task22.h"

using namespace AOC;

int main(int argc, char* argv)
{
    std::unordered_map<std::string, std::string> inputs = {
        { "task1", "res/1.in" },
        { "task2", "res/2.in" }
    };

    std::vector<Task*> tasks = {
        new Task11(inputs["task1"]),
        new Task12(inputs["task1"]),
        new Task21(inputs["task2"]),
        new Task22(inputs["task2"])
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
