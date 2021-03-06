#ifndef INSTR_H_
#define INSTR_H_

#include <Arduino.h>
#include <instruments.h>

const unsigned char *const instruments[] PROGMEM = {
    INSTRUMENT_BDRUM1,   INSTRUMENT_SNARE1,   INSTRUMENT_SCRATCH,
    INSTRUMENT_SHRTVIBE, INSTRUMENT_JAVAICAN, INSTRUMENT_SDRUM2,
    INSTRUMENT_LOGDRUM1, INSTRUMENT_BASS1,    INSTRUMENT_JAVAICAN,
    INSTRUMENT_ACCORDN,  INSTRUMENT_BAGPIPE1, INSTRUMENT_BAGPIPE2,
    INSTRUMENT_BANJO1,   INSTRUMENT_BASS1,    INSTRUMENT_BASS2,
    INSTRUMENT_BASSHARP, INSTRUMENT_BASSOON1, INSTRUMENT_BASSTRLG,
    INSTRUMENT_BDRUM1,   INSTRUMENT_BELLONG,  INSTRUMENT_BELLS,
    INSTRUMENT_BELSHORT, INSTRUMENT_BNCEBASS, INSTRUMENT_BRASS1,
    INSTRUMENT_CBASSOON, INSTRUMENT_CELESTA,  INSTRUMENT_CLAR1,
    INSTRUMENT_CLAR2,    INSTRUMENT_CLARINET, INSTRUMENT_CLAVECIN,
    INSTRUMENT_CROMORNE, INSTRUMENT_CYMBAL1,  INSTRUMENT_ELCLAV1,
    INSTRUMENT_ELCLAV2,  INSTRUMENT_ELECFL,   INSTRUMENT_ELECVIBE,
    INSTRUMENT_ELGUIT1,  INSTRUMENT_ELGUIT2,  INSTRUMENT_ELGUIT3,
    INSTRUMENT_ELGUIT4,  INSTRUMENT_ELORGAN1, INSTRUMENT_ELPIANO1,
    INSTRUMENT_ELPIANO2, INSTRUMENT_EPIANO1A, INSTRUMENT_EPIANO1B,
    INSTRUMENT_FLUTE,    INSTRUMENT_FLUTE1,   INSTRUMENT_FLUTE2,
    INSTRUMENT_FRHORN1,  INSTRUMENT_FRHORN2,  INSTRUMENT_FSTRP1,
    INSTRUMENT_FSTRP2,   INSTRUMENT_FUZGUIT1, INSTRUMENT_FUZGUIT2,
    INSTRUMENT_GUITAR1,  INSTRUMENT_HARP1,    INSTRUMENT_HARP2,
    INSTRUMENT_HARP3,    INSTRUMENT_HARPE1,   INSTRUMENT_HARPSI1,
    INSTRUMENT_HARPSI2,  INSTRUMENT_HARPSI3,  INSTRUMENT_HARPSI4,
    INSTRUMENT_HARPSI5,  INSTRUMENT_HELICPTR, INSTRUMENT_HIHAT1,
    INSTRUMENT_HIHAT2,   INSTRUMENT_JAVAICAN, INSTRUMENT_JAZZGUIT,
    INSTRUMENT_JEWSHARP, INSTRUMENT_KEYBRD1,  INSTRUMENT_KEYBRD2,
    INSTRUMENT_KEYBRD3,  INSTRUMENT_LASER,    INSTRUMENT_LOGDRUM1,
    INSTRUMENT_MARIMBA1, INSTRUMENT_MARIMBA2, INSTRUMENT_MDRNPHON,
    INSTRUMENT_MLTRDRUM, INSTRUMENT_MOOGSYNT, INSTRUMENT_NOISE1,
    INSTRUMENT_OBOE1,    INSTRUMENT_ORGAN1,   INSTRUMENT_ORGAN2,
    INSTRUMENT_ORGAN3,   INSTRUMENT_ORGAN3A,  INSTRUMENT_ORGAN3B,
    INSTRUMENT_ORGNPERC, INSTRUMENT_PHONE1,   INSTRUMENT_PHONE2,
    INSTRUMENT_PIAN1A,   INSTRUMENT_PIAN1B,   INSTRUMENT_PIAN1C,
    INSTRUMENT_PIANO,    INSTRUMENT_PIANO1,   INSTRUMENT_PIANO2,
    INSTRUMENT_PIANO3,   INSTRUMENT_PIANO4,   INSTRUMENT_PIANOBEL,
    INSTRUMENT_PIANOF,   INSTRUMENT_POPBASS1, INSTRUMENT_RKSNARE1,
    INSTRUMENT_SAX1,     INSTRUMENT_SCRATCH,  INSTRUMENT_SCRATCH4,
    INSTRUMENT_SDRUM2,   INSTRUMENT_SHRTVIBE, INSTRUMENT_SITAR1,
    INSTRUMENT_SITAR2,   INSTRUMENT_SNAKEFL,  INSTRUMENT_SNARE1,
    INSTRUMENT_SNRSUST,  INSTRUMENT_SOLOVLN,  INSTRUMENT_STEELGT1,
    INSTRUMENT_STEELGT2, INSTRUMENT_STRINGS1, INSTRUMENT_STRNLONG,
    INSTRUMENT_SYN1,     INSTRUMENT_SYN2,     INSTRUMENT_SYN3,
    INSTRUMENT_SYN4,     INSTRUMENT_SYN5,     INSTRUMENT_SYN6,
    INSTRUMENT_SYN9,     INSTRUMENT_SYNBAL1,  INSTRUMENT_SYNBAL2,
    INSTRUMENT_SYNBASS1, INSTRUMENT_SYNBASS2, INSTRUMENT_SYNBASS4,
    INSTRUMENT_SYNSNR1,  INSTRUMENT_SYNSNR2,  INSTRUMENT_TINCAN1,
    INSTRUMENT_TOM1,     INSTRUMENT_TOM2,     INSTRUMENT_TRAINBEL,
    INSTRUMENT_TRIANGLE, INSTRUMENT_TROMB1,   INSTRUMENT_TROMB2,
    INSTRUMENT_TRUMPET1, INSTRUMENT_TRUMPET2, INSTRUMENT_TRUMPET3,
    INSTRUMENT_TRUMPET4, INSTRUMENT_TUBA1,    INSTRUMENT_VIBRA1,
    INSTRUMENT_VIBRA2,   INSTRUMENT_VIBRA3,   INSTRUMENT_VIOLIN1,
    INSTRUMENT_VIOLIN2,  INSTRUMENT_VIOLIN3,  INSTRUMENT_VLNPIZZ1,
    INSTRUMENT_WAVE,     INSTRUMENT_XYLO1,    INSTRUMENT_XYLO2,
    INSTRUMENT_XYLO3,
};

const unsigned char instNames[154][9] PROGMEM = {
    "BDRUM1",   "SNARE1",   "SCRATCH",
    "SHRTVIBE", "JAVAICAN", "SDRUM2",
    "LOGDRUM1", "BASS1",    "JAVAICAN",
    "ACCORDN",  "BAGPIPE1", "BAGPIPE2",
    "BANJO1",   "BASS1",    "BASS2",
    "BASSHARP", "BASSOON1", "BASSTRLG",
    "BDRUM1",   "BELLONG",  "BELLS",
    "BELSHORT", "BNCEBASS", "BRASS1",
    "CBASSOON", "CELESTA",  "CLAR1",
    "CLAR2",    "CLARINET", "CLAVECIN",
    "CROMORNE", "CYMBAL1",  "ELCLAV1",
    "ELCLAV2",  "ELECFL",   "ELECVIBE",
    "ELGUIT1",  "ELGUIT2",  "ELGUIT3",
    "ELGUIT4",  "ELORGAN1", "ELPIANO1",
    "ELPIANO2", "EPIANO1A", "EPIANO1B",
    "FLUTE",    "FLUTE1",   "FLUTE2",
    "FRHORN1",  "FRHORN2",  "FSTRP1",
    "FSTRP2",   "FUZGUIT1", "FUZGUIT2",
    "GUITAR1",  "HARP1",    "HARP2",
    "HARP3",    "HARPE1",   "HARPSI1",
    "HARPSI2",  "HARPSI3",  "HARPSI4",
    "HARPSI5",  "HELICPTR", "HIHAT1",
    "HIHAT2",   "JAVAICAN", "JAZZGUIT",
    "JEWSHARP", "KEYBRD1",  "KEYBRD2",
    "KEYBRD3",  "LASER",    "LOGDRUM1",
    "MARIMBA1", "MARIMBA2", "MDRNPHON",
    "MLTRDRUM", "MOOGSYNT", "NOISE1",
    "OBOE1",    "ORGAN1",   "ORGAN2",
    "ORGAN3",   "ORGAN3A",  "ORGAN3B",
    "ORGNPERC", "PHONE1",   "PHONE2",
    "PIAN1A",   "PIAN1B",   "PIAN1C",
    "PIANO",    "PIANO1",   "PIANO2",
    "PIANO3",   "PIANO4",   "PIANOBEL",
    "PIANOF",   "POPBASS1", "RKSNARE1",
    "SAX1",     "SCRATCH",  "SCRATCH4",
    "SDRUM2",   "SHRTVIBE", "SITAR1",
    "SITAR2",   "SNAKEFL",  "SNARE1",
    "SNRSUST",  "SOLOVLN",  "STEELGT1",
    "STEELGT2", "STRINGS1", "STRNLONG",
    "SYN1",     "SYN2",     "SYN3",
    "SYN4",     "SYN5",     "SYN6",
    "SYN9",     "SYNBAL1",  "SYNBAL2",
    "SYNBASS1", "SYNBASS2", "SYNBASS4",
    "SYNSNR1",  "SYNSNR2",  "TINCAN1",
    "TOM1",     "TOM2",     "TRAINBEL",
    "TRIANGLE", "TROMB1",   "TROMB2",
    "TRUMPET1", "TRUMPET2", "TRUMPET3",
    "TRUMPET4", "TUBA1",    "VIBRA1",
    "VIBRA2",   "VIBRA3",   "VIOLIN1",
    "VIOLIN2",  "VIOLIN3",  "VLNPIZZ1",
    "WAVE",     "XYLO1",    "XYLO2",
    "XYLO3",
};

#endif // INSTR_H"_
