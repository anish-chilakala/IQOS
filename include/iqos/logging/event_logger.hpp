#pragma once

#include "vex.h"
#include "iqos/memory/ring_buffer.hpp"
#include "iqos/logging/log_levels.hpp"
#include <string>
#include <vector>

namespace iqos {
namespace logging {
    class EventLogger {

        struct LogEntry {
    LogLevel level;
    std::string message;
    uint32_t timestamp;
    };

public:
EventLogger(RingBuffer& ringBuffer);
//PUblic Function Declarations here
void log(LogLevel level, std::string message);
std::vector<LogEntry> getLogs();
void clear();

private:
//Private Declarations here
RingBuffer& ringBuffer;
std::vector<LogEntry> logs;

    };
} // namespace logging
} // namespace iqos
