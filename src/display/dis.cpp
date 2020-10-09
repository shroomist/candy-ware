#include "dis.hpp"
#include "../sch/header.hpp"
// #include "../potnbtn/set-pot-btn.hpp"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "debug.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void animInit();
void animInit1();

Task tAnimInit (TASK_IMMEDIATE, TASK_ONCE, &animInit, &runner);
Task tAnimInit1 (TASK_IMMEDIATE, TASK_ONCE, &animInit1, &runner);

void animInit () {
  display.println(F("OPERA"));
  display.display();
  tAnimInit1.enableDelayed(1500);
};

void animInit1 () {
  display.clearDisplay();
  display.setCursor(0, 15);
  display.println(F("ROTAS"));
  display.display();
};

set_param setParam = [] (int t, int v) {
  display.clearDisplay();
  display.setCursor(0, 15);
  display.println(F("PARAM"));
  display.display();
};

set_btn setBtn = [] (int t, bool v) {
  display.clearDisplay();
  display.setCursor(0, 15);
  display.println(F("BATON"));
  display.display();
};

Displ::Displ() {};

void Displ::setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    return;
  }

  display.clearDisplay();
  display.setTextSize(4);              // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 15);
  tAnimInit.enable();
};

param_btn_handles Displ::getHandles() {
  return param_btn_handles{setParam, setBtn};
}
