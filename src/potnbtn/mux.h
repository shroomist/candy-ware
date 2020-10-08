#ifndef __MUX_H_
#define __MUX_H_

#define MUX_A_Pin PB12
#define MUX_B_Pin PB13
#define MUX_C_Pin PB14
#define MUX_D_Pin PB15

#include <Arduino.h>

void queryMux(byte chan);
void setupMux();

#endif // __MUX_H_
