#include "iqos/errors/fault_detection.hpp"



namespace iqos {
namespace errors {

   FaultDetection::FaultDetection(EventBus& eventBus, Motor& motor) : eventBus(eventBus), motor(motor) {
    stallReported = false;
    overheatReported = false;
    disconnectReported = false;
}

   void FaultDetection::update() {
    
    if (motor.isStalled() && !stallReported) {
    eventBus.fire("MOTOR_STALL");
    stallReported = true;
    }
    if (!motor.isStalled()) {
    stallReported = false; // reset when fault clears
    }

    if (motor.isOverheating() && !overheatReported) {
    eventBus.fire("MOTOR_OVERHEAT");
    overheatReported = true;
    }
    if (!motor.isOverheating()) {
    overheatReported = false; // reset when fault clears
    }
   

   if (!motor.isInstalled() && !disconnectReported) {
    eventBus.fire("MOTOR_DISCONNECT");
    disconnectReported = true;
    }
    if (motor.isInstalled()) {
    disconnectReported = false;
    }

}



} // namespace errors
} // namespace iqos
