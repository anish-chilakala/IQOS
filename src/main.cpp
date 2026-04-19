/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Anish Chilakala                                           */
/*    Created:      4/2/2026                                                  */
/*    Description:  IQOS - Custom Operating System for VEX IQ2               */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "iqos/boot/boot_manager.hpp"

using namespace vex;

// A global instance of vex::brain used for printing to the IQ2 brain screen
vex::brain Brain;

int main() {
    
    // IQOS Boot Sequence
    // iqos::boot::BootManager::initialize();
    // Everything will be initialized from here when IQOS is complete

    
    while(1) {
        this_thread::sleep_for(10);
    }
}
