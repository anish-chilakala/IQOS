#include "vex.h"
#include "iqos/hal/screen.hpp"

using namespace vex;

extern vex::brain Brain;

namespace iqos {
namespace hal {

    Screen::Screen() {
        currentColor = vex::color::black; // default pen color
    }

    void Screen::clearScreen() {
        Brain.Screen.clearScreen();
    }

    void Screen::printText(int x, int y, std::string text) {
        Brain.Screen.printAt(x, y, text.c_str());
    }

    void Screen::drawRectangle(int x, int y, int width, int height, vex::color c) {
        Brain.Screen.setPenColor(c);
        Brain.Screen.drawRectangle(x, y, width, height);
    }

    void Screen::drawCircle(int x, int y, int radius, vex::color c) {
        Brain.Screen.setPenColor(c);
        Brain.Screen.drawCircle(x, y, radius);
    }

    void Screen::drawLine(int x1, int y1, int x2, int y2) {
        Brain.Screen.drawLine(x1, y1, x2, y2);
    }

    void Screen::setColor(vex::color c) {
        Brain.Screen.setPenColor(c);
    } 

    void Screen::drawPixel(int x, int y) {
        Brain.Screen.drawPixel(x, y);
    }

    bool Screen::isTouched() {
        return Brain.Screen.pressing();
    }

    int Screen::getTouchX() {
        return Brain.Screen.xPosition();
    }

    int Screen::getTouchY() {
        return Brain.Screen.yPosition();
    }




} // namespace hal
} // namespace iqos
