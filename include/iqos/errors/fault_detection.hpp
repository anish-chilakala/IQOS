#pragma once

#include "vex.h"
#include <string>
#include <vector>
#include "iqos/events/event_bus.hpp"
#include "iqos/hal/motor.hpp"


namespace iqos {
namespace errors {
class FaultDetection {
    public:
    FaultDetection(EventBus& eventBus, Motor& motor);
    //Function Declarations here
    void update();

    private:
    //Private Variable Declarations
    EventBus& eventBus;
    Motor& motor;   
bool stallReported;
bool overheatReported;
bool disconnectReported;

};

} // namespace errors
} // namespace iqos