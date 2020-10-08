#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

#include "sch/header.hpp"
#include "sch/calc.hpp"

#include "debug.h"
#include "potnbtn/mux-read-timer.hpp"
#include <Arduino.h> //for Serial and delay

Scheduler runner; //Let the scheduler live here, in the main file, ok?
// Calculator calc1(123);

void setParam(int target, int value) {
  _PP("POT value for: ");
  _PP(target);
  _PP(" = ");
  _PL(value);
}

void setBtn (int target, bool value) {
  _PP("BTN value for: ");
  _PP(target);
  _PP(" = ");
  _PL(value);

}

MuxReadTimer mrt(1, setParam, setBtn);

//Pretend, that the t2 task is a special task,
//that needs to live in file2 object file.
void t2Callback() { // in sch/header.hpp
    // Serial.print("t2: ");
    // Serial.println(millis());
}
Task t2(3000, TASK_FOREVER, &t2Callback, &runner, true);

//Lets define t3Callback here. We are going to use it in file1
//for Task 1.
void t3Callback() {
    Serial.print("t3: ");
    Serial.println(millis());
}

void setup () {
  Serial.begin(115200);
  delay(5000);
  Serial.println("Scheduler TEST (multi-tab)");

  runner.startNow();  // set point-in-time for scheduling start
  mrt.enable();
}


void loop () {
  runner.execute();
}
