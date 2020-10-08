#include "mux.h"
#include "btn.h"

// bool lastButtonPressed[BUTTON_COUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool buttonLatching[BUTTON_COUNT] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool isButtonPressed[BUTTON_COUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void setupBtn () {
  pinMode(BTN_PIN, INPUT_PULLUP);
}

bool btnRead () {
  return (!digitalRead(BTN_PIN));
}

btn_reading btnReading{false,false};

btn_reading* getBtnReading (byte target) {
  btnReading.target = target;
  btnReading.value = btnRead();
  btnReading.isNew = isButtonPressed[target] != btnReading.value;
  if (btnReading.isNew) {
    isButtonPressed[target] = btnReading.value;
  }
  return &btnReading;
}

// void btnsReadAll () {

//   for (byte i = 0; i <= 15; i++) {
//     queryMux(i); // TODO: delay 30ms
//     isButtonPressed[i] = btnRead();
//     if (isButtonPressed[i] != lastButtonPressed[i]) {

//       // update the switch state
//       lastButtonPressed[i] = isButtonPressed[i];

//       //"HIGH condition code"
//       //
//       if (isButtonPressed[i] == true) {

//         buttonLatching[i] = !buttonLatching[i];
        // select channel with keyboard

        // channel=i;
        // TODO: CHANGE PARAM IN SYNTH
        //////////////////////////////
        // if (i > 7 && FALSE) {

        //   byte keypressed = 16 - i;
        //   if (keypressed == 1) {
        //     changeParam(6, NOTE_C);
        //   }
        //   if (keypressed == 2) {
        //     changeParam(6, NOTE_D);
        //   }
        //   if (keypressed == 3) {
        //     changeParam(6, NOTE_E);
        //   }
        //   if (keypressed == 4) {
        //     changeParam(6, NOTE_F);
        //   }
        //   if (keypressed == 5) {
        //     changeParam(6, NOTE_G);
        //   }
        //   if (keypressed == 63) {
        //     changeParam(6, NOTE_A);
        //   }
        //   if (keypressed == 7) {
        //     changeParam(6, NOTE_B);
        //   }
        // }
      }
      // while pressing CHAN  key
      // TODO: GLOBAL SELECT CHANNEL
      //////////////////////////////
      // if (bitRead(keyboardAccumulator, 3)) {
      //   for (byte i = 8; i <= 15; i++) {
      //     if (bitRead(keyboardAccumulator, i)) {
      //       channel = 15 - i;
      //       // turn off auto
      //       buttonLatching[6] = 0;
      //       Serial.print("SELECTED CHANNEL ");
      //       Serial.println(channel);
      //     }
      //   }
      // }
      //////////////////////////////

      // while pressing keyboard FN3
      // TODO: SEQUENCER LENGTH, LOAD SONG
      ////////////////////////////////////
      //  if (bitRead(keyboardAccumulator, 0)) {

      //   if (bitRead(keyboardAccumulator, 4)) {

      //     sequenceLength = 16;
      //     Serial.println("sequenceLength = 16;");
      //   }
      //   if (bitRead(keyboardAccumulator, 5)) {

      //     sequenceLength = 8;
      //     Serial.println("sequenceLength =8;");
      //   }
      //   for (byte i = 8; i <= 15; i++) {
      //     if (bitRead(keyboardAccumulator, i)) {

      //       int songno = 15 - i;

      //       loadSong(songno);
      //     }
      //   }
      // }
      ////////////////////////////////////
      //
      // TODO: ENTER EDIT MODE
      ////////////////////////////////////
      // while pressing ch+ enter edit mode of selected channel
      // if (bitRead(keyboardAccumulator, 4)) {

      //   for (byte i = 8; i <= 15; i++) {
      //     if (bitRead(keyboardAccumulator, i)) {

      //       int whichChannel = 15 - i;
      //       channel = whichChannel;
      //       // auto off
      //       buttonLatching[6] = 0;
      //       enterEditMode(whichChannel);
      //     }
      //   }
      // }
      ////////////////////////////////////
    }
  }
}

// byte isEditMode = 15;
// void enterEditMode(byte whichChannel) {
//   isEditMode = whichChannel;

//   for (byte j = 0; j <= 15; j++) {
//     bool isLedOn = seqGate[j][whichChannel];
//     if (mainBeat == j) {
//       // invert current beat
//       switchLed(j, !isLedOn);
//     } else {
//       // lid on gates
//       switchLed(j, isLedOn);
//     }
//   }

//   // isEditMode 15 = no edit mode, 0 to 7 > editing that channel
// }

// void exitEditMode() {
//   isEditMode = 15;
//   // switchOffLeds
//   for (byte j = 0; j <= 15; j++) {

//     switchLed(j, 0);
//   }
//   //turn auto on
//   buttonLatching[6]=1;
//   switchLed(9, 1);
// }

// void keyboardPress(int keyPressed) {

//   if (isEditMode == 15) {
//     // PLAYS CORRESPONDING NOTE
//     opl2.playNote(channel, octave[channel], keyPressed);
//   } else {
//     // WE ARE IN  change toggle gate MODE SO WE TOGGLE GATES
//     // Serial.println("keypressed: ");
//     // Serial.print(keyPressed);

//     seqGate[keyPressed][channel] = !seqGate[keyPressed][channel];
//     if (seqGate[keyPressed][channel]) {
//       switchLed(keyPressed, 1);
//       // Serial.println("TRUE ");
//     } else {
//       switchLed(keyPressed, 0);
//       // Serial.println("FALSE ");
//     }
//   }
// }

// int keyboardAccumulator = 0;
// void calculeKeyboardAccumulator() {
//   keyboardAccumulator = 0;
//   for (byte j = 0; j <= 15; j++) {
//     bitWrite(keyboardAccumulator, j, buttonReadMux(j));
//   }
// }

// void pianoKeyboardManager() {
//   static byte lastPressed;
//   calculeKeyboardAccumulator();
//   // dont play notes while pressing function combos
//   if (!bitRead(keyboardAccumulator, 0) or !bitRead(keyboardAccumulator, 3) or
//       !bitRead(keyboardAccumulator, 4) or !bitRead(keyboardAccumulator, 5)) {
//     if (bitRead(keyboardAccumulator, 15) && lastPressed != 15) {
//       keyboardPress(NOTE_C);
//       Serial.println("C1");
//       lastPressed = 15;
//     }
//     if (bitRead(keyboardAccumulator, 14) && lastPressed != 14) {
//       keyboardPress(NOTE_D);
//       Serial.println("D1");
//       lastPressed = 14;
//     }
//     if (bitRead(keyboardAccumulator, 13) && lastPressed != 13) {
//       keyboardPress(NOTE_E);
//       Serial.println("E1");
//       lastPressed = 13;
//     }
//     if (bitRead(keyboardAccumulator, 12) && lastPressed != 12) {
//       keyboardPress(NOTE_F);
//       Serial.println("F1");
//       lastPressed = 12;
//     }
//     if (bitRead(keyboardAccumulator, 11) && lastPressed != 11) {
//       keyboardPress(NOTE_G);
//       Serial.println("G1");
//       lastPressed = 11;
//     }
//     if (bitRead(keyboardAccumulator, 10) && lastPressed != 10) {
//       keyboardPress(NOTE_A);
//       Serial.println("A1");
//       lastPressed = 10;
//     }
//     if (bitRead(keyboardAccumulator, 9) && lastPressed != 9) {
//       keyboardPress(NOTE_B);
//       Serial.println("B1");
//       lastPressed = 9;
//     }
//   }
// }

// void editGateManager() {

//   static bool released;
//   calculeKeyboardAccumulator();
//   if (keyboardAccumulator == 0)
//     released = true;

//   if (bitRead(keyboardAccumulator, 15) && released) {
//     keyboardPress(8);
//     Serial.println("KEY 1");
//     released = false;
//   }
//   if (bitRead(keyboardAccumulator, 14) && released) {
//     keyboardPress(9);
//     Serial.println("KEY 2");
//     released = false;
//   }
//   if (bitRead(keyboardAccumulator, 13) && released) {
//     keyboardPress(10);
//     Serial.println("KEY 3");
//     released = false;
//   }
//   if (bitRead(keyboardAccumulator, 12) && released) {
//     keyboardPress(11);
//     Serial.println("KEY 4");
//     released = false;
//   }
//   if (bitRead(keyboardAccumulator, 11) && released) {
//     keyboardPress(12);
//     Serial.println("KEY 5");
//     released = false;
//   }
//   if (bitRead(keyboardAccumulator, 10) && released) {
//     keyboardPress(13);
//     Serial.println("KEY 6");
//     released = false;
//   }
//   if (bitRead(keyboardAccumulator, 9) && released) {
//     keyboardPress(14);
//     Serial.println("KEY 7");
//     released = false;
//   }
//   if (bitRead(keyboardAccumulator, 8) && released) {
//     keyboardPress(15);
//     Serial.println("KEY 8");
//     released = false;
//   }
//   if (bitRead(keyboardAccumulator, 7) && released) {
//     keyboardPress(0);
//     Serial.println("KEY 9");
//     released = false;
//   }
//   if (bitRead(keyboardAccumulator, 6) && released) {
//     keyboardPress(1);
//     Serial.println("KEY 10");
//     released = false;
//   }
//   if (bitRead(keyboardAccumulator, 5) && released) {
//     keyboardPress(2);
//     Serial.println("KEY 11");
//     released = false;
//   }
//   if (bitRead(keyboardAccumulator, 4) && released) {
//     keyboardPress(3);
//     Serial.println("KEY 12");
//     released = false;
//   }
//   if (bitRead(keyboardAccumulator, 3) && released) {
//     keyboardPress(4);
//     Serial.println("KEY 13");
//     released = false;
//   }
//   if (bitRead(keyboardAccumulator, 2) && released) {
//     keyboardPress(5);
//     Serial.println("KEY 14");
//     released = false;
//   }
//   if (bitRead(keyboardAccumulator, 1) && released) {
//     keyboardPress(6);
//     Serial.println("KEY 15");
//     released = false;
//   }
//   if (bitRead(keyboardAccumulator, 0) && released) {
//     keyboardPress(7);
//     Serial.println("KEY 16");
//     released = false;
//   }
// }
