/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       system_clock.cpp                                          */
/*    Author:       Anish Chilakala                                           */
/*    Created:      4/2/2026                                                  */
/*    Description:  IQOS System Clock Implementation                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "iqos/timing/system_clock.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace timing {

uint32_t SystemClock::milliseconds() {
    return Brain.Timer.time(msec);
}

uint64_t SystemClock::microseconds() {
    return Brain.Timer.time(msec) * 1000;
}

double SystemClock::seconds() {
    return Brain.Timer.time(sec);
}

void SystemClock::delay(uint32_t ms) {
    this_thread::sleep_for(ms);
}

} // namespace timing
} // namespace iqos