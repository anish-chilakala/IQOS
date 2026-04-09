#pragma once

#include "vex.h"
#include <string>
#include <vector>


namespace iqos {
namespace hal {
    class Battery {
        
        public:
        Battery();
        // Function Declerations here
        uint8_t getLevel();
        bool isLow();
        void setLowThreshold(uint8_t threshold);
        uint8_t getLowThreshold();
        
        private:
        // Private Declarations for battery management
        uint8_t lowThreshold;
    };

} // namespace hal
} // namespace iqos