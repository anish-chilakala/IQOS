#pragma once

#include "vex.h"
#include "iqos/memory/ring_buffer.hpp"
#include <string>
#include <vector>

namespace iqos {
namespace logging {
    class SensorLogger {

struct SensorReading {
    std::string sensorName;
    double value;
    uint32_t timestamp;
};

public:
SensorLogger(RingBuffer& ringBuffer);
//Public Function Declarations here
void log(std::string sensorName, double value);
std::vector<SensorReading> getReadings();
void clear();


private:
//Private Declarations here
RingBuffer& ringBuffer;
std::vector<SensorReading> readings;


    };
} // namespace logging
} // namespace iqos
