#include "iqos/errors/recovery.hpp"

#include "vex.h"
#include "iqos/timing/system_clock.hpp"
using namespace vex;
extern vex::brain Brain;

namespace iqos {
namespace errors {

    Recovery::Recovery(EventBus& eventBus, Motor& motor) : eventBus(eventBus), motor(motor) {
        //Initializes Automatically
    }

    bool Recovery::attemptRecovery(ErrorCode code) {
    switch (code) {
    case ErrorCode::MOTOR_STALL:
        handleMotorStall();
        return true;
    case ErrorCode::MOTOR_OVERHEAT:
        handleOverheat();
        return true;
    default:
        return false;
    }
    }

    void Recovery::handleMotorStall() {
    double previousVelocity = motor.getVelocity(); // save current velocity
    motor.setVelocity(0);
    SystemClock::delay(500);
    motor.setVelocity(previousVelocity); // restore original velocity
    }

void Recovery::handleOverheat() {
    double previousVelocity = motor.getVelocity(); // save current velocity
    while (motor.isOverheating()) {
        motor.setVelocity(20);
        SystemClock::delay(1000);
    }
    motor.setVelocity(previousVelocity); // restore original velocity
    }


} // namespace errors
} // namespace iqos
