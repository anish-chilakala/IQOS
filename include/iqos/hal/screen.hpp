#pragma once

#include "vex.h"
#include <string>
#include <vector>


namespace iqos {
namespace hal {

    class Screen {
public:
Screen();

// Function Declerations here
void clearScreen();
void printText(int x, int y, std::string text);
void drawRectangle(int x, int y, int width, int height, vex::color c);
void drawCircle(int x, int y, int radius, vex::color c);
void drawLine(int x1, int y1, int x2, int y2);
void drawPixel(int x, int y);
void setColor(vex::color c);
bool isTouched();
int getTouchX();
int getTouchY();

private:
//private members for screen management
vex::color currentColor;
    
};


} // namespace hal
} // namespace iqos