

#include "vex.h"
#include "iqos/logging/motor_logger.hpp"
#include "iqos/memory/ring_buffer.hpp"
#include "iqos/timing/system_clock.hpp"
using namespace vex;
extern vex::brain Brain;

namespace iqos {
namespace logging {

    MotorLogger::MotorLogger(RingBuffer& ringBuffer, Motor& motor) : ringBuffer(ringBuffer), motor(motor) {
    }

    void MotorLogger::log() {
        double velocity = motor.getVelocity();
        double temperature = motor.getTemperature();
        double position = motor.getPosition();

        uint32_t timestamp = SystemClock::milliseconds();

        MotorReading newReadings;
        newReadings.velocity = velocity;
        newReadings.temperature = temperature;
        newReadings.position = position;
        newReadings.timestamp = timestamp;

        readings.push_back(newReadings);
    }

    std::vector<MotorLogger::MotorReading> MotorLogger::getReadings() {
        return readings;
    }

    void MotorLogger::clear() {
        readings.clear();
    }

   

} // namespace logging
} // namespace iqos
