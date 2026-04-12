#pragma once

#include "vex.h"
#include "iqos/memory/config_manager.hpp"
#include "iqos/memory/variable_registry.hpp"
#include <string>
#include <vector>
#include <map>


namespace iqos {
namespace memory {
    class SettingsManager {
       
        public:
SettingsManager(ConfigManager& configManager, VariableRegistry& variableRegistry);
       //Function Declarations here
void load(std::string filename);
void save(std::string filename);
double get(std::string name);
void set(std::string name, double value);


 

    private:
//Private Declarations 
ConfigManager& configManager;
VariableRegistry& variableRegistry;





    };
    
    
} //namespace memory
} //namespace iqos