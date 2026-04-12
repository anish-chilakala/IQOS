#pragma once

#include "vex.h"
#include "iqos/events/event_bus.hpp"
#include "iqos/hal/motor.hpp"
#include "iqos/errors/error_codes.hpp"
#include <string>
#include <vector>



namespace iqos {
namespace errors {
class Recovery {
    public:
    Recovery(EventBus& eventBus, Motor& motor);
    //Function Declarations here
    bool attemptRecovery(ErrorCode code);
    void handleMotorStall();
    void handleOverheat();

    private:
    //Private Variable Declarations
    EventBus& eventBus;
    Motor& motor;
    

};

} // namespace errors
} // namespace iqos