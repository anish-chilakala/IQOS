#include "vex.h"
#include "iqos/events/event_bus.hpp"
#include "iqos/hal/port_manager.hpp"
#include "iqos/events/port_events.hpp"



using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace events {
    PortEvents::PortEvents(EventBus& eventBus, PortManager& portManager) : eventBus(eventBus), portManager(portManager) {
    for (int i = 0; i < 12; i++) {
    previousStates.push_back(DeviceType::NONE);
    }
    }

    
    void PortEvents::update() {
        portManager.scan();
        for (int i=0; i < 12; i++) {
            DeviceType currentState = portManager.getDeviceType(i);
            if (currentState != previousStates[i]) {
            if (currentState != DeviceType::NONE) {
            eventBus.fire("PORT_CONNECTED");
            } else {
            eventBus.fire("PORT_DISCONNECTED");
            }
            }
            previousStates[i] = currentState;
            
        }
    }
} // namespace events
} // namespace iqos