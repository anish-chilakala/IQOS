#include "vex.h"
#include "iqos/scheduler/task_manager.hpp"
#include "iqos/timing/system_clock.hpp"
#include "iqos/scheduler/task_watchdog.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace scheduler {

TaskWatchdog::TaskWatchdog() {
}

void TaskWatchdog::registerTask(std::string name, uint32_t timeoutMs) {
    WatchedTask newWatchedTask;
    newWatchedTask.name = name;
    newWatchedTask.timeoutMs = timeoutMs;
    newWatchedTask.lastCheckIn = SystemClock::milliseconds();
    newWatchedTask.isActive = true;
    watchedTasks.push_back(newWatchedTask);
}

void TaskWatchdog::checkIn(std::string name) {
    for (int i = 0; i < watchedTasks.size(); i++) {
        if (watchedTasks[i].name == name) {
            watchedTasks[i].lastCheckIn = SystemClock::milliseconds();
            return;
        }

    }
}

void TaskWatchdog::unregister(std::string name) {
    for (int i=0; i < watchedTasks.size(); i++) {
        if (watchedTasks[i].name == name) {
            watchedTasks.erase(watchedTasks.begin() + i);
            return;
        }
    }
}

void TaskWatchdog::update() {
    // loop through all watched tasks
    uint32_t currentTime = SystemClock::milliseconds();
    for (int i = 0; i < watchedTasks.size(); i++) {
        if (watchedTasks[i].isActive) {
            uint32_t timeSinceCheckIn = currentTime - watchedTasks[i].lastCheckIn;
            if (timeSinceCheckIn > watchedTasks[i].timeoutMs) {
                // task is frozen — log this later when logging system is built
                watchedTasks[i].lastCheckIn = currentTime;
            }
        }
    }
}

} //namespace scheduler
} //namespace iqos
    
