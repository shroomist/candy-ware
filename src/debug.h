#ifndef __DEBUG_H_
#define __DEBUG_H_

#include <Arduino.h>

#ifdef _DEBUG_
#define _PP(a) Serial.print(a);
#define _PL(a) Serial.println(a);
#else
#define _PP(a)
#define _PL(a)
#endif

#endif // __DEBUG_H_
