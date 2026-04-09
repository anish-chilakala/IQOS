#include "vex.h"
#include "iqos/hal/distance.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace hal {
Distance::Distance(uint8_t port) {
    //Vex IQ distance sensor initialization
    DistanceSensor = vex::distance(port);
}

double distance::getDistanceMM() {
    // Get the current distance in millimeters from the distance sensor
    return DistanceSensor.objectDistance(mm);
}

double distance::getDistanceInches() {
    // Get the current distance in inches from the distance sensor
    return getDistanceMM() / 25.4;
}

bool distance::isObjectDetected() {
    // Check if an object is detected within the sensor's range
    return DistanceSensor.isObjectDetected();
}

double distance::getSignalStrength() {
    // Get the signal strength of the detected object (if supported by the sensor)
    return DistanceSensor.signalStrength();
}


} //namespace hal
} //namespace iqos