#pragma once

#include "vex.h"

namespace iqos {
namespace timing {
class CountdownTimer {
    public:

    CountdownTimer();
    
    // Function declarations
    void start(uint32_t durationMs);
    void stop();
    void reset();
    uint32_t getRemainingMs();
    double getRemainingSeconds();
    bool isRunning();
    bool isExpired();



    private:
    // Variable declarations
    uint32_t startTime;
    bool timerRunning;
    uint32_t duration;
};

} // namespace timing
} // namespace iqos
