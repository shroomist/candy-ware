#include "mux.h"

void queryMux(byte chan) {
  digitalWrite(MUX_A_Pin, bitRead(chan, 0));
  digitalWrite(MUX_B_Pin, bitRead(chan, 1));
  digitalWrite(MUX_C_Pin, bitRead(chan, 2));
  digitalWrite(MUX_D_Pin, bitRead(chan, 3));
}

void setupMux() {
  pinMode(MUX_A_Pin, OUTPUT);
  pinMode(MUX_B_Pin, OUTPUT);
  pinMode(MUX_C_Pin, OUTPUT);
  pinMode(MUX_D_Pin, OUTPUT);
}
