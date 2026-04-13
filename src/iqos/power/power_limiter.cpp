

#include "vex.h"
#include "iqos/power/power_limiter.hpp"
using namespace vex;
extern vex::brain Brain;

namespace iqos {
namespace power{
PowerLimiter::PowerLimiter(EventBus& eventBus, double maxPower) : eventBus(eventBus), powerLimit(maxPower) {
}

void PowerLimiter::setLimit(double limit) {
    powerLimit = limit;
}

double PowerLimiter::getLimit() {
    return powerLimit;
}

double PowerLimiter::enforceLimit(double requestedVelocity) {
    if (requestedVelocity > powerLimit) {
    return powerLimit;
}
return requestedVelocity;
}

bool PowerLimiter::isOverLimit(double currentPower) {
    if (currentPower > powerLimit) {
        return true;
    }
    return false;
}


} // namespace power
} // namespace iqos
