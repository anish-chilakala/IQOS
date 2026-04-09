#pragma once

#include "vex.h"
#include <string>
#include <vector>


namespace iqos {
namespace hal {
    class IMU {
        public:
        IMU();
        // Function Declerations here
        double getHeading();
        double getPitch();
        double getRoll();
        double getAccelerationX();
        double getAccelerationY();
        bool isCalibrating();
        void reset();

        private:
        // Private Declarations for IMU management
        
    };


} //namespace hal
} //namespace iqos