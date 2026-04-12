#include "iqos/memory/config_manager.hpp"
#include <sstream>
#include <map>

namespace iqos {
namespace memory {

ConfigManager::ConfigManager(PersistentStorage& storage)
    : storage(storage) {}

void ConfigManager::load(std::string filename) {
    configData.clear();

    std::string raw = storage.read(filename);
    if (raw.empty()) {
        return; // no file or empty file
    }

    std::stringstream ss(raw);
    std::string line;

    while (std::getline(ss, line)) {
        if (line.empty()) continue;
        if (line[0] == '#') continue; // allow comments

        size_t eq = line.find('=');
        if (eq == std::string::npos) continue;

        std::string key = line.substr(0, eq);
        std::string value = line.substr(eq + 1);

        configData[key] = value;
    }
}

void ConfigManager::save(std::string filename) {
    std::string output;

    for (auto& pair : configData) {
        output += pair.first + "=" + pair.second + "\n";
    }

    storage.write(filename, output);
}

std::string ConfigManager::getValue(std::string key) {
    if (configData.count(key)) {
        return configData[key];
    }
    return "";
}

void ConfigManager::setValue(std::string key, std::string value) {
    configData[key] = value;
}

} // namespace memory
} // namespace iqos
