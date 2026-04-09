#pragma once

#include "vex.h"
#include <string>
#include <vector>


namespace iqos {
namespace hal {
class Encoder {
    
    public:
    Encoder(uint8_t port);
    // Function Declerations here
    double getPosition();
    double getRotations();
    double getVelocity();
    void reset();
    
    private:
    // Private Declarations for encoder management
    uint8_t port;
    vex::motor vexMotor;
};

}// namespace hal
}// namespace iqos