

#include "vex.h"
#include "iqos/hal/screen.hpp"
#include "iqos/boot/boot_screen.hpp"
using namespace vex;
extern vex::brain Brain;

namespace iqos {
namespace boot{
    BootScreen::BootScreen(Screen& screen) : screen(screen) {
    }

vex::color blue = vex::color(0, 0, 255); //blue for Vex IQ
vex::color black = vex::color(0, 0, 0);      // background

void BootScreen::show() {
    screen.clearScreen(black);

    // Letter I
    screen.drawRectangle(140, 20, 40, 8, blue);
    screen.drawRectangle(156, 28, 8, 40, blue);
    screen.drawRectangle(140, 68, 40, 8, blue);

    // Letter Q
    screen.drawRectangle(200, 20, 40, 8, blue);
    screen.drawRectangle(200, 68, 40, 8, blue);
    screen.drawRectangle(200, 28, 8, 40, blue);
    screen.drawRectangle(232, 28, 8, 40, blue);
    screen.drawRectangle(228, 60, 12, 12, blue);

    // Letter O
    screen.drawRectangle(260, 20, 40, 8, blue);
    screen.drawRectangle(260, 68, 40, 8, blue);
    screen.drawRectangle(260, 28, 8, 40, blue);
    screen.drawRectangle(292, 28, 8, 40, blue);

    // Letter S
    screen.drawRectangle(320, 20, 40, 8, blue);
    screen.drawRectangle(320, 44, 40, 8, blue);
    screen.drawRectangle(320, 68, 40, 8, blue);
    screen.drawRectangle(320, 28, 8, 16, blue);
    screen.drawRectangle(352, 52, 8, 16, blue);

    screen.printText(110, 110, "Loading...");
    screen.printText(105, 140, "Version 0.0");
}

    void BootScreen::updateProgress(int progress) {
// draw background bar
screen.drawRectangle(10, 200, 300, 10, black);
// draw filled portion based on progress
screen.drawRectangle(10, 200, progress * 3, 10, blue);
// print percentage
screen.printText(130, 220, std::to_string(progress) + "%");
    }

    void BootScreen::hide() {
        screen.clearScreen();
    }





} // namespace boot
} // namespace iqos
