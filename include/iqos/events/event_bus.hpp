#pragma once

#include "vex.h"
#include <string>
#include <vector>


namespace iqos {
namespace events {
    class EventBus {

        struct Subscriber {
        std::string eventName;
        void (*callback)();
    };

        public:
        EventBus();
        // Function Declerations here
        void subscribe(std::string eventName, void (*callback)());
        void unsubscribe(std::string eventName);
        void fire(std::string eventName);

        private:
        // Private Declarations for EventBus management
        std::vector<Subscriber> subscribers;
    };

}//namespace events
}//namespace iqos