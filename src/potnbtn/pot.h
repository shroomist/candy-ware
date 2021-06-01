#ifndef __POT_H_
#define __POT_H_

#include <Arduino.h>

#define POT_PIN PA0
#define POT_Pin PA0

#define POT_COUNT 16

// TODO: normalization goes elsewhere
const int boundaries[POT_COUNT][2] = { // was [24][2]
    {15, 0}, // 0 ATT 1
    {15, 0}, // 1 DEC 1
    {15, 0}, // 2 SUS 1
    {15, 0}, // 3 REL 1
    {0, 15}, // 4 MULT 1
    {0, 7},  // 5 FEED
    {0, 7}, // 6 NOTE
    {64, 0}, // 7 VOL 1
    {15, 0}, // 8 ATT 2
    {15, 0}, // 9 DEC 2
    {15, 0}, // 10 SUS 2
    {15, 0}, // 11 REL 2
    {0, 15}, // 12 MULT 2
    {0, 16}, // 13 MAPPED WAVETYPES  16
    {0, 64}, // 14 tremolos vibratos
    {64, 0}  // 15 VOL2
};

int softDebounce(int readCV, int oldRead);


struct pot_reading {
  bool isNew;
  int value;
  byte target;
};

struct pot_reading *getPotReading(byte target);

void setupPots ();
int potRead () ;

#endif // __POT_H_
