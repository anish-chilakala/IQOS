#include "iqos/memory/variable_registry.hpp"
#include <sstream>
#include <map>

namespace iqos {
namespace memory {
    VariableRegistry::VariableRegistry() {
        //Initializes Automatically
    }

    void VariableRegistry::set(std::string name, double value) {
    registry[name] = value;    
    }

    double VariableRegistry::get(std::string name) {
    return registry[name];
    }

    bool VariableRegistry::exists(std::string name) {
    return registry.count(name) > 0;
    }

    void VariableRegistry::remove(std::string name) {
    registry.erase(name);
    }



} // namespace memory
} // namespace iqos
