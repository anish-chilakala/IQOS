

#include "vex.h"
#include "iqos/logging/log_levels.hpp"
#include "iqos/logging/gui_feed.hpp"
#include "iqos/timing/system_clock.hpp"
using namespace vex;
extern vex::brain Brain;

namespace iqos {
namespace logging {

    GuiFeed::GuiFeed(Screen& screen, EventLogger& eventLogger ) : screen(screen), eventLogger(eventLogger) {
    yPosition = 20;
    }

 std::string GuiFeed::levelToString(LogLevel level) {
    if (level == LogLevel::DEBUG) return "DEBUG";
    if (level == LogLevel::INFO) return "INFO";
    if (level == LogLevel::WARNING) return "WARN";
    if (level == LogLevel::ERROR) return "ERROR";
    return "UNKNOWN";
}

    void GuiFeed::update() {
        std::vector<EventLogger::LogEntry> logs = eventLogger.getLogs();
        screen.clearScreen();
        
        for (int i = 0; i < logs.size(); i++) {
    std::string level = levelToString(logs[i].level);
    std::string message = "[" + level + "] " + logs[i].message;
    screen.printText(10, yPosition, message);
    yPosition += 20; // move down for next line
    }
    yPosition = 20;

    }

    void GuiFeed::clear() {
        screen.clearScreen();
        yPosition = 20;
    }
} // namespace logging
} // namespace iqos
