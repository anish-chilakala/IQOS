#pragma once

#include "vex.h"
#include "iqos/hal/battery.hpp"
#include "iqos/events/event_bus.hpp"
#include <string>
#include <vector>


namespace iqos {
namespace power {
    class PowerLimiter {
        
        public:
PowerLimiter(EventBus& eventBus, double maxPower);   
        // Function Declerations here
void setLimit(double limit);
double getLimit();
double enforceLimit(double requestedVelocity);
bool isOverLimit(double currentPower);

       
        private:
        // Private Declarations for battery management
        EventBus& eventBus;
        double powerLimit;

        
    };

} // namespace power
} // namespace iqos