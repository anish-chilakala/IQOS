#pragma once

#include "vex.h"
#include <string>
#include <vector>
#include "iqos/scheduler/task_priorities.hpp"

namespace iqos {
namespace scheduler {

class Mutex {
    public:
Mutex();
// Function Declerations here
void lock();
void unlock();
bool isLocked();

    private:
// Private variables here
bool locked;
};
    

} // namespace scheduler
} // namespace iqos