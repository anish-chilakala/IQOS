#pragma once

#include "vex.h"
#include "iqos/hal/battery.hpp"
#include "iqos/events/event_bus.hpp"
#include "iqos/hal/screen.hpp"
#include <string>
#include <vector>


namespace iqos {
namespace power {
    class IdleMode {
        
        public:
IdleMode(EventBus& eventBus, Screen& screen, uint32_t idleTimeout); 
        // Function Declerations here
void update();
void resetActivity();
bool isIdleMode();

        private:
        // Private Declarations for battery management
EventBus& eventBus;
Screen& screen;
uint32_t idleTimeout;
uint32_t lastActivityTime;
bool isIdle;

        
    };

} // namespace power
} // namespace iqos