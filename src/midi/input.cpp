#include "input.hpp"

#define MIDI_DRUM_CH 60

HardwareSerial Serial2(PA3, PA2); // RX, TX -- to unused pin PB1
// #include <SoftwareSerial.h>
// SoftwareSerial midiSerial(PB11, PB1); // RX, TX -- to unused pin PB1
MIDI_CREATE_INSTANCE(HardwareSerial, Serial2, midi2);

void handleNoteOn(byte channel, byte pitch, byte velocity) {
  _PP("ch: ");
  _PL(channel);
  if (channel == 16) {
    _PP("trk: ");
    byte track = pitch - 35;
    _PL(track);
    synth.play(track, 1);
  }
  if (channel < 16 && channel > 9) {
    byte track = channel - 10;
    synth.handleNote(track, pitch, velocity);
  }

  _PP("MIDI NOTE ON ");
  _PP(" ch ");
  _PP(channel);
  _PP("pch ");
  _PP(pitch);
  _PP("velo ");
  _PL(velocity);
  // synth.play(pitch, 1);
}

void handleNoteOff(byte channel, byte pitch, byte velocity) {
  if (channel == 55) {
    byte track = pitch - 35;
    synth.play(track, 0);
  }
  _PP("MIDI NOTE OfF ");
  _PP(" ch ");
  _PP(channel);
  _PP("pch ");
  _PP(pitch);
  _PP("velo ");
  _PL(velocity);
  if (channel < 16 && channel > 9) {
    byte track = channel - 10;
    synth.handleNoteOff(track);
  }
}

MidiCtrl::MidiCtrl(Synth *synth) : synth(synth) {

  midi2.begin(MIDI_CHANNEL_OMNI);
  midi2.setHandleNoteOn(handleNoteOn);
  midi2.setHandleNoteOff(handleNoteOff);

  midiRead.setCallback([this]() { midi2.read(); });
};
