#pragma once

#include "vex.h"
#include <string>
#include <vector>
#include "iqos/scheduler/task_priorities.hpp"

namespace iqos {
namespace scheduler {

struct Task {
    std::string name;
    TaskPriority priority;
    uint32_t intervalMs;
    bool isRunning;
    vex::task* thread;
};

class TaskManager {
public:
    TaskManager();
    void addTask(std::string name, void (*taskFunction)(), TaskPriority priority, uint32_t intervalMs);
    void removeTask(std::string name);
    void pauseTask(std::string name);
    void resumeTask(std::string name);
    void setTaskPriority(std::string name, TaskPriority priority);
    bool isTaskRunning(std::string name);

private:
    std::vector<Task> tasks;
};

} // namespace scheduler
} // namespace iqos