
#include "vex.h"
#include "iqos/scheduler/task_manager.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace scheduler {

TaskManager::TaskManager() {
    // nothing to initialize, tasks vector starts empty automatically
}

void TaskManager::addTask(std::string name, void (*taskFunction)(), TaskPriority priority, uint32_t intervalMs) {
    // create a new task struct with the provided information
    Task newTask;
    newTask.name = name;
    newTask.priority = priority;
    newTask.intervalMs = intervalMs;
    newTask.isRunning = true;
    newTask.thread = new vex::task(taskFunction);

    // add the new task to the list
    tasks.push_back(newTask);
}

void TaskManager::removeTask(std::string name) {
    // loop through all tasks to find the one with the matching name
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].name == name) {
            // stop the thread before removing
            tasks[i].thread->stop();
            // remove from the list
            tasks.erase(tasks.begin() + i);
            return;
        }
    }
}

void TaskManager::pauseTask(std::string name) {
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].name == name) {
            tasks[i].thread->suspend();
            tasks[i].isRunning = false;
            return;
        }
    }
}

void TaskManager::resumeTask(std::string name) {
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].name == name) {
            tasks[i].thread->resume();
            tasks[i].isRunning = true;
            return;
        }
    }
}

void TaskManager::setTaskPriority(std::string name, TaskPriority priority) {
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].name == name) {
            tasks[i].priority = priority;
            return;
        }
    }
}

bool TaskManager::isTaskRunning(std::string name) {
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].name == name) {
            return tasks[i].isRunning;
        }
    }
    // task not found
    return false;
}


} // namespace scheduler
} // namespace iqos