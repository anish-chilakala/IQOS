#pragma once

#include "vex.h"
#include "iqos/events/event_bus.hpp"
#include "iqos/events/sensor_events.hpp"
#include <string>
#include <vector>


namespace iqos {
namespace events {
    class SensorEvents {

        struct SensorThreshold {
        std::string eventName;
        double thresholdValue;
        double (*getSensorValue)(); // callback to get sensor reading
    };

        public:
        // Constructor for SensorEvents, takes references to the event bus and controller
        SensorEvents(EventBus& eventBus);
        // Function declaration for updating sensor events
        void update();
        void addThreshold(std::string eventName, double thresholdValue, double (*getSensorValue)());

        private:
        // Private members for managing sensor events
        EventBus& eventBus;
        std::vector<SensorThreshold> thresholds;
    };
    
} // namespace events
} // namespace iqos