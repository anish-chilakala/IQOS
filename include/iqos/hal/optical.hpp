#pragma once

#include "vex.h"
#include <string>
#include <vector>


namespace iqos {
namespace hal {
class Optical {
    public:
    Optical(uint8_t port);
    // Function Declerations here
    double getHue();
    double getSaturation();
    double getBrightness();
    double getProximity();
    bool isObjectDetected();

    private:
    // Private Declarations for Optical Sensor management
    uint8_t port; // Port number for the optical sensor
    vex::optical opticalSensor; // VEX optical sensor object
};
}//namespace hal
}//namespace iqos