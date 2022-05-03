#include "DigiKeyboard.h"
#define KEY_ESC     41
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
  // AutoPilot Enroller Exp4
  DigiKeyboard.delay(2000);  DigiKeyboard.sendKeyStroke(KEY_F10,MOD_SHIFT_LEFT | 0);
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("powershell"));
  DigiKeyboard.delay(500);  DigiKeyboard.sendKeyStroke(KEY_ENTER,0);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print(F("$serial = Get-WmiObject Win32_bios | Select -expand serialnumber; Rename-Computer REDACTED-$serial;$env:Path += ")); DigiKeyboard.print(char(34)); DigiKeyboard.print(F(";C:")); DigiKeyboard.print(char(92)); DigiKeyboard.print(F("Program Files")); DigiKeyboard.print(char(92)); DigiKeyboard.print(F("WindowsPowerShell")); DigiKeyboard.print(char(92)); DigiKeyboard.print(F("Scripts")); DigiKeyboard.print(char(34)); DigiKeyboard.print(F(";Set-ExecutionPolicy -Scope Process -ExecutionPolicy RemoteSigned;Install-Script -Name Get-WindowsAutoPilotInfo;Get-WindowsAutoPilotInfo -online"));
  DigiKeyboard.delay(2750);  DigiKeyboard.sendKeyStroke(KEY_ENTER,0);
  DigiKeyboard.delay(250);
  DigiKeyboard.print(F("Y"));
  DigiKeyboard.delay(250);  DigiKeyboard.sendKeyStroke(KEY_ENTER,0);
  DigiKeyboard.delay(5000);
  DigiKeyboard.print(F("A"));
  DigiKeyboard.delay(250);  DigiKeyboard.sendKeyStroke(KEY_ENTER,0);
}

void loop() {
  digitalWrite(1, HIGH);
  delay(1000);
  digitalWrite(1, LOW);
  delay(1000);
}
