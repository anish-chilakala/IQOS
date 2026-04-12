#include "iqos/memory/settings_manager.hpp"
#include "iqos/memory/variable_registry.hpp"
#include "iqos/memory/config_manager.hpp"
#include <sstream>
#include <map>

namespace iqos {
namespace memory {

   SettingsManager::SettingsManager(ConfigManager& configManager, VariableRegistry& variableRegistry) : configManager(configManager), variableRegistry(variableRegistry) {
}

   void SettingsManager::load(std::string filename) {
    configManager.load(filename);
   }

   void SettingsManager::save(std::string filename){
    configManager.save(filename);
   }

   double SettingsManager::get(std::string name) {
    return variableRegistry.get(name);
   }

   void SettingsManager::set(std::string name, double value) {
    variableRegistry.set(name, value);
   }


} // namespace memory
} // namespace iqos
