#include "vex.h"
#include "iqos/hal/optical.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace hal {
Optical::Optical(uint8_t port) {
    //Vex IQ optical sensor initialization
    opticalSensor = vex::optical(port);
}

double Optical::getHue() {
    // Get the current hue value from the optical sensor
    return opticalSensor.hue();
}

double Optical::getSaturation() {
    // Get the current saturation value from the optical sensor
    return opticalSensor.saturation();
}

double Optical::getBrightness() {
    // Get the current brightness value from the optical sensor
    return opticalSensor.brightness();
}

double Optical::getProximity() {
    // Get the current proximity value from the optical sensor
    return opticalSensor.proximity();
}

bool Optical::isObjectDetected() {
    // Check if an object is detected within the sensor's range
    return opticalSensor.isNearDetected();
}

}//namespace hal
}//namespace iqos