#include "vex.h"
#include "iqos/hal/distance.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace hal {
Distance::Distance(uint8_t port) {
    //Vex IQ distance sensor initialization
    distanceSensor = vex::distance(port);
}

double Distance::getDistanceMM() {
    // Get the current distance in millimeters from the distance sensor
    return distanceSensor.objectDistance(mm);
}

double Distance::getDistanceInches() {
    // Get the current distance in inches from the distance sensor
    return getDistanceMM() / 25.4;
}

bool Distance::isObjectDetected() {
    // Check if an object is detected within the sensor's range
    return distanceSensor.isObjectDetected();
}

double Distance::getSignalStrength() {
    // Get the signal strength of the detected object (if supported by the sensor)
    return distanceSensor.signalStrength();
}


} //namespace hal
} //namespace iqos