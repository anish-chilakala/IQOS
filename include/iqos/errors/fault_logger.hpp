#pragma once

#include "vex.h"
#include "iqos/memory/ring_buffer.hpp"
#include "iqos/errors/error_codes.hpp"
#include <string>
#include <vector>



namespace iqos {
namespace errors {
class FaultLogger {

struct FaultEntry {
    ErrorCode code;
    uint32_t timestamp;
};

    public:
FaultLogger(RingBuffer& ringBuffer);   
    //Function Declarations here
void log(ErrorCode code, uint32_t timestamp);
std::vector<FaultEntry> getRecentFaults();
void clearFaults();
   

    private:
    //Private Variable Declarations
RingBuffer& ringBuffer;
std::vector<FaultEntry> faults;

    

};

} // namespace errors
} // namespace iqos