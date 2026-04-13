

#include "vex.h"
#include "iqos/power/thermal_throttle.hpp"
#include "iqos/timing/system_clock.hpp"
using namespace vex;
extern vex::brain Brain;

namespace iqos {
namespace power{

ThermalThrottle::ThermalThrottle(EventBus& eventBus, Motor& motor, double tempThreshold) : eventBus(eventBus), motor(motor), tempThreshold(tempThreshold) {
    isThrottling = false;
}

void ThermalThrottle::update() {
double temperature = motor.getTemperature();

if (temperature > tempThreshold && !throttling) {
    originalVelocity = motor.getVelocity(); // save current velocity
    throttling = true;
    motor.setVelocity(originalVelocity * 0.5); // reduce to 50% of original
    eventBus.fire("THERMAL_THROTTLE_START");
} else if (temperature <= tempThreshold && throttling) {
    throttling = false;
    motor.setVelocity(originalVelocity); // restore original
    eventBus.fire("THERMAL_THROTTLE_END");
}
}

bool ThermalThrottle::isThrottling() {
    return throttling;
}

void ThermalThrottle::setThreshold(double threshold) {
tempThreshold = threshold;
}

} // namespace power
} // namespace iqos
