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

#include <Arduino.h> //for Serial and delay
#include <MIDI.h>
HardwareSerial Serial2(PA3, PA2); // RX, TX -- to unused pin PB1

MIDI_CREATE_INSTANCE(HardwareSerial, Serial2, midi2);
// #include <SoftwareSerial.h>
// SoftwareSerial midiSerial(PB11, PB1); // RX, TX -- to unused pin PB1
void handleNoteOn(byte channel, byte pitch, byte velocity)
{
  _PP("MIDI NOTE ON ");
  _PP(" ch ");
  _PP(channel);
  _PP("pch ");
  _PP(pitch);
  _PP("velo ");
  _PL(velocity);
}

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

Task sequencerGoNextStep(500, TASK_FOREVER, &check, &runner, true);

CtrlLog logController("log");
CtrlLog logController1("synth");
Displ displ;
Synth synth;
Sequencer seqs(&synth);
str_ctrl logCtrl = {Log, (Ctrl*)&logController};
str_ctrl seqCtrl = {SeqC, (Ctrl*)&seqs};
str_ctrl synthCtrl = {SynthC, &synth};
str_ctrl displCtrl = {DisplayC, &displ};
all_ctrls allCtrls = {logCtrl, synthCtrl, displCtrl, seqCtrl};

CtrlSwitch controlSwitch(allCtrls);
param_btn_handles hs1 = controlSwitch.getHandles();

MuxReadTimer mrt(1, hs1.param, hs1.btn);

//Pretend, that the t2 task is a special task,
//that needs to live in file2 object file.
// void t2Callback() { // in sch/header.hpp
//     // Serial.print("t2: ");
//     // Serial.println(millis());
// }
// Task t2(3000, TASK_FOREVER, &t2Callback, &runner, true);

//Lets define t3Callback here. We are going to use it in file1
//for Task 1.
// void t3Callback() {
//     Serial.print("t3: ");
//     Serial.println(millis());
// }

// int currentStep1 = 0;



void setup () {
  Serial.begin(115200);
  Serial2.begin(31250);
  midi2.begin(MIDI_CHANNEL_OMNI);
  midi2.setHandleNoteOn(handleNoteOn);
  delay(5000);
  Serial.println("Scheduler TEST (multi-tab)");

  seqs.start();
  seqs.setTempo(130);
  runner.startNow();  // set point-in-time for scheduling start
  mrt.enable();
  displ.setup();
  initOPL();
}

int incomingByte = 0; // for incoming serial data

void loop () {
  runner.execute();
  midi2.read();
  if (Serial2.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial2.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }
}
