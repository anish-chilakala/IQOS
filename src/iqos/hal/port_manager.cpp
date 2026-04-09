#include "vex.h"
#include "iqos/hal/port_manager.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace hal {

PortManager::PortManager() {
    for (int i = 0; i < 12; i++) {
        ports.push_back(DeviceType::NONE);
    }
}

void PortManager::scan() {
   void PortManager::scan() {
    for (int i = 0; i < 12; i++) {
        vex::deviceType type = Brain.getDeviceType(i);
        if (type == vex::deviceType::motor) {
            ports[i] = DeviceType::MOTOR;
        } else if (type == vex::deviceType::distanceSensor) {
            ports[i] = DeviceType::DISTANCE;
        } else if (type == vex::deviceType::opticalSensor) {
            ports[i] = DeviceType::OPTICAL;
        } else if (type == vex::deviceType::bumper) {
            ports[i] = DeviceType::BUMPER;
        } else if (type == vex::deviceType::inertial) {
            ports[i] = DeviceType::IMU;
        } else if (type == vex::deviceType::none) {
            ports[i] = DeviceType::NONE;
        } else {
            ports[i] = DeviceType::UNKNOWN;
        }
    }
}

}

   DeviceType PortManager::getDeviceType(uint8_t port) {
    return ports[port];
}

    bool PortManager::isPortOccupied(uint8_t port) {
    return ports[port] != DeviceType::NONE;
}


std::vector<uint8_t> PortManager::getOccupiedPorts() {
    std::vector<uint8_t> occupied_ports;
    for (int i = 0; i < 12; i++) {
        if (ports[i] != DeviceType::NONE) {
    occupiedPorts.push_back(i);
    }
    }
    return occupied_ports;
}

} // namespace hal
} // namespace iqos
    