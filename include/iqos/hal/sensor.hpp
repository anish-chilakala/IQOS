#pragma once

#include "vex.h"
#include <string>
#include <vector>


namespace iqos {
namespace hal {
class Sensor {
    public:
    Sensor(uint8_t port);
    // Function Declerations here
    uint8_t getPort();
    bool isConnected();
    virtual double read() = 0; // Pure virtual function for reading sensor value

    protected:
    // protected members for derived sensor classes
    uint8_t port;
    bool connected;



};

} // namespace hal
} // namespace iqos