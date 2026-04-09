#pragma once

#include "vex.h"
#include <string>
#include <vector>


namespace iqos {
namespace hal {

enum class DeviceType {
    NONE,       // nothing plugged in
    MOTOR,      // motor plugged in
    DISTANCE,   // distance sensor
    OPTICAL,    // optical sensor
    BUMPER,     // bumper sensor
    IMU,        // inertial sensor
    UNKNOWN     // something plugged in but unrecognized
};

class PortManager {
    public:
    PortManager();
    // Function Declerations here
    void scan();
    DeviceType getDeviceType(uint8_t port);
    bool isPortOccupied(uint8_t port);
    std::vector<uint8_t> getOccupiedPorts();




    private:
    // private members for port management
    std::vector<DeviceType> ports;
    

};

} // namespace hal
} // namespace iqos
