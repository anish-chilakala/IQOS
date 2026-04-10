#pragma once

#include "vex.h"
#include "iqos/events/event_bus.hpp"
#include "iqos/hal/controller.hpp"
#include <string>
#include <vector>


namespace iqos {
namespace events {
class ButtonEvents {
    public:
    ButtonEvents(EventBus& eventBus, Controller& controller);
    // Function Declerations here
    void update();

    private:
    // Private Declarations for ButtonEvents management
    EventBus& eventBus;
    Controller& controller;
};

} // namespace events
} // namespace iqos