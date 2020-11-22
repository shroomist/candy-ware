#include "seq.hpp"
#include "debug.h"

int currentStep = 0;
void check () {
  _PP("check: playing step ");
  _PL(currentStep);
};


int bpm = 120;
bool seqPlaying = true;


bool seqGate[8][16] = {
{ 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0 },
{ 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0 },
{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0 },
{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0 },
{ 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
{ 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0 }
};

int getStepLength (int bpm) {
  return 60000 / bpm / 4; // TODO: be more precise
}

void playStep (Synth* synth) {
  for (byte i = 0; i <= 8 - 1; i++) {
    synth->play(i, seqGate[i][currentStep]);
  }
};

auto getStepper (Synth* synth, int* currentStep) {
  return [&synth, currentStep] () {
    for (byte i = 0; i <= 8 - 1; i++) {
      synth->play(i, seqGate[i][*currentStep]);
    }
    *currentStep = *currentStep + 1;
  };
};

void check1 () {
  _PP("check1: playing step ");
  _PL(currentStep);
};

// void setupSequencer ( Synth* synth ) {
//   sequencerGoNextStep.setCallback(getStepper(synth, &currentStep));
//   _PP("setting interval ");
//   _PL(getStepLength(bpm));
//   // sequencerGoNextStep.setInterval(getStepLength(bpm));
//   // runner.addTask(sequencerGoNextStep);
// };

void start () {
  _PL("enabling seq");
  sequencerGoNextStep.enableDelayed();
}

void stop () {
  sequencerGoNextStep.disable();
}

Sequencer::Sequencer (Synth* synth): synth(synth), currentStep(0) {
  sequencerGoNextStep.setCallback([this] () {
    for (byte i = 0; i <= 8 - 1; i++) {
      if (seqGate[i][currentStep]) {
        this->synth->play(i, seqGate[i][currentStep]);
      }
    }
    if (currentStep >= 15) { currentStep = 0; }
    else {currentStep = currentStep + 1;}
  });
  setupHandles();
};


param_btn_handles Sequencer::getHandles() {
  return hs;
};

void Sequencer::start () {
  _PL("enabling seq");
  sequencerGoNextStep.enableDelayed();
  running = true;
}

void Sequencer::setupHandles () {
  set_param potH = [] (int target, int value) {
  };
  set_btn btnH = [this] (int target, bool value) {
    if (value == 0) return;
    switch (target) {
      case 7: if (running) { stop(); } else { start(); }; break;
    }
  };

  hs = {potH, btnH};

};

void Sequencer::stop () {
  sequencerGoNextStep.disable();
  running = false;
  currentStep = 0;
}

void Sequencer::setTempo (int bpm) {
  sequencerGoNextStep.setInterval(getStepLength(bpm));
};
