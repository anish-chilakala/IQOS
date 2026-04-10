#include "vex.h"
#include "iqos/events/event_bus.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace events {
EventBus::EventBus() {
    // nothing to initialize, event queue starts empty automatically
}

void EventBus::subscribe(std::string eventName, void (*callback)()) {
    // add the event and callback to the list of subscribers
    Subscriber newSubscriber;
    newSubscriber.eventName = eventName;
    newSubscriber.callback = callback;
    subscribers.push_back(newSubscriber);
}

void EventBus::unsubscribe(std::string eventName) {
    // loop through all subscribers to find the one with the matching event name
    for (int i = 0; i < subscribers.size(); i++) {
        if (subscribers[i].eventName == eventName) {
            // remove from the list
            subscribers.erase(subscribers.begin() + i);
            return;
        }
    }
}

void EventBus::fire(std::string eventName) {
    // loop through all subscribers to find those with the matching event name
    for (int i = 0; i < subscribers.size(); i++) {
        if (subscribers[i].eventName == eventName) {
            // call the subscriber's callback function
            subscribers[i].callback();
        }
    }
}



} // namespace events
} // namespace iqos