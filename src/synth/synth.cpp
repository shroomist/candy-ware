#include "synth.hpp"
#include <instruments.h>
#include "debug.h"

OPL2 opl2 = OPL2(PB8,PB9,PB10);

void initOPL () {
  opl2.init();
  opl2.setPercussion(true);
  Instrument piano = opl2.loadInstrument(INSTRUMENT_PIANO1);
  opl2.setInstrument(0, piano);
  opl2.setBlock(0, 4);
  Instrument bass = opl2.loadInstrument(INSTRUMENT_BDRUM1);
  Instrument snare = opl2.loadInstrument(INSTRUMENT_RKSNARE1);
  Instrument tom = opl2.loadInstrument(INSTRUMENT_TOM2);
  Instrument cymbal = opl2.loadInstrument(INSTRUMENT_CYMBAL1);
  Instrument hihat = opl2.loadInstrument(INSTRUMENT_HIHAT2);
  opl2.setDrumInstrument(bass);
  opl2.setDrumInstrument(snare);
  opl2.setDrumInstrument(tom);
  opl2.setDrumInstrument(cymbal);
  opl2.setDrumInstrument(hihat);
  // opl2.setBlock(6, 4); //bd
  // opl2.setFNumber(6, opl2.getNoteFNumber(NOTE_C));
};

void Synth::changeParam(byte channel, byte param, int value) {

  switch (param) {
    case 0:
      opl2.setAttack(channel, OPERATOR1, value);
      break;
    case 1:
      opl2.setDecay(channel, OPERATOR1, value);
      break;
    case 2:
      opl2.setSustain(channel, OPERATOR1, value);
      break;
    case 3:
      opl2.setRelease(channel, OPERATOR1, value);
      break;
    case 4:
      opl2.setMultiplier(channel, OPERATOR1, value);
      break;
    case 5:
      opl2.setFeedback(channel, value);
      break;
    case 6:
      // with no shift we change octaves
      // if (bitRead(!keyboardAccumulator, 0)) {
        octave[channel] = value >> 2;
        opl2.setBlock(channel, value >> 2);
        _PP("set octave ch:");
        _PP(channel);
        _PP(" : ");
        _PL(value >> 2);
      // } else { // while pressing SHIFT we change notes
      //   opl2.playNote(channel, octave[channel], value);
      //   Serial.print("6 NOTE: ");
      //   Serial.println(value);
      // }
      break;
    case 7:
      opl2.setVolume(channel, OPERATOR1, value);
      break;
    case 8:
      opl2.setAttack(channel, OPERATOR2, value);
      break;
    case 9:
      opl2.setDecay(channel, OPERATOR2, value);
      break;
    case 10:
      opl2.setSustain(channel, OPERATOR2, value);
      break;
    case 11:
      opl2.setRelease(channel, OPERATOR2, value);
      break;
    case 12:
      opl2.setMultiplier(channel, OPERATOR2, value);
      break;
    case 13:
      combinedWaveforms(channel, value);
      break;
    case 14:
     tremVibratos(channel, value);
      break;
    case 15:
      opl2.setVolume(channel, OPERATOR2, value);
      break;

    case 131:
      opl2.setWaveForm(channel, OPERATOR1, value);
      break;
  }
}

void combinedWaveforms(byte channel, byte value) {
  byte op1 = bitRead(value, 0) + bitRead(value, 1) * 2;
  byte op2 = bitRead(value, 2) + bitRead(value, 3) * 2;
  opl2.setWaveForm(channel, OPERATOR1, op1);
  opl2.setWaveForm(channel, OPERATOR2, op2);
}

void tremVibratos(byte channel, byte value) {

  opl2.setDeepVibrato(bitRead(value, 4));
  opl2.setDeepTremolo(bitRead(value, 5));
  opl2.setTremolo(channel, 0, bitRead(value, 3));
  opl2.setTremolo(channel, 1, bitRead(value, 1));
  opl2.setVibrato(channel, 0, bitRead(value, 0));
  opl2.setVibrato(channel, 1, bitRead(value, 2));
}

Synth::Synth():
  octave{4,4,4,4,4,4},
  drums{DRUM_BASS,DRUM_SNARE,DRUM_TOM,DRUM_HI_HAT,DRUM_CYMBAL},
  channel(0)
{};

param_btn_handles Synth::getHandles() {
  set_param potH = [this] (int t, int v) {
    int synthValue = map(v, 0, 4096, boundaries[t][0], boundaries[t][1]);
    changeParam(channel, t, synthValue);
  };
  set_btn btnH = [this] (int t, bool v) {
    if (t <= 3) {
      channel = 6+t;
      opl2.playDrum(drums[t], octave[channel], NOTE_C);
      opl2.setKeyOn(t, v);
    }
    else
    {
      channel = 0;
      opl2.playNote(0, octave[0], 15-t);
    }
  };
  return param_btn_handles{potH, btnH};
};

