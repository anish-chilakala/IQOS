#include "vex.h"
#include "iqos/events/event_bus.hpp"
#include "iqos/events/user_events.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace events {

UserEvents::UserEvents(EventBus& eventBus) : eventBus(eventBus) {
}

void UserEvents::registerEvent(std::string eventName) {
    registeredEvents.push_back(eventName);
}

void UserEvents::fireEvent(std::string eventName) {
    eventBus.fire(eventName);
}

bool UserEvents::isRegistered(std::string eventName) {
    for (int i = 0; i < registeredEvents.size(); i++) {
        if (registeredEvents[i] == eventName) {
            return true;
        }
    }
    return false;
}

} // namespace events
} // namespace iqos