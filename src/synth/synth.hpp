#ifndef __SYNTH_H_
#define __SYNTH_H_

#include <OPL2.h>
#include "../ctrl/ctrl.hpp"

// OPL2 opl2;
void initOPL();

class Synth: public Ctrl {
  public:
    Synth();
    param_btn_handles getHandles();
    void changeParam(byte ch, byte param, int value);
    byte octave[8];
    byte channel;
    void handleNote(byte inst, byte pitch, byte velo);
    void handleNoteOff(byte inst);
};

void tremVibratos(byte channel, byte value);
void combinedWaveforms(byte channel, byte value);

const int boundaries[16][2] = { // was [24][2]
    {15, 0}, // 0 ATT 1
    {15, 0}, // 1 DEC 1
    {15, 0}, // 2 SUS 1
    {15, 0}, // 3 REL 1
    {0, 15}, // 4 MULT 1
    {0, 7},  // 5 FEED
    {0, 24}, // 6 NOTE
    {64, 0}, // 7 VOL 1
    {15, 0}, // 8 ATT 2
    {15, 0}, // 9 DEC 2
    {15, 0}, // 10 SUS 2
    {15, 0}, // 11 REL 2
    {0, 15}, // 12 MULT 2
    {0, 16}, // 13 MAPPED WAVETYPES  16
    {0, 64}, // 14 tremolos vibratos
    {64, 0}  // 15 VOL2
};


#endif // __SYNTH_H_
