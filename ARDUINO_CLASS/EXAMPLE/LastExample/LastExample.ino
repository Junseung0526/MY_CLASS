#include <LedControl.h>

// DIN=11, CLK=13, CS=10, 장치 수=1
LedControl lc = LedControl(11, 12, 10, 1);

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {
  byte images[4][8] = {
    { // Heart
      B01100110,
      B10011001,
      B10000001,
      B10000001,
      B01000010,
      B00100100,
      B00011000,
      B00000000 },
    { // Angry face
      B00000000,
      B01000010,
      B10100101,
      B00000000,
      B00000000,
      B01111110,
      B01000010,
      B00111100 },
    { // Smiling face
      B01111110,
      B10000001,
      B10100101,
      B10000001,
      B10100101,
      B10011001,
      B10000001,
      B01111110 },
    { 
      B00111100,
      B01000010,
      B10011001,
      B10111101,
      B10111101,
      B10011001,
      B01000010,
      B00111100 },
};

for (int k = 0; k < 3; k++) {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, images[k][i]);
  }
  delay(2000);
  lc.clearDisplay(0);
}
}
