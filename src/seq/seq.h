#ifndef __SEQ_H_
#define __SEQ_H_

#include <Arduino.h>
#include "sch/header.hpp"
#include "synth/synth.hpp"

extern Task sequencerGoNextStep;
void setupSequencer (Synth* synth);
void start ();
void stop ();

void check ();

class Sequencer {
  public:
    Sequencer (Synth* synth);
    void start ();
    void stop ();
    void setTempo (int bpm);
    Synth* synth;
  private:
    int currentStep = 0;
};
#endif // __SEQ_H_
