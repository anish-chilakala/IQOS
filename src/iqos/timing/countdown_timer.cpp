#include "vex.h"
#include "iqos/timing/system_clock.hpp"
#include "iqos/timing/countdown_timer.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace timing {

    CountdownTimer::CountdownTimer() {
    startTime = 0;
    timerRunning = false;
    duration = 0;
    }

    void CountdownTimer::start(uint32_t durationMs) {
        duration = durationMs;
        startTime = SystemClock::milliseconds();
        timerRunning = true;
    }

    void CountdownTimer::stop() {
        timerRunning = false;
    }

    void CountdownTimer::reset() {
        timerRunning = false;
        startTime = 0;
        duration = 0;
    }

    uint32_t CountdownTimer::getRemainingMs() {
        if (timerRunning) {
            uint32_t currentTime = SystemClock::milliseconds();
            uint32_t elapsedTime = currentTime - startTime;
            return (elapsedTime >= duration) ? 0 : (duration - elapsedTime);
        }
        return duration;
    }

    double CountdownTimer::getRemainingSeconds() {
        return getRemainingMs() / 1000.0;
    }

    bool CountdownTimer::isRunning() {
        return timerRunning;
    }

    bool CountdownTimer::isExpired() {
        return getRemainingMs() == 0;
    }

} // namespace timing
} // namespace iqos
