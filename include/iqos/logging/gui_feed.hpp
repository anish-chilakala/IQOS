#pragma once

#include "vex.h"
#include "iqos/hal/screen.hpp"
#include "iqos/logging/event_logger.hpp"
#include <string>
#include <vector>

namespace iqos {
namespace logging {
    class GuiFeed {

public:
GuiFeed(Screen& screen, EventLogger& eventLogger);
//PUblic Function Declarations here
void update();
void clear();

private:
//Private Declarations here
Screen& screen;
EventLogger& eventLogger;
int yPosition;
std::string levelToString(LogLevel level);

    };
} // namespace logging
} // namespace iqos
