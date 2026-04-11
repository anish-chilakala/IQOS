#pragma once

#include "vex.h"
#include "iqos/events/event_bus.hpp"
#include "iqos/hal/motor.hpp"
#include <string>
#include <vector>


namespace iqos {
namespace events {
    class MotorEvents {
        public:
        MotorEvents(EventBus& eventBus, Motor& motor);
        //Function Declarations here
        void update();


        private:
        //Private variables for management here
        EventBus& eventBus;
        Motor& motor;

    };
    
} //namespace events
} //namespace iqos