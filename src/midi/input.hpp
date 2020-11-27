#ifndef __INPUT_H_
#define __INPUT_H_

#include "debug.h"

#include <Arduino.h>
#include "sch/header.hpp"
#include "synth/synth.hpp"
#include "ctrl/ctrl.hpp"

#include <MIDI.h>

extern Task midiRead;
extern Synth synth;

class MidiCtrl {
  public:
    MidiCtrl (Synth* synth);
    Synth* synth;
};


#endif // __INPUT_H_
