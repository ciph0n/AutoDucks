#include "DigiKeyboard.h"
#define KEY_ESC     41
#define KEY_BACKSPACE 42
#define KEY_TAB     43
#define KEY_PRT_SCR 70
#define KEY_DELETE  76
#define KEY_ARROW_RIGHT 0x4F
#define KEY_ARROW_DOWN  0x51
#define KEY_ARROW_UP    0x52

void setup() {
  pinMode(1, OUTPUT);
  DigiKeyboard.delay(5000);
  DigiKeyboard.sendKeyStroke(0);

  // Win10 Auto Wipe Exp3
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_TAB, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_TAB, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_TAB, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, 0);
  DigiKeyboard.delay(100);
  // Activate Windows Key
  DigiKeyboard.delay(10000);
  DigiKeyboard.delay(10000);
  DigiKeyboard.delay(7500);
  DigiKeyboard.sendKeyStroke(KEY_TAB, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_TAB, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_TAB, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, 0);
  DigiKeyboard.delay(3000);
  // Windows Version Selection
  DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_TAB, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, 0);
  DigiKeyboard.delay(2250);
  // Windows Version Selection
  DigiKeyboard.sendKeyStroke(KEY_SPACE, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_TAB, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, 0);
  DigiKeyboard.delay(4000);
  // Windows Partition Manager
  DigiKeyboard.sendKeyStroke(KEY_ARROW_UP, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_UP, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_UP, 0);
  DigiKeyboard.delay(100);
  // Deletion of ONE partition
  DigiKeyboard.sendKeyStroke(KEY_TAB, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_RIGHT, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, 0);
  DigiKeyboard.delay(1500);
  // Deletion of TWO partition
  DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_TAB, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_RIGHT, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, 0);
  DigiKeyboard.delay(1500);
  // Deletion of THREE partition
  DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_TAB, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_RIGHT, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, 0);
  DigiKeyboard.delay(1500);
  // Deletion of FOUR partition
  DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_TAB, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_RIGHT, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, 0);
  DigiKeyboard.delay(1000);
  // WIPE TIME
  DigiKeyboard.sendKeyStroke(KEY_TAB, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_TAB, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_TAB, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_TAB, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, 0);

}


void loop() {
  digitalWrite(1, HIGH);
  delay(1000);
  digitalWrite(1, LOW);
  delay(1000);
}
