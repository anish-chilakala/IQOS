#include "vex.h"
#include "iqos/hal/encoder.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace hal {
    Encoder::Encoder(uint8_t port) {
        // Initialize the encoder if needed
        this->port = port;
        vexMotor = vex::motor(port);
       }

    double Encoder::getPosition() {
        // Get the current position from the motor's encoder
        return vexMotor.position(vex::rotationUnits::deg);
    }

    double Encoder::getRotations() {
        // Get the current rotations from the motor's encoder
        return vexMotor.rotation(vex::rotationUnits::rev);
    }

    double Encoder::getVelocity() {
        // Get the current velocity from the motor's encoder
        return vexMotor.velocity(vex::velocityUnits::rpm);
    }

    void Encoder::reset() {
        // Reset the motor's encoder position to zero
        vexMotor.resetRotation();
    }

} //namespace hal
} //namespace iqos