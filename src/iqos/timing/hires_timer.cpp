#include "vex.h"
#include "iqos/timing/system_clock.hpp"
#include "iqos/timing/hires_timer.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace timing {

void HiResTimer::start() {
    isTimerRunning = true;
    startTime = SystemClock::milliseconds();
}

void HiResTimer::stop() {
    isTimerRunning = false;
    uint32_t endTime = SystemClock::milliseconds();
    elapsedTime += (endTime - startTime);
}

void HiResTimer::reset() {
    isTimerRunning = false;
    elapsedTime = 0;
}

double HiResTimer::getElapsedMs() {
    // what happens when elapsed time is requested
    return elapsedTime;
}

} // namespace timing
} // namespace iqos