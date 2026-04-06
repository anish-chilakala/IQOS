#include "vex.h"
#include "iqos/scheduler/task_manager.hpp"
#include "iqos/scheduler/mutex.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace scheduler {

    Mutex::Mutex() {
        locked = false;
    }

    void Mutex::lock() {
        while (locked) {
            vex::task::sleep(1); // Sleep for a short time to prevent busy waiting
        }
        locked = true; 
    }

    void Mutex::unlock() {
        locked = false; 
    }

    bool Mutex::isLocked() {
        return locked;
    }

} // namespace scheduler
} // namespace iqos