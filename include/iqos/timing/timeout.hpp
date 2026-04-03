#pragma once

#include "vex.h"

namespace iqos {
namespace timing {

class Timeout {
public:
    Timeout(uint32_t limitMs);
    
    //Calling the functions
    void start();
    void reset();
    bool isExpired();

private:
    //Defining variables
    uint32_t timeLimit;
    uint32_t timeoutStart;
    bool timeoutActive;
};
} // namespace timing
} // namespace iqos
