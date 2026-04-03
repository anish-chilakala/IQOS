#pragma once

#include "vex.h"

namespace iqos {
namespace timing {

class HiResTimer {
public:
//Calling the functions
    void start();
    void stop();
    void reset();
    double getElapsedMs();

private:
    //Defining variables 
    uint32_t startTime;
    double elapsedTime;
    bool isTimerRunning;
};

} // namespace timing
} // namespace iqos

