#pragma once

#include "vex.h"
#include "iqos/hal/battery.hpp"
#include "iqos/events/event_bus.hpp"
#include <string>
#include <vector>


namespace iqos {
namespace power {
    class BatteryMonitor {
        
        public:
BatteryMonitor(EventBus& eventBus, Battery& battery);     
        // Function Declerations here
void update();
double getDrainRate();
uint8_t getLevel();
       
        private:
        // Private Declarations for battery management
EventBus& eventBus;
Battery& battery;
uint8_t previousLevel;
double drainRate;
        
    };

} // namespace power
} // namespace iqos