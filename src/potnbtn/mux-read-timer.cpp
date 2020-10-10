#include "mux-read-timer.hpp"
#include "mux.h"
#include "pot.h"
#include "btn.h"

#include "debug.h"

#define READ_PERIOD 2
#define MUX_DELAY 1


MuxReadTimer::MuxReadTimer (int b, set_param setParam, set_btn setBtn) {
  // Pass the this pointer, so that we get access to this->cumSum
  // Also pass a copy of b
  setupMux();
  setupPots();
  setupBtn();

  tSetMuxReadTarget.set( READ_PERIOD, TASK_FOREVER, [this] () {
    nextReadTarget();

      queryMux(readTarget.target);

  });

  tSetReadReady.set( READ_PERIOD, TASK_FOREVER, [this, b, setParam, setBtn]() {
    if (readTarget.isPot) {
      pot_reading* currentPotRead = getPotReading(readTarget.target); // TODO: GC?
      if (currentPotRead->isNew) {
        setParam(currentPotRead->target, currentPotRead->value); // TODO: improve last read with target
      }

    } else {

      btn_reading* currentBtnRead = getBtnReading(readTarget.target);
      if (currentBtnRead->isNew) {
        setBtn(currentBtnRead->target, currentBtnRead->value);
      }

    }
  });
  runner.addTask(tSetMuxReadTarget);
  runner.addTask(tSetReadReady);
}

void MuxReadTimer::enable () { // Should be at the end of setup()
  tSetMuxReadTarget.enableDelayed(10);
  tSetReadReady.enableDelayed(40);
}


void MuxReadTimer::nextReadTarget() {
  if (readTarget.target < 15) {
    readTarget.target = readTarget.target + 1;
  } else {
    readTarget.target = 0;
    readTarget.isPot = !readTarget.isPot;
  }
}
