const int segmentPins[8] = {2, 3, 4, 5, 6, 8, 9, 10};
const int buttonPin = 11;
const int piezoPin = 12;
const int ledPin = 13;


const byte digits[10] = {
  B11000000, // 0
  B11111001, // 1
  B10100100, // 2
  B10110000, // 3
  B10011001, // 4
  B10010010, // 5
  B10000010, // 6
  B11111000, // 7
  B10000000, // 8
  B10010000  // 9
};

int guess;
int secretNumber;
bool buttonPressed = false;
unsigned long buttonPressStartTime = 0;
const unsigned long longPressThreshold = 1000; // 1초

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], LOW);
  }
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(piezoPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  randomSeed(analogRead(A0));
  secretNumber = random(10);
  guess = random(10);
  displayNumber(guess);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && !buttonPressed) {
    buttonPressed = true;
    buttonPressStartTime = millis();
  }


  if (buttonState == HIGH && buttonPressed) {
    buttonPressed = false;
    if (millis() - buttonPressStartTime < longPressThreshold) {
      guess = random(10);
      displayNumber(guess);
      checkGuess();
    }
  }


  if (buttonState == LOW && buttonPressed && (millis() - buttonPressStartTime >= longPressThreshold)) {
    resetGuess();
    while (digitalRead(buttonPin) == LOW);
    buttonPressed = false;
  }

  delay(50);
}

void displayNumber(int num) {
  if (num >= 0 && num <= 9) {
    byte segmentData = digits[num];
    for (int i = 0; i < 7; i++) {
      digitalWrite(segmentPins[i], bitRead(segmentData, i));
    }
    digitalWrite(segmentPins[7], HIGH);
  }
}

void resetGuess() {
  guess = 0;
  displayNumber(guess);
}

void checkGuess() {
  if (guess == secretNumber) {
    for (int i = 0; i < 3; i++) {
      tone(piezoPin, 1000);
      digitalWrite(ledPin, HIGH);
      delay(200);
      noTone(piezoPin);
      digitalWrite(ledPin, LOW);
      delay(200);
    }
    secretNumber = random(10);
    resetGuess();
  } else {
    tone(piezoPin, 200);
    digitalWrite(ledPin, HIGH);
    delay(500);
    noTone(piezoPin);
    digitalWrite(ledPin, LOW);
  }
}