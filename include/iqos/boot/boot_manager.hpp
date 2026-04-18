#pragma once

#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <unordered_set>

#include "iqos/hal/screen.hpp"
#include "iqos/boot/boot_screen.hpp"

namespace iqos {
namespace boot {

struct Module {
    std::string name;
    std::vector<std::string> dependsOn;
    std::function<void()> init;
};

class BootManager {
private:
    hal::Screen& screen;
    BootScreen bootScreen;

    std::vector<Module> modules;

    void visit(
        const std::string& name,
        std::unordered_map<std::string, Module>& map,
        std::unordered_set<std::string>& visited,
        std::unordered_set<std::string>& temp,
        std::vector<Module>& ordered
    );

public:
    BootManager(hal::Screen& screen);

    void registerModule(const Module& module);
    void run();
};

} // namespace boot
} // namespace iqos