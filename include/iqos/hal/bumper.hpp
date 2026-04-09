#pragma once

#include "vex.h"
#include <string>
#include <vector>


namespace iqos {
namespace hal {
class Bumper {
    public:
    Bumper(uint8_t port);
    // Function Declerations here
    bool isPressed();
    bool wasPressed();

    private:
    // Private Declarations for Bumper Sensor management
    uint8_t port; // Port number for the bumper sensor
    vex::bumper bumperSensor; // VEX bumper sensor object
    bool pressedSinceLastCheck; // Flag to track if the bumper has been pressed since the last check
};



}//namespace hal
}//namespace iqos
