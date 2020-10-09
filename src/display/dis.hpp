#ifndef __DISPLAY_H_
#define __DISPLAY_H_

// SCREEN DEFINITIONS
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 4 // Reset pin # (or -1 if sharing Arduino reset pin)

#include "../ctrl/ctrl.hpp"

class Displ: public Ctrl {
  public:
    Displ();
    void setup();
    param_btn_handles getHandles();
};

#endif // __MAIN_H_
