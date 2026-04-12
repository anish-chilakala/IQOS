#pragma once

#include "vex.h"
#include <string>
#include <vector>
#include <map>


namespace iqos {
namespace memory {
    class RingBuffer {
       
        public:
        RingBuffer(uint32_t maxSize);
       //Function Declarations here
void push(double value);
double pop();
double peek();
bool isFull();
bool isEmpty();
uint32_t size();
 

    private:
//Private Declarations 
std::vector<double> buffer;
uint32_t maxSize;
uint32_t head;



    };
    
    
} //namespace memory
} //namespace iqos