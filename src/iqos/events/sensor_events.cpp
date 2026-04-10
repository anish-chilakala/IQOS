#include "vex.h"
#include "iqos/events/event_bus.hpp"
#include "iqos/events/sensor_events.hpp"



using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace events {
    SensorEvents::SensorEvents(EventBus& eventBus) : eventBus(eventBus) {
        // nothing to initialize, event queue starts empty automatically
    }

    void SensorEvents::addThreshold(std::string sensorName, double thresholdValue, double (*getSensorValue)()) {
        // Add a new sensor threshold to the list
        SensorThreshold newThreshold;
        newThreshold.eventName = sensorName;
        newThreshold.thresholdValue = thresholdValue;
        // For demonstration, we will use a dummy function that returns a constant value
        newThreshold.getSensorValue = getSensorValue;
        thresholds.push_back(newThreshold);
    }

    void SensorEvents::update() {
        // Check each sensor threshold and fire events if thresholds are crossed
        for (const auto& threshold : thresholds) {
            double currentValue = threshold.getSensorValue();
            if (currentValue > threshold.thresholdValue) {
                eventBus.fire(threshold.eventName);
            }
        }
    }
} // namespace events
} // namespace iqos