#pragma once

#include "vex.h"
#include <string>
#include <vector>


namespace iqos {
namespace hal {
class Distance {
    public:
    Distance(uint8_t port);
    // Function Declerations here
    double getDistanceMM();
    double getDistanceInches();
    bool isObjectDetected();
    double getSignalStrength();

    private:
    // Private Declarations for Distance Sensor management
    uint8_t port; // Port number for the distance sensor
    vex::distance distanceSensor; // VEX distance sensor object
};
} //namespace hal
} //namespace iqos