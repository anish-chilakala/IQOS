/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       delta_time.hpp                                            */
/*    Author:       Anish Chilakala                                           */
/*    Created:      4/2/2026                                                  */
/*    Description:  IQOS Delta Time - Time between loop iterations           */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#pragma once

#include "vex.h"
#include "iqos/timing/system_clock.hpp"

namespace iqos {
namespace timing {

/**
 * DeltaTime
 * 
 * Tracks the time between loop iterations.
 * Used by PID controllers and motion profiling
 * to make calculations time-accurate.
 * 
 * Usage:
 *   iqos::timing::DeltaTime dt;
 *   dt.update();
 *   double elapsed = dt.getSeconds();
 */
class DeltaTime {
public:

    /**
     * Constructor - initializes the timer
     */
    DeltaTime();

    /**
     * Call this once per loop iteration
     * Updates the delta time calculation
     */
    void update();

    /**
     * Returns delta time in milliseconds
     */
    double getMilliseconds() const;

    /**
     * Returns delta time in seconds
     */
    double getSeconds() const;

    /**
     * Resets the delta time back to zero
     */
    void reset();

private:
    uint32_t previousTime;
    double deltaMs;
};

} // namespace timing
} // namespace iqos