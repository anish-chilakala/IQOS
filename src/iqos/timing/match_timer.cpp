#include "vex.h"
#include "iqos/timing/system_clock.hpp"
#include "iqos/timing/match_timer.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace timing {

    MatchTimer::MatchTimer() {
    startTime = 0;
    timerRunning = false;
    elapsedTime = 0;
    }

    uint32_t MatchTimer::getElapsedMs() {
        if (timerRunning) {
            uint32_t currentTime = SystemClock::milliseconds();
            return elapsedTime + (currentTime - startTime);
        }
        return elapsedTime;
    }

    double MatchTimer::getElapsedSeconds() {
        return getElapsedMs() / 1000.0;
    }

    bool MatchTimer::isRunning() {
        return timerRunning;
    }

    void MatchTimer::start() {
        if (!timerRunning) {
            timerRunning = true;
            startTime = SystemClock::milliseconds();
        }
    }

    void MatchTimer::stop() {
        if (timerRunning) {
            uint32_t currentTime = SystemClock::milliseconds();
            elapsedTime += (currentTime - startTime);
            timerRunning = false;
        }
    }

    void MatchTimer::reset() {
        timerRunning = false;
        elapsedTime = 0;
        startTime = 0;
    }

} // namespace timing
} // namespace iqos