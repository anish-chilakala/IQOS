#pragma once

#include "vex.h"
#include "iqos/hal/battery.hpp"
#include "iqos/events/event_bus.hpp"
#include "iqos/hal/screen.hpp"
#include "iqos/hal/motor.hpp"
#include <string>
#include <vector>


namespace iqos {
namespace power {
    class ThermalThrottle {
        
        public:
        ThermalThrottle(EventBus& eventBus, Motor& motor, double tempThreshold);
 // Function Declerations here
void update();
bool isThrottling();
void setThreshold(double threshold);


        private:
// Private Declarations for battery management
EventBus& eventBus;
Motor& motor;
double tempThreshold;
bool throttling;
double originalVelocity;

        
    };

} // namespace power
} // namespace iqos