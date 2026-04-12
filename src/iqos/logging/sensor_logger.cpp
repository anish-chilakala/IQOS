

#include "vex.h"
#include "iqos/logging/sensor_logger.hpp"
#include "iqos/memory/ring_buffer.hpp"
#include "iqos/timing/system_clock.hpp"
using namespace vex;
extern vex::brain Brain;

namespace iqos {
namespace logging {

    SensorLogger::SensorLogger(RingBuffer& ringBuffer) : ringBuffer(ringBuffer) {
    }

    void SensorLogger::log(std::string sensorName, double value) {
        uint32_t timestamp = SystemClock::milliseconds();

        SensorReading newReading;
        newReading.sensorName = sensorName;
        newReading.value = value;
        newReading.timestamp = timestamp;

        readings.push_back(newReading);
    }

    std::vector<SensorLogger::SensorReading> SensorLogger::getReadings() {
        return readings;
    }

    void SensorLogger::clear() {
        readings.clear();
    }


} // namespace logging
} // namespace iqos
