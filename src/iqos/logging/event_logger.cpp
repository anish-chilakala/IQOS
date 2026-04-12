

#include "vex.h"
#include "iqos/logging/event_logger.hpp"
#include "iqos/timing/system_clock.hpp"
using namespace vex;
extern vex::brain Brain;

namespace iqos {
namespace logging {

    EventLogger::EventLogger(RingBuffer& ringBuffer) : ringBuffer(ringBuffer) {
    }

    void EventLogger::log(LogLevel level, std::string message) {
        LogEntry newEntry;
        newEntry.level = level;
        newEntry.message = message;
        newEntry.timestamp = SystemClock::milliseconds();

        logs.push_back(newEntry);
    }

    std::vector<EventLogger::LogEntry> EventLogger::getLogs() {
    return logs;
    }

    void EventLogger::clear() {
        logs.clear();
    }


} // namespace logging
} // namespace iqos
