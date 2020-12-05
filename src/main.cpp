#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

#include "sch/header.hpp"
#include "sch/calc.hpp"

#include "debug.h"
#include "potnbtn/mux-read-timer.hpp"
#include "ctrl/ctrl.hpp"

#include "display/dis.hpp"
#include "synth/synth.hpp"

#include "seq/seq.hpp"
#include "midi/input.hpp"

#include <Arduino.h> //for Serial and delay

Scheduler runner; //Let the scheduler live here, in the main file, ok?

Task sequencerGoNextStep(5000, TASK_FOREVER, NULL, &runner, false);
Task midiRead(5, TASK_FOREVER, NULL, &runner, true);

CtrlLog logController("log");
CtrlLog logController1("synth");
Displ displ;
Synth synth;
Sequencer seqs(&synth);
MidiCtrl midiIn(&synth);
str_ctrl logCtrl = {Log, (Ctrl*)&logController};
str_ctrl seqCtrl = {SeqC, (Ctrl*)&seqs};
str_ctrl synthCtrl = {SynthC, &synth};
str_ctrl displCtrl = {DisplayC, &displ};
all_ctrls allCtrls = {logCtrl, synthCtrl, displCtrl, seqCtrl};

CtrlSwitch controlSwitch(allCtrls);
param_btn_handles hs1 = controlSwitch.getHandles();

MuxReadTimer mrt(hs1.param, hs1.btn);

void setup () {
  Serial.begin(115200);
  Serial2.begin(31250);
  delay(5000);
  Serial.println("Scheduler TEST (multi-tab)");

  // seqs.start();
  seqs.setTempo(70);
  runner.startNow();  // set point-in-time for scheduling start
  mrt.enable();
  displ.setup();
  initOPL();
}

int incomingByte = 0; // for incoming serial data

void loop () {
  runner.execute();
}
