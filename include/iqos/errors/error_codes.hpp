#pragma once

#include "vex.h"

namespace iqos {
namespace errors {
    enum class ErrorCodes {
        //Define enum of all possible error codes:
    NONE = 0,
    MOTOR_STALL = 1,
    MOTOR_OVERHEAT = 2,
    MOTOR_DISCONNECT = 3,
    SENSOR_DISCONNECT = 4,
    SENSOR_OUT_OF_RANGE = 5,
    TASK_FROZEN = 6,
    LOW_BATTERY = 7,
    CONFIG_LOAD_FAILED = 8,
    STORAGE_WRITE_FAILED = 9
    };

} // namespace errors
} // namespace iqos