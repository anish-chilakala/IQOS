#include "vex.h"
#include "iqos/hal/battery.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace hal {
    Battery::Battery() {
        // Initialize the battery if needed
        lowThreshold = 20; // Default low threshold
    }

    uint8_t Battery::getLevel() {
        // Get the current battery level from the brain
        return Brain.Battery.capacity();
    }   

    bool Battery::isLow() {
        // Check if the battery level is below the low threshold
        return getLevel() < lowThreshold;
    }

    void Battery::setLowThreshold(uint8_t threshold) {
        lowThreshold = threshold;
    }

    uint8_t Battery::getLowThreshold() {
        return lowThreshold;
    }

} // namespace hal
} // namespace iqos