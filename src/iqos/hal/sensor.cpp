#include "vex.h"
#include "iqos/hal/sensor.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace hal {

    Sensor::Sensor(uint8_t port) {
    this->port = port;
    connected = false;
    }
    

    uint8_t Sensor::getPort() {
        return port;
    }

    bool Sensor::isConnected() {
        return connected;
    }


} // namespace hal
} // namespace iqos
