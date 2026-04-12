#pragma once

#include "vex.h"
#include <string>
#include <vector>
#include <map>


namespace iqos {
namespace memory {
    class VariableRegistry {
       public:
       VariableRegistry();
       //Function Declarations here
    void set(std::string name, double value);
    double get(std::string name);
    bool exists(std::string name);
    void remove(std::string name);      

    private:
//Private Declarations for Variable Registry
std::map<std::string, double> registry;


    };
    
    
} //namespace memory
} //namespace iqos