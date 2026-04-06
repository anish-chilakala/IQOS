#pragma once

#include "vex.h"
#include <string>
#include <vector>
#include "iqos/scheduler/task_priorities.hpp"

namespace iqos {
namespace scheduler {

class Semaphore {
    public:
Semaphore(int maxCount);
// Function Declerations here
void wait();
void signal();
int getCount();
    private:
// Private variables here
int count;
};
    

} // namespace scheduler
} // namespace iqos