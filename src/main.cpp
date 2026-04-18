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

    //IQOS Boot Sequence
    
    iqos::hal::Screen screen;
    iqos::boot::BootManager boot(screen);

    // Boot steps (REAL execution, inline logic)

    boot.registerStep({"HAL", 10, [&]() {
        // init HAL systems here
    }});

    boot.registerStep({"Boot", 25, [&]() {
        // boot core systems
    }});

    boot.registerStep({"Errors", 40, [&]() {
        // error handler init
    }});

    boot.registerStep({"Events", 55, [&]() {
        // event system init
    }});

    boot.registerStep({"Logging", 70, [&]() {
        // logging system init
    }});

    boot.registerStep({"Memory", 80, [&]() {
        // memory system init
    }});

    boot.registerStep({"Power", 90, [&]() {
        // power system init
    }});

    boot.registerStep({"Scheduler", 97, [&]() {
        // scheduler init
    }});

    boot.registerStep({"Timing", 100, [&]() {
        // timing finalization
    }});

    boot.run();

    while (true) {
        this_thread::sleep_for(10);
    }
}

