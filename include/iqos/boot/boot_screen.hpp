#pragma once

#include "vex.h"
#include "iqos/hal/screen.hpp"
#include <string>
#include <vector>


namespace iqos {
namespace boot {
    class BootScreen {
        
        public:
     BootScreen(Screen& screen);   
 // Function Declerations here
 BootScreen(Screen& screen);
void show();
void updateProgress(int progress);
void hide();



        private:
// Private Declarations for battery management
Screen& screen;

        
    };

} // namespace boot
} // namespace iqos