#include "vex.h"
#include "iqos/hal/bumper.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace hal {
Bumper::Bumper(uint8_t port) {
    //Vex IQ bumper sensor initialization
    bumperSensor = vex::bumper(port);
    pressedSinceLastCheck = false; // Initialize the flag to track if the bumper has been pressed
}

bool Bumper::isPressed() {
    // Check if the bumper is currently pressed
    return bumperSensor.pressing();
}

bool Bumper::wasPressed() {
    bool currentlyPressed = bumperSensor.pressing();
    if (currentlyPressed) {
        pressedSinceLastCheck = true;
    }
    bool result = pressedSinceLastCheck;
    pressedSinceLastCheck = false; // reset after checking
    return result;
}

}//namespace hal
}//namespace iqos

