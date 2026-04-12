#pragma once

#include "vex.h"
#include "iqos/memory/ring_buffer.hpp"
#include "iqos/hal/motor.hpp"
#include <string>
#include <vector>

namespace iqos {
namespace logging {
    class MotorLogger {

struct MotorReading {
    double velocity;
    double temperature;
    double position;
    uint32_t timestamp;
};

public:
MotorLogger(RingBuffer& ringBuffer, Motor& motor);
//Public Function Declarations here
void log();
std::vector<MotorReading> getReadings();
void clear();


private:
//Private Declarations here
RingBuffer& ringBuffer;
Motor& motor;
std::vector<MotorReading> readings;



    };
} // namespace logging
} // namespace iqos
