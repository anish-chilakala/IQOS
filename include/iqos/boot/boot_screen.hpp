#pragma once

#include "vex.h"
#include "iqos/hal/screen.hpp"
#include <string>
#include <vector>


namespace iqos {
namespace boot {
    class BootScreen {
        
        public:
BootScreen(hal::Screen& screen);   
 // Function Declerations here
void show();
void updateProgress(int progress);
void hide();



        private:
// Private Declarations for battery management
hal::Screen& screen;

        
    };

} // namespace boot
} // namespace iqos