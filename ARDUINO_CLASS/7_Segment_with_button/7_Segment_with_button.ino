const int segmentPins[8] = {2, 3, 4, 5, 6, 7, 8, 9}; // a, b, c, d, e, f, g, dp
const int buttonPin = 10;

int buttonState = 0;
int lastButtonState = 0;
int currentIndex = 0;

const int totalItems = 14;

// 순서: 0~9, P, L, A, Y
const bool patterns[14][8] = {
  // a  b  c  d  e  f  g  dp
  {1, 1, 1, 1, 1, 1, 0, 1}, // 0
  {0, 1, 1, 0, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1, 0}, // 2
  {1, 1, 1, 1, 0, 0, 1, 0}, // 3
  {0, 1, 1, 0, 0, 1, 1, 0}, // 4
  {1, 0, 1, 1, 0, 1, 1, 0}, // 5
  {1, 0, 1, 1, 1, 1, 1, 0}, // 6
  {1, 1, 1, 0, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1, 0}, // 8
  {1, 1, 1, 1, 0, 1, 1, 0}, // 9
  {1, 1, 0, 0, 1, 1, 1, 0}, // P
  {0, 0, 0, 1, 1, 1, 0, 0}, // L
  {1, 1, 1, 0, 1, 1, 1, 0}, // A
  {0, 1, 1, 1, 0, 1, 1, 0}  // Y
};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], LOW);
  }

  pinMode(buttonPin, INPUT_PULLUP);
  displayPattern(currentIndex);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && buttonState == LOW) {
    currentIndex++;
    if (currentIndex >= totalItems) currentIndex = 0;
    displayPattern(currentIndex);
    delay(200);
  }

  lastButtonState = buttonState;
}

void displayPattern(int index) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(segmentPins[i], patterns[index][i] ? HIGH : LOW);
  }
}
