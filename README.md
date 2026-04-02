# IQOS
IQOS is an operating system designed for the VEX IQ Brain and Hardware that sits on top of the VEXcode IQ SDK. It turns raw hardware access into a managed, safe, organized system that future VEX IQ templates can sit on top of. This is PROS for V5 except for VEX IQ.

## Examples of IQOS

**Without IQOS:**
```cpp
// You manually poll sensors in loops
// No protection if two tasks access motor simultaneously
// No detection if sensor disconnects
// No logging if something crashes
// No config system, hardcode everything
// No power management, motors just overheat
// Robot crashes silently with no recovery
```

**With IQOS:**
```cpp
// Sensors fire events automatically when thresholds hit
// Mutex system prevents data conflicts automatically
// Port disconnect detected and logged instantly
// Every fault logged with timestamp and error code
// Config loaded from file on boot automatically
// Thermal throttling kicks in before motors overheat
// Graceful recovery attempted before giving up
```

## The Seven Things IQOS Aims to Provide for the VEX IQ Community

### 1. Safety
- Prevents tasks from conflicting with each other
- Detects and recovers from faults automatically
- Graceful failure instead of silent crashes

### 2. Structure
- Controlled boot sequence
- Everything initializes in the right order
- Hardware verified before robot runs

### 3. Awareness
- Knows what hardware is connected
- Monitors motor temps, battery, sensor states
- Logs everything that happens

### 4. Efficiency
- Tasks run at correct priorities
- Power managed intelligently
- No wasted processing on unnecessary polling

### 5. Persistence
- Settings saved between runs
- Config loaded automatically on boot
- No hardcoding values into code

### 6. Communication
- Event system connects all parts of the robot
- Modules talk to each other without being directly linked
- GUI receives data without polling

### 7. Foundation
- Clean interfaces for templates (such as LemLib for V5) to sit on top of

## Goal
The goal for IQOS is to increase efficiency and effectiveness in robot code design. When this is finished, teams will be able to write effective controllers to make sure robots follow the user's, driver's, or even the computer's commands. This will bring autons up from half of max score to max scores and make driver skills much easier — if you know how to use the OS properly.

## Respecting the Student Centered Competition
Some people might think that IQOS can count as cheating, as we claim IQOS will increase the robot's full potential without any work. This certainly is not the case. This is a custom OS — we provide the building blocks, but teams need to learn the OS and be able to change parts to make it fulfill their robot's full potential. This OS simply increases the potential of the VEX IQ Hardware and Brain to provide a better robotics experience.
