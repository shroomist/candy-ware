#ifndef __SEQ_H_
#define __SEQ_H_

#include <Arduino.h>
#include "sch/header.hpp"
#include "synth/synth.hpp"
#include "ctrl/ctrl.hpp"

extern Task sequencerGoNextStep;
void setupSequencer (Synth* synth);
void start ();
void stop ();

void check ();

class Sequencer: public Ctrl {
  public:
    Sequencer (Synth* synth);
    void start ();
    void stop ();
    void setTempo (int bpm);
    Synth* synth;
    param_btn_handles getHandles();
  private:
    param_btn_handles hs;
    int currentStep = 0;
    void setupHandles ();
    bool running = true;
};
#endif // __SEQ_H_
