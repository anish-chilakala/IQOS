#include "vex.h"
#include "iqos/memory/persistent_storage.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace memory {

    PersistentStorage::PersistentStorage() {
    //Initializes Automatically
    }

void PersistentStorage::write(std::string filename, std::string data) {
    // convert string to buffer
    uint8_t buffer[512];
    memcpy(buffer, data.c_str(), data.size());
    // save to brain
    Brain.SDcard.savefile(filename.c_str(), buffer, data.size());
}

std::string PersistentStorage::read(std::string filename) {
    uint8_t buffer[512];
    Brain.SDcard.loadfile(filename.c_str(), buffer, 512);
    return std::string((char*)buffer);
}

bool PersistentStorage::exists(std::string filename) {
    return Brain.SDcard.exists(filename.c_str());
}

void PersistentStorage::remove(std::string filename) {
    Brain.SDcard.remove(filename.c_str());
}


} // namespace memory
} // namespace iqos