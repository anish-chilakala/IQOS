#pragma once

#include "vex.h"
#include <string>
#include <vector>
#include "iqos/scheduler/task_manager.hpp"
#include "iqos/scheduler/task_priorities.hpp"

namespace iqos {
namespace scheduler {

    class TaskQueue {
        public:
        TaskQueue();
    // Function declarations for task management
    void enqueue(Task task);
    Task dequeue();
    Task peek();
    bool isEmpty();
    uint32_t size();


    private:
    // Variables for task management
    std::vector<Task> queue;

    };


} // namespace scheduler
} // namespace iqos
