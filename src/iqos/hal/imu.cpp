#include "vex.h"
#include "iqos/hal/imu.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace hal {
    IMU::IMU() {
        // Initialize the IMU if needed
        BrainInertial.calibrate();
       }
    double IMU::getHeading() {
        // Get the current heading from the IMU
        return BrainInertial.heading();
    }

    double IMU::getPitch() {
        // Get the current pitch from the IMU
        return BrainInertial.pitch();
    }

    double IMU::getRoll() {
        // Get the current roll from the IMU
        return BrainInertial.roll();
    }

   double IMU::getAccelerationX() {
    return BrainInertial.acceleration(xaxis);
}

double IMU::getAccelerationY() {
    return BrainInertial.acceleration(yaxis);
}
    }

    bool IMU::isCalibrating() {
        // Check if the IMU is currently calibrating
        return BrainInertial.isCalibrating();
    }

    void IMU::reset() {
        // Reset the IMU's heading to zero
        BrainInertial.resetHeading();
    }
} //namespace hal
} //namespace iqos