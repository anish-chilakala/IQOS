IQOS/
│
├── .github/
│   ├── ISSUE_TEMPLATE/
│   │   ├── bug_report.md
│   │   └── feature_request.md
│   └── PULL_REQUEST_TEMPLATE.md
│
├── docs/
│   ├── getting_started.md
│   ├── architecture.md
│   ├── api_reference.md
│   └── contributing_guide.md
│
├── include/
│   └── iqos/
│       ├── scheduler/
│       │   ├── task_manager.hpp
│       │   ├── task_priorities.hpp
│       │   ├── task_queue.hpp
│       │   ├── task_watchdog.hpp
│       │   ├── mutex.hpp
│       │   └── semaphore.hpp
│       │
│       ├── timing/
│       │   ├── system_clock.hpp
│       │   ├── delta_time.hpp
│       │   ├── match_timer.hpp
│       │   ├── countdown_timer.hpp
│       │   ├── hires_timer.hpp
│       │   └── timeout.hpp
│       │
│       ├── hal/
│       │   ├── motor.hpp
│       │   ├── sensor.hpp
│       │   ├── port_manager.hpp
│       │   ├── screen.hpp
│       │   ├── controller.hpp
│       │   ├── battery.hpp
│       │   ├── encoder.hpp
│       │   ├── imu.hpp
│       │   ├── distance.hpp
│       │   ├── optical.hpp
│       │   └── bumper.hpp
│       │
│       ├── events/
│       │   ├── event_bus.hpp
│       │   ├── button_events.hpp
│       │   ├── touch_events.hpp
│       │   ├── sensor_events.hpp
│       │   ├── match_events.hpp
│       │   ├── motor_events.hpp
│       │   ├── port_events.hpp
│       │   └── user_events.hpp
│       │
│       ├── memory/
│       │   ├── persistent_storage.hpp
│       │   ├── config_manager.hpp
│       │   ├── variable_registry.hpp
│       │   ├── ring_buffer.hpp
│       │   ├── stack_allocator.hpp
│       │   └── settings_manager.hpp
│       │
│       ├── errors/
│       │   ├── fault_detection.hpp
│       │   ├── error_codes.hpp
│       │   ├── recovery.hpp
│       │   └── fault_logger.hpp
│       │
│       ├── logging/
│       │   ├── event_logger.hpp
│       │   ├── log_levels.hpp
│       │   ├── gui_feed.hpp
│       │   ├── sensor_logger.hpp
│       │   └── motor_logger.hpp
│       │
│       ├── power/
│       │   ├── battery_monitor.hpp
│       │   ├── power_limiter.hpp
│       │   ├── idle_mode.hpp
│       │   └── thermal_throttle.hpp
│       │
│       └── boot/
│           ├── boot_manager.hpp
│           ├── hardware_detect.hpp
│           ├── config_loader.hpp
│           ├── self_test.hpp
│           └── boot_screen.hpp
│
├── src/
│   └── iqos/
│       ├── scheduler/
│       │   ├── task_manager.cpp
│       │   ├── task_priorities.cpp
│       │   ├── task_queue.cpp
│       │   ├── task_watchdog.cpp
│       │   ├── mutex.cpp
│       │   └── semaphore.cpp
│       │
│       ├── timing/
│       │   ├── system_clock.cpp
│       │   ├── delta_time.cpp
│       │   ├── match_timer.cpp
│       │   ├── countdown_timer.cpp
│       │   ├── hires_timer.cpp
│       │   └── timeout.cpp
│       │
│       ├── hal/
│       │   ├── motor.cpp
│       │   ├── sensor.cpp
│       │   ├── port_manager.cpp
│       │   ├── screen.cpp
│       │   ├── controller.cpp
│       │   ├── battery.cpp
│       │   ├── encoder.cpp
│       │   ├── imu.cpp
│       │   ├── distance.cpp
│       │   ├── optical.cpp
│       │   └── bumper.cpp
│       │
│       ├── events/
│       │   ├── event_bus.cpp
│       │   ├── button_events.cpp
│       │   ├── touch_events.cpp
│       │   ├── sensor_events.cpp
│       │   ├── match_events.cpp
│       │   ├── motor_events.cpp
│       │   ├── port_events.cpp
│       │   └── user_events.cpp
│       │
│       ├── memory/
│       │   ├── persistent_storage.cpp
│       │   ├── config_manager.cpp
│       │   ├── variable_registry.cpp
│       │   ├── ring_buffer.cpp
│       │   ├── stack_allocator.cpp
│       │   └── settings_manager.cpp
│       │
│       ├── errors/
│       │   ├── fault_detection.cpp
│       │   ├── error_codes.cpp
│       │   ├── recovery.cpp
│       │   └── fault_logger.cpp
│       │
│       ├── logging/
│       │   ├── event_logger.cpp
│       │   ├── log_levels.cpp
│       │   ├── gui_feed.cpp
│       │   ├── sensor_logger.cpp
│       │   └── motor_logger.cpp
│       │
│       ├── power/
│       │   ├── battery_monitor.cpp
│       │   ├── power_limiter.cpp
│       │   ├── idle_mode.cpp
│       │   └── thermal_throttle.cpp
│       │
│       └── boot/
│           ├── boot_manager.cpp
│           ├── hardware_detect.cpp
│           ├── config_loader.cpp
│           ├── self_test.cpp
│           └── boot_screen.cpp
│
├── tests/
│   ├── scheduler/
│   ├── timing/
│   ├── hal/
│   ├── events/
│   ├── memory/
│   ├── errors/
│   ├── logging/
│   ├── power/
│   └── boot/
│
├── examples/
│   ├── basic_setup/
│   ├── event_usage/
│   ├── config_usage/
│   └── full_robot/
│
├── CHANGELOG.md
├── CODE_OF_CONDUCT.md
├── CONTRIBUTING.md
├── LICENSE
├── README.md
├── SECURITY.md
└── CMakeLists.txt
