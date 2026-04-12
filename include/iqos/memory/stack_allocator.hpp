#pragma once

#include "vex.h"
#include <string>
#include <vector>
#include <map>


namespace iqos {
namespace memory {
    class StackAllocater {
       
        public:
StackAllocator(uint32_t size);
~StackAllocator();
       //Function Declarations here
uint8_t* allocate(uint32_t size);
void deallocate(uint32_t size);
void reset();
uint32_t getUsed();
uint32_t getAvailable();

 

    private:
//Private Declarations 
uint8_t* memory;
uint32_t totalSize;
uint32_t usedSize;




    };
    
    
} //namespace memory
} //namespace iqos