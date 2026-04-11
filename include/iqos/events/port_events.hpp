#pragma once

#include "vex.h"
#include "iqos/events/event_bus.hpp"
#include "iqos/hal/port_manager.hpp"
#include <string>
#include <vector>


namespace iqos {
namespace events {
    class PortEvents {
        public:
        PortEvents(EventBus& eventbus, PortManager& PortManager);
        //Function Declarations go here
        void update();


        private:
        //Private Declarations go here
        std::vector<DeviceType> previousStates;
        EventBus& eventBus;
        PortManager& portManager;


    };
    
} //namespace events
} //namespace iqos