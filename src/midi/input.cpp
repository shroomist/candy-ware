#include "input.hpp"

#define MIDI_CH_START 9
#define MIDI_CH_END 17

byte track = 0;

HardwareSerial Serial2(PA3, PA2); // RX, TX -- to unused pin PB1
MIDI_CREATE_INSTANCE(HardwareSerial, Serial2, midi2);

void handleNoteOn(byte channel, byte pitch, byte velocity) {
  if (channel >= MIDI_CH_START && channel < MIDI_CH_END) {
    track = channel - MIDI_CH_START;
    synth.handleNote(track, pitch - 60, velocity);
  }
}

void handleNoteOff(byte channel, byte pitch, byte velocity) {
  if (channel >= MIDI_CH_START && channel < MIDI_CH_END) {
    byte track = channel - MIDI_CH_START;
    synth.handleNoteOff(track);
  }
}

MidiCtrl::MidiCtrl(Synth *synth) : synth(synth) {

  midi2.begin(MIDI_CHANNEL_OMNI);
  midi2.setHandleNoteOn(handleNoteOn);
  midi2.setHandleNoteOff(handleNoteOff);

  midiRead.setCallback([this]() { midi2.read(); });
};
