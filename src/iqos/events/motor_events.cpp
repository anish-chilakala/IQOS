#include "vex.h"
#include "iqos/events/event_bus.hpp"
#include "iqos/hal/motor.hpp"
#include "iqos/events/motor_events.hpp"



using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace events {
    MotorEvents::MotorEvents(EventBus& eventBus, Motor& motor) : eventBus(eventBus), motor(motor) {
// nothing to initialize, starts automatically
    }

    void MotorEvents::update() {
        if (motor.isStalled()) {
            eventBus.fire("MOTOR_STALLED");
        }

        if (motor.isOverheating()) {
            eventBus.fire("MOTOR_OVERHEATING");
        }
    }
} // namespace events
} // namespace iqos