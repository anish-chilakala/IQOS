

#include "vex.h"
#include "iqos/power/idle_mode.hpp"
#include "iqos/timing/system_clock.hpp"
using namespace vex;
extern vex::brain Brain;

namespace iqos {
namespace power{

    IdleMode::IdleMode(EventBus& eventBus, Screen& screen, uint32_t idleTimeout) : eventBus(eventBus), screen(screen), idleTimeout(idleTimeout) {
        isIdle = false;
        lastActivityTime = SystemClock.milliseconds();
    }

    void IdleMode::update() {
    uint32_t currentTime = SystemClock::milliseconds();
    uint32_t timeSinceActivity = currentTime - lastActivityTime;

    if (timeSinceActivity > idleTimeout && !isIdle) {
        isIdle = true;
        screen.clearScreen();
        eventBus.fire("IDLE_START"); // not IDLE_END
    }
}

    void IdleMode::resetActivity() {
    lastActivityTime = SystemClock::milliseconds();
    if (isIdle) {
        isIdle = false;
        eventBus.fire("IDLE_END");
    }
}

    bool IdleMode::isIdleMode() {
        return isIdle;
    }

} // namespace power
} // namespace iqos
