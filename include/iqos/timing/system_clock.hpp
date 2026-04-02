/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       system_clock.hpp                                          */
/*    Author:       Anish Chilakala                                           */
/*    Created:      4/2/2026                                                  */
/*    Description:  IQOS System Clock - Master clock for the entire OS       */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#pragma once

#include "vex.h"

namespace iqos {
namespace timing {

/**
 * SystemClock
 * 
 * The master clock for the entire IQOS operating system.
 * Every module that needs time should use this, never call
 * vex time functions directly.
 * 
 * Usage:
 *   uint32_t ms = iqos::timing::SystemClock::milliseconds();
 *   uint64_t us = iqos::timing::SystemClock::microseconds();
 */
class SystemClock {
public:

    /**
     * Returns milliseconds since the brain turned on
     */
    static uint32_t milliseconds();

    /**
     * Returns microseconds since the brain turned on
     */
    static uint64_t microseconds();

    /**
     * Returns seconds since the brain turned on
     */
    static double seconds();

    /**
     * Blocks the current task for a given number of milliseconds
     */
    static void delay(uint32_t ms);

private:
    // SystemClock is a static utility class, no instances allowed
    SystemClock() = delete;
};

} // namespace timing
} // namespace iqos