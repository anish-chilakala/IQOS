#include "iqos/memory/ring_buffer.hpp"
#include <sstream>
#include <map>

namespace iqos {
namespace memory {
    RingBuffer::RingBuffer(uint32_t maxSize) {
        this->maxSize = maxSize;
        head = 0;
    }
    
    void RingBuffer::push(double value) {
        if (isFull()) {
    buffer[head] = value;
} else {
    buffer.push_back(value);
}
head = (head + 1) % maxSize;
    }

   double RingBuffer::pop() {
    double value = buffer[0];
buffer.erase(buffer.begin());
return value;
   }

   double RingBuffer::peek() {
    return buffer[0];
   }

   bool RingBuffer::isFull() {
    return buffer.size() >= maxSize;
   }

   bool RingBuffer::isEmpty() {
    return buffer.empty();
   }

   uint32_t RingBuffer::size() {
    return buffer.size();
   }



} // namespace memory
} // namespace iqos
