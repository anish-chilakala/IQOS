#pragma once

#include "vex.h"
#include "iqos/memory/persistent_storage.hpp"
#include <string>
#include <vector>
#include <map>


namespace iqos {
namespace memory {
    class ConfigManager {
        public:
        ConfigManager(PersistentStorage& storage);
        //Function Declarations here
        
        void load(std::string filename);             // void - just loads, gives nothing back
        void save(std::string filename);             // void - just saves, gives nothing back
        std::string getValue(std::string key);       // string - returns the value for that key
        void setValue(std::string key, std::string value); // void - just sets, gives nothing back


        private:
        //Private Variable Declarations here
        PersistentStorage& storage;
        std::map<std::string, std::string> configData;


    };
    
    
} //namespace memory
} //namespace iqos