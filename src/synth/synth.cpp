#include "synth.hpp"
#include "../state.hpp"
// #include <instruments.h>
#include "instr.hpp"
#include "debug.h"

OPL2 opl2 = OPL2(PB8,PB9,PB10);

void Synth::handleNote(byte track, byte pitch, byte velocity) {
  _PP("playNote ");
  _PP(track);
  _PP(" pitch ");
  _PP(pitch / 12)
  opl2.playNote(track,  pitch / 12, pitch % 12);
}
void Synth::handleNoteOff(byte track) {
  opl2.setKeyOn(track, false);
}


void initOPL () {
  opl2.init();

  for(int i=0; i<9; i++) {
    opl2.setInstrument(i, opl2.loadInstrument( instruments[i] ));
    opl2.setBlock(i, 0); // octave
    channelInstr[i] = i;
  };

  // Set octave and frequency for bass drum.
  // opl2.setBlock(6, 5);
  // opl2.setFNumber(6, opl2.getNoteFNumber(NOTE_C));

  // // Set octave and frequency for snare drum and hi-hat.
  // opl2.setBlock(7, 2);
  // opl2.setFNumber(7, opl2.getNoteFNumber(NOTE_C));
  // // Set low volume on hi-hat
  // opl2.setVolume(7, OPERATOR1, 16);

  // // Set octave and frequency for tom tom and cymbal.
  // opl2.setBlock(8, 3);
  // opl2.setFNumber(8, opl2.getNoteFNumber(NOTE_A));
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
        _PP("ch ");
        _PP(channel);
        _PP(" ");
        _PL(octave[channel]);
        // opl2.setBlock(channel, value >> 2);
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
  octave{0,0,0,0,0,0},
  channel(0)
{};

param_btn_handles Synth::getHandles() {
  set_param potH = [this] (int t, int v) {
    int synthValue = map(v, 0, 4096, boundaries[t][0], boundaries[t][1]);
    changeParam(channel, t, synthValue);
  };
  set_btn btnH = [this](int t, bool v) {
    _PP("push ");
    _PP(t);
    _PP(" v = ");
    _PL(v);
    if (t >= 0 && t <9){
    channel = t;
    currentChannel = t;
      if (v) {
        handleNote(t, octave[t], NOTE_C);
      } else {
        handleNoteOff(t);
      }
    }
    if (t == 10 && v) {
      channelInstr[channel] = channelInstr[channel] - 1;
      opl2.setInstrument(channel, opl2.loadInstrument( instruments[channelInstr[channel]] ));
    }
    if (t == 11 && v) {
      channelInstr[channel] = channelInstr[channel] + 1;
      opl2.setInstrument(channel, opl2.loadInstrument( instruments[channelInstr[channel]] ));
    }

  };
  return param_btn_handles{potH, btnH};
};

