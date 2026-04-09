#include "vex.h"
#include "iqos/hal/controller.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace hal {
    Controller::Controller() {
        // Initialize the controller if needed
    }

bool Controller::isButtonL1Pressed() {
        return controller.ButtonL1.pressing();
    }

bool Controller::isButtonL2Pressed() {
        return controller.ButtonL2.pressing();
    }

bool Controller::isButtonR1Pressed() {
        return controller.ButtonR1.pressing();
    }

bool Controller::isButtonR2Pressed() {
        return controller.ButtonR2.pressing();
    }

bool Controller::isButtonEUpPressed() {
        return controller.ButtonEUp.pressing();
    }

bool Controller::isButtonEDownPressed() {
        return controller.ButtonEDown.pressing();
    }

bool Controller::isButtonFUpPressed() {
        return controller.ButtonFUp.pressing();
    }

    bool Controller::isButtonFDownPressed() {
        return controller.ButtonFDown.pressing();
    }

bool Controller::isButtonL3Pressed() {
        return controller.ButtonL3.pressing();
    }

bool Controller::isButtonR3Pressed() {
        return controller.ButtonR3.pressing();
    }

    int Controller::getAxis1Position() {
        return controller.Axis1.position();
    }

    int Controller::getAxis2Position() {
        return controller.Axis2.position();
    }

    int Controller::getAxis3Position() {
        return controller.Axis3.position();
    }

    int Controller::getAxis4Position() {
        return controller.Axis4.position();
    }

    bool Controller::isConnected() {
        return controller.is_connected(); 
    }
    

} // namespace hal
} // namespace iqos