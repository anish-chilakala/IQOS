#pragma once

#include "vex.h"
#include <vector>
#include <string>
#include "iqos/scheduler/task_manager.hpp"
#include "iqos/scheduler/task_priorities.hpp"

namespace iqos {
namespace scheduler {

    struct WatchedTask {
        std::string name;
        uint32_t lastCheckIn;    
        uint32_t timeoutMs;      
        bool isActive;           
    };

    class TaskWatchdog {
    
    public:
    TaskWatchdog();
    // Function declarations for task watchdog management
    void registerTask(std::string name, uint32_t timeoutMs);
    void checkIn(std::string name);
    void unregister(std::string name);
    void update();

    private:
    // Variables for task watchdog management
    std::vector<WatchedTask> watchedTasks;

    };

} //namespace scheduler
} //namespace iqos