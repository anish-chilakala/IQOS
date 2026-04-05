#include "vex.h"
#include "iqos/scheduler/task_queue.hpp"
#include <vector>

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace scheduler {

TaskQueue::TaskQueue() {
    // starts automatically, nothing to initialize
}

void TaskQueue::enqueue(Task task) {
    queue.push_back(task);
}

Task TaskQueue::dequeue() {
    Task first = queue[0];
    queue.erase(queue.begin());
    return first;
}

Task TaskQueue::peek() {
    return queue[0];
}

bool TaskQueue::isEmpty() {
    return queue.empty();
}

uint32_t TaskQueue::size() {
    return queue.size();
}

} // namespace scheduler
} // namespace iqos