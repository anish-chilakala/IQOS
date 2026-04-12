#pragma once

#include "vex.h"

namespace iqos {
namespace errors {
    enum class ErrorCode {
    // No error
    NONE = 0,

    // Motor errors
    MOTOR_STALL = 1,
    MOTOR_OVERHEAT = 2,
    MOTOR_DISCONNECT = 3,
    MOTOR_OVERCURRENT = 4,

    // Sensor errors
    SENSOR_DISCONNECT = 5,
    SENSOR_OUT_OF_RANGE = 6,
    SENSOR_CALIBRATION_FAILED = 7,

    // Memory errors
    STORAGE_READ_FAILED = 8,
    STORAGE_WRITE_FAILED = 9,
    CONFIG_LOAD_FAILED = 10,
    CONFIG_SAVE_FAILED = 11,
    OUT_OF_MEMORY = 12,

    // System errors
    BOOT_FAILED = 13,
    WATCHDOG_TIMEOUT = 14,
    MUTEX_TIMEOUT = 15,

    // Controller errors
    CONTROLLER_DISCONNECT = 16,

    // Task errors
    TASK_FROZEN = 17,
    TASK_CREATE_FAILED = 18,

    // Power errors
    LOW_BATTERY = 19,
    CRITICAL_BATTERY = 20,
    THERMAL_THROTTLE = 21
};

} // namespace errors
} // namespace iqos