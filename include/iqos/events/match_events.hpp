#pragma once

#include "vex.h"
#include "iqos/events/event_bus.hpp"
#include <string>
#include <vector>


namespace iqos {
namespace events {
class MatchEvents {

    public:
    enum class MatchPhase {
    NONE,
    AUTONOMOUS,
    DRIVER,
    DISABLED
    };
    
    MatchEvents(EventBus& eventBus);
    // Function Declarations here
    void update();

    private:
    // Private Variable Decalarations here
    EventBus& eventBus;
    MatchPhase currentPhase;    
};


}// namespace events
}//namespace iqos