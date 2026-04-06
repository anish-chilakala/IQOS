#include "vex.h"
#include "iqos/scheduler/semaphore.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace scheduler {

 Semaphore::Semaphore(int maxCount) {
    count = maxCount;
 }

void Semaphore::wait(){
while (count == 0) {
    vex::task::sleep(1); // Sleep for a short time to prevent busy waiting
}
count--;
}

void Semaphore::signal(){
count++;
}

int Semaphore::getCount() {
    return count;
}




} // namespace scheduler
} // namespace iqos