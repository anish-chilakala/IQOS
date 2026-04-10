#include "vex.h"
#include "iqos/events/event_bus.hpp"
#include "iqos/events/match_events.hpp"



using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace events {

MatchEvents::MatchEvents(EventBus& eventBus) : eventBus(eventBus) {
    currentPhase = MatchPhase::NONE;
}

void MatchEvents::update() {
    MatchPhase newPhase;

    // figure out what phase we are in right now
    if (Competition.isAutonomous()) {
        newPhase = MatchPhase::AUTONOMOUS;
    } else if (Competition.isDriverControl()) {
        newPhase = MatchPhase::DRIVER;
    } else {
        newPhase = MatchPhase::DISABLED;
    }

    // if the phase changed fire the matching event
    if (newPhase != currentPhase) {
        if (newPhase == MatchPhase::AUTONOMOUS) {
            eventBus.fire("MATCH_AUTONOMOUS_START");
        } else if (newPhase == MatchPhase::DRIVER) {
            eventBus.fire("MATCH_DRIVER_START");
        } else {
            eventBus.fire("MATCH_DISABLED");
        }
        // update stored phase
        currentPhase = newPhase;
    }
}
} // namespace events
} // namespace iqos