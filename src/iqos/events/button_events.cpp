#include "vex.h"
#include "iqos/events/event_bus.hpp"
#include "iqos/events/button_events.hpp"
#include "iqos/hal/controller.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace events {

ButtonEvents::ButtonEvents(EventBus& eventBus, Controller& controller) : eventBus(eventBus), controller(controller) {
    // nothing to initialize, event queue starts empty automatically
}

void ButtonEvents::update() {
    // check the state of each button and fire events accordingly
    if (controller.isButtonL1Pressed()) {
    eventBus.fire("BUTTON_L1_PRESSED");
}
if (controller.isButtonL2Pressed()) {
    eventBus.fire("BUTTON_L2_PRESSED");
}
if (controller.isButtonR1Pressed()) {
    eventBus.fire("BUTTON_R1_PRESSED");
}
if (controller.isButtonR2Pressed()) {
    eventBus.fire("BUTTON_R2_PRESSED");
}
if (controller.isButtonEUpPressed()) {
    eventBus.fire("BUTTON_EUP_PRESSED");
}
if (controller.isButtonEDownPressed()) {
    eventBus.fire("BUTTON_EDOWN_PRESSED");
}
if (controller.isButtonFUpPressed()) {
    eventBus.fire("BUTTON_FUP_PRESSED");
}
if (controller.isButtonFDownPressed()) {
    eventBus.fire("BUTTON_FDOWN_PRESSED");
}
if (controller.isButtonL3Pressed()) {
    eventBus.fire("BUTTON_L3_PRESSED");
}
if (controller.isButtonR3Pressed()) {
    eventBus.fire("BUTTON_R3_PRESSED");
}

}
} // namespace events
} // namespace iqos