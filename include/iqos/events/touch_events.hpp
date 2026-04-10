#pragma once

#include "vex.h"
#include "iqos/events/event_bus.hpp"
#include "iqos/hal/screen.hpp"
#include <string>
#include <vector>


namespace iqos {
namespace events {
    class TouchEvents {
        public:
        // Constructor for TouchEvents, takes references to the event bus and controller
        TouchEvents(EventBus& eventBus, Screen& screen);
        // Function declaration for updating touch events
        void update();

        private:
        // Private members for managing touch events
        EventBus& eventBus;
        Screen& screen;
        bool wasTouched; // tracks previous touch state
    };

} // namespace events
} // namespace iqos