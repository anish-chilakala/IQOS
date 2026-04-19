

#include "vex.h"
#include "iqos/boot/boot_manager.hpp"
using namespace vex;
extern vex::brain Brain;

namespace iqos {
namespace boot{
    
    void BootManager::boot() {
        Screen.printText(110, 160, "Checking Boot...");
        iqos::boot::Boot::init();

        Screen.printText(110, 160, "Checking Errors...");
        iqos::errors::Errors::init();

        Screen.printText(110, 160, "Checking Events...");
        iqos::events::Events::init();

        Screen.printText(110, 160, "Checking HAL...");
        iqos::hal::HAL::init();

        Screen.printText(110, 160, "Checking Logging...");
        iqos::logging::Logging::init();

        Screen.printText(110, 160, "Checking Memory...");
        iqos::memory::Memory::init();

        screen.printText(110, 160, "Checking Power...");
        iqos::power::Power::init();

        Screen.printText(110, 160, "Checking Scheduler...");
        iqos::scheduler::Scheduler::init();
        
        Screen.printText(110, 160, "Checking Timing...");
        iqos::timing::Timing::init();
    }






} // namespace boot
} // namespace iqos
