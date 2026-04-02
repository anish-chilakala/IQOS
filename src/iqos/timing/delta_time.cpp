/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       delta_time.cpp                                            */
/*    Author:       Anish Chilakala                                           */
/*    Created:      4/2/2026                                                  */
/*    Description:  IQOS Delta Time Implementation                           */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "iqos/timing/delta_time.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace timing {

DeltaTime::DeltaTime() {
    previousTime = SystemClock::milliseconds();
    deltaMs = 0.0;
}

void DeltaTime::update() {
    uint32_t currentTime = SystemClock::milliseconds();
    deltaMs = static_cast<double>(currentTime - previousTime);
    previousTime = currentTime;
}

double DeltaTime::getMilliseconds() const {
    return deltaMs;
}

double DeltaTime::getSeconds() const {
    return deltaMs / 1000.0;
}

void DeltaTime::reset() {
    previousTime = SystemClock::milliseconds();
    deltaMs = 0.0;
}

} // namespace timing
} // namespace iqos