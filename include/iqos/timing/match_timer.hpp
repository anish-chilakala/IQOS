#pragma once

#include "vex.h"

namespace iqos {
namespace timing {

class MatchTimer {
    public:

    MatchTimer();
    
    //Function declarations
    uint32_t getElapsedMs();
    double getElapsedSeconds();
    bool isRunning();
    void start();
    void stop();
    void reset();
    
    private:
    //Variable declarations
    uint32_t startTime;
    bool timerRunning;
    uint32_t elapsedTime;
};

} // namespace timing
} // namespace iqos