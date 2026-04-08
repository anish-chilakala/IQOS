#pragma once

#include "vex.h"
#include <string>
#include <vector>


namespace iqos {
namespace hal {

class Motor {
    public:
    Motor(uint8_t port);
    // Function Declerations here
    void setVelocity(double velocity); 
    void setVoltage(double voltage);
    void stop();
    void brake();
    double getVelocity();
    double getTemperature();
    double getPosition();
    bool isStalled();
    bool isOverheating();
    void resetPosition();



    private:
    // Private Varibale Declarations here
    uint8_t port;
    vex::motor vexMotor;

};

} // namespace hal
} // namespace iqos