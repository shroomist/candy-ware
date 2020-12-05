#include "mux.h"
#include "pot.h"
#include "debug.h"

byte currentPot = 0;
int pot[POT_COUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool initialized[POT_COUNT] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
int debounceRange = 24; // 5

int potRead () {
  return (analogRead(POT_Pin));
  // delay 30ms?
}

void setupPots () {
  analogReadResolution(12);
  pinMode(POT_Pin, INPUT_ANALOG);
}

pot_reading potReading{true,0};

pot_reading* getPotReading (byte target) {
  potReading.target = target;

  if (!initialized[target]) {
    potReading.isNew = false;
    potReading.value = potRead();
    initialized[target] = true;
    pot[target] = potReading.value;
    return &potReading;
  }

  potReading.value = softDebounce(potRead(), pot[target]);

  if (initialized[target]) {
    potReading.isNew = potReading.value != pot[target];
  }

  if (potReading.isNew) {
    pot[target] = potReading.value;
  }

  return &potReading;
}

int softDebounce(int readCV, int oldRead) {
  if (abs(readCV - oldRead) > debounceRange) {
    return readCV;
  }
  return oldRead;
}
