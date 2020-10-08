#ifndef __BTN_H_
#define __BTN_H_

#define BTN_PIN PB3
#define BUTTON_COUNT 16

#include <Arduino.h>

struct btn_reading {
  bool isNew;
  bool value;
  byte target;
};

void setupBtn ();

struct btn_reading* getBtnReading (byte target);

#endif // __BTN_H_
