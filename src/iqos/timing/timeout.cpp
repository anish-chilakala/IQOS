#include "vex.h"
#include "iqos/timing/timeout.hpp"
#include "iqos/timing/system_clock.hpp"
#include "iqos/timing/hires_timer.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace timing {

    void Timeout::start() {
        timeoutActive = true;
        timeoutStart = SystemClock::milliseconds();
    }

    void Timeout::reset() {
        timeoutActive = false;
        timeoutStart = 0;
    }

    bool Timeout::isExpired() {
        if (!timeoutActive) {
            return false;
        }
        uint32_t currentTime = SystemClock::milliseconds();
        return (currentTime - timeoutStart) >= timeLimit;
    }

    Timeout::Timeout(uint32_t limitMs) {
        timeLimit = limitMs;
        timeoutStart = 0;
        timeoutActive = false;
    }

} // namespace timing
} // namespace iqos