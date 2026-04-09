#pragma once

#include "vex.h"
#include <string>
#include <vector>


namespace iqos {
namespace hal {
class Controller {
public:
    Controller();
// Function Declerations here
    // Left rear bumpers
bool isButtonL1Pressed();
bool isButtonL2Pressed();

// Right rear bumpers
bool isButtonR1Pressed();
bool isButtonR2Pressed();

// Front left buttons
bool isButtonEUpPressed();
bool isButtonEDownPressed();

// Front right buttons
bool isButtonFUpPressed();
bool isButtonFDownPressed();

// Joystick buttons
bool isButtonL3Pressed();
bool isButtonR3Pressed();

    int getAxis1Position();
    int getAxis2Position();
    int getAxis3Position();
    int getAxis4Position();
    bool isConnected();


private:
    vex::controller controller;

};

} // namespace hal
} // namespace iqos
