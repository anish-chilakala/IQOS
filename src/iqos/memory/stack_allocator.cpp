#include "iqos/memory/stack_allocater.hpp"
#include <sstream>
#include <map>

namespace iqos {
namespace memory {
   StackAllocator::StackAllocator(uint32_t size) {
    memory = new uint8_t[size];
    this->totalSize = size;
    usedSize = 0;
}

   StackAllocater::~StackAllocator() {
    delete[] memory;
   }

   uint8_t* StackAllocator::allocate(uint32_t size) {
    uint8_t* ptr = memory + usedSize;
    usedSize += size;
    return ptr;
}

   void StackAllocator::deallocate(uint32_t size) {
    usedSize -= size;
   }

   void StackAllocator::reset() {
    usedSize = 0;
   }

   uint32_t StackAllocator::getUsed() {
    return usedSize;
   }

   uint32_t StackAllocator::getAvailable() {
    return totalSize - usedSize;
   }




} // namespace memory
} // namespace iqos
