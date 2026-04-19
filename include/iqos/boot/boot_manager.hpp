#pragma once

#include "vex.h"
#include "iqos/boot/boot_screen.hpp"

namespace iqos {
namespace boot {

    class BootManager {
        public:
            // The single entry point called from main.cpp
            static void boot();

        private:
            // Helper to handle the screen during boot
            static void run_sequence();
    };

} // namespace boot
} // namespace iqos
