#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>



// auto fun = [] () { _PL("Hi from func"); };
// auto other = [] (std::function<void ()> myfun) { myfun(); };
// void readMux () {
//   _PP(millis());
//   _PP("reading: ");
//   _PL(readTarget);
//   other(fun);
//   st.setWaiting();
//   tReadMux.waitFor(&st);
// }

#include "sch/header.hpp"
#include "sch/calc.hpp"

#include "potnbtn/mux-read-timer.hpp"
#include <Arduino.h> //for Serial and delay

Scheduler runner; //Let the scheduler live here, in the main file, ok?
Calculator calc1(123);

MuxReadTimer mrt(1);

//Pretend, that the t2 task is a special task,
//that needs to live in file2 object file.
void t2Callback() { // in sch/header.hpp
    Serial.print("t2: ");
    Serial.println(millis());
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
  //  mrt.tSetMuxReadTarget.enableDelayed(12);
  // mrt.tSetReadReady.enableDelayed(25);
}


void loop () {
  runner.execute();

//  Serial.println("Loop ticks at: ");
//  Serial.println(millis());
}
