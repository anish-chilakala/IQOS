#include "iqos/boot/boot_manager.hpp"
#include <stdexcept>

namespace iqos {
namespace boot {

BootManager::BootManager(hal::Screen& screen)
    : screen(screen), bootScreen(screen) {}

void BootManager::registerModule(const Module& module) {
    modules.push_back(module);
}

void BootManager::visit(
    const std::string& name,
    std::unordered_map<std::string, Module>& map,
    std::unordered_set<std::string>& visited,
    std::unordered_set<std::string>& temp,
    std::vector<Module>& ordered
) {
    if (temp.count(name)) {
        throw std::runtime_error("Circular dependency: " + name);
    }

    if (visited.count(name)) return;

    temp.insert(name);

    for (auto& dep : map[name].dependsOn) {
        visit(dep, map, visited, temp, ordered);
    }

    temp.erase(name);
    visited.insert(name);
    ordered.push_back(map[name]);
}

void BootManager::run() {
    bootScreen.show();

    std::unordered_map<std::string, Module> map;
    for (auto& m : modules) {
        map[m.name] = m;
    }

    std::vector<Module> ordered;
    std::unordered_set<std::string> visited;
    std::unordered_set<std::string> temp;

    for (auto& m : modules) {
        visit(m.name, map, visited, temp, ordered);
    }

    int progress = 0;
    int step = 100 / (ordered.empty() ? 1 : ordered.size());

    for (auto& m : ordered) {
        m.init();
        progress += step;
        bootScreen.updateProgress(progress);
    }

    bootScreen.hide();
}

} // namespace boot
} // namespace iqos