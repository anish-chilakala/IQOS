#pragma once

#include "vex.h"
#include <string>
#include <vector>


namespace iqos {
namespace memory {
    class PersistentStorage {
        public:
        PersistentStorage();
        //Function Declarations here
        void write(std::string filename, std::string data);
        std::string read(std::string filename);
        bool exists(std::string filename);
        void remove(std::string filename);


        private:
        //Private Variable Declarations here
        //No private variables to declare

    };
    
} //namespace memory
} //namespace iqos