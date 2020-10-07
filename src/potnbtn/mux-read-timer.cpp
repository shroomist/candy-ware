#include "mux-read-timer.hpp"
#include "debug.h"

#define READ_PERIOD 1000
#define MUX_DELAY 30

MuxReadTimer::MuxReadTimer (int b) {
      // Pass the this pointer, so that we get access to this->cumSum
      // Also pass a copy of b
      tSetMuxReadTarget.set( READ_PERIOD, TASK_FOREVER, [this] () {
        readTarget = nextReadTarget(readTarget);
        _PP(millis());
        _PP(": target set: ");
        _PL(readTarget);
      });

      tSetReadReady.set( READ_PERIOD, TASK_FOREVER, [this, b]() {
        _PP(millis());
        _PP(": read Ready:  ");
        _PL(readTarget);
      });
      runner.addTask(tSetMuxReadTarget);
      runner.addTask(tSetReadReady);
}

void MuxReadTimer::enable () { // Should be at the end of setup()
  tSetMuxReadTarget.enableDelayed(10);
  tSetReadReady.enableDelayed(40);
}

int MuxReadTimer::nextReadTarget(int curr) {
  if (curr < 15) {
    return ++curr;
  }
  return 0;
}
