#pragma once

#include "vex.h"
#include "iqos/events/event_bus.hpp"
#include "iqos/hal/port_manager.hpp"
#include <string>
#include <vector>


namespace iqos {
namespace events {
    class UserEvents {
        public:
        UserEvents(EventBus& eventBus);
        //Public Function Declarations
        void registerEvent(std::string eventName);
        void fireEvent(std::string eventName);
        bool isRegistered(std::string eventName);


        private:
        // Private declarations here
        EventBus& eventBus;
        std::vector<std::string> registeredEvents;
        


    };
    
} //namespace events
} //namespace iqos