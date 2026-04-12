#include "iqos/errors/fault_logger.hpp"

#include "vex.h"
#include "iqos/timing/system_clock.hpp"
using namespace vex;
extern vex::brain Brain;

namespace iqos {
namespace errors {

FaultLogger::FaultLogger(RingBuffer& ringBuffer) : ringBuffer(ringBuffer) {
}

void FaultLogger::log(ErrorCode code, uint32_t timestamp) {
    FaultEntry newFault;
    newFault.code = code;
    newFault.timestamp = timestamp;

    faults.push_back(newFault);
}

std::vector<FaultLogger::FaultEntry> FaultLogger::getRecentFaults() {
    return faults;
}

void FaultLogger::clearFaults() {
    faults.clear();
}

} // namespace errors
} // namespace iqos
