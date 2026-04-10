#include "vex.h"
#include "iqos/events/event_bus.hpp"
#include "iqos/events/touch_events.hpp"
#include "iqos/hal/screen.hpp"



using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace events {
    TouchEvents::TouchEvents(EventBus& eventBus, Screen& screen) : eventBus(eventBus), screen(screen), wasTouched(false) {
        // nothing to initialize, event queue starts empty automatically
    }


 void TouchEvents::update() {
    // Check if the screen is currently being touched
    bool isCurrentlyTouched = screen.isTouched();

    // If the touch state has changed from not touched to touched, fire a "TOUCH_PRESSED" event
    if (isCurrentlyTouched && !wasTouched) {
    eventBus.fire("SCREEN_TOUCHED");
    }
    else if (!isCurrentlyTouched && wasTouched) {
    eventBus.fire("SCREEN_RELEASED");
    }

    if (isCurrentlyTouched) {
    eventBus.fire("TOUCH_X");
    eventBus.fire("TOUCH_Y");
    }

    // Update the previous touch state for the next update cycle
    wasTouched = isCurrentlyTouched;
    
}

} // namespace events
} //namespace iqos