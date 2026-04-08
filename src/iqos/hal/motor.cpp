#include "vex.h"
#include <cmath>
#include "iqos/hal/motor.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace hal {
Motor::Motor(uint8_t port) {
    vexMotor = vex::motor(port);
    uint8_t port = vexMotor.index();
}

void Motor::setVelocity(double velocity) {
    vexMotor.setVelocity(velocity, percentUnits::pct);
}

void Motor::setVoltage(double voltage) {
    vexMotor.setVoltage(voltage, voltageUnits::volt);
}

void Motor::stop() {
    vexMotor.stop();
}

void Motor::brake() {
    vexMotor.setBrake(brakeType::hold);
}

double Motor::getVelocity() {
    return vexMotor.velocity(percentUnits::pct);
}

double Motor::getTemperature() {
    return vexMotor.temperature(temperatureUnits::fahrenheit);
}

double Motor::getPosition() {
    return vexMotor.position(rotationUnits::deg);
}

bool Motor::isStalled(){
    vexMotor.velocity(velocityUnits::rpm);
    double epsilon = 1;
    if (vexMotor.velocity(velocityUnits::rpm) < epsilon && vexMotor.isSpinning()) {
        return true;
    }
    return false;

}

bool Motor::isOverheating() {
    if (vexMotor.temperature(temperatureUnits::celsius) > 55) {
        return true;
    }
    return false;
}

void Motor::resetPosition() {
    vexMotor.resetEncoder();
}

} // namespace hal
} // namespace iqos