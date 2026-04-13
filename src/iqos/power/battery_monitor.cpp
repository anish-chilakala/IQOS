

#include "vex.h"
#include "iqos/power/battery_monitor.hpp"
using namespace vex;
extern vex::brain Brain;

namespace iqos {
namespace power{
    BatteryMonitor::BatteryMonitor(EventBus& eventBus, Battery& battery) : eventBus(eventBus), battery(battery) {
    previousLevel = battery.getLevel();
    }

    void BatteryMonitor::update() {
    uint8_t currentLevel = battery.getLevel(); // get current level
    this->drainRate = previousLevel - currentLevel; // calculate drain
    previousLevel = currentLevel; // update for next time
    
    if (battery.isLow()) { // check if low
        eventBus.fire("BATTERY_LOW");
    }
}

    double BatteryMonitor::getDrainRate() {
    return drainRate;
}

uint8_t BatteryMonitor::getLevel() {
    return battery.getLevel();
}





   

} // namespace power
} // namespace iqos
