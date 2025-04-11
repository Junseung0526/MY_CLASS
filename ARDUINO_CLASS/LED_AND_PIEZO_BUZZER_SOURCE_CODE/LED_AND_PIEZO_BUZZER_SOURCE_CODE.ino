const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int buttonPin = 2;
const int buzzerPin = 8;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  static int holdTime = 0;
  static int frequency = 500;
  static int delayTime = 500;

  if (digitalRead(buttonPin) == LOW) {
    holdTime += 100;
    frequency += 100;
    delayTime = max(50, delayTime - 50);


    if (holdTime % 300 < 100) {
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
    } else if (holdTime % 300 < 200) {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, LOW);
    } else {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, HIGH);
    }


    tone(buzzerPin, frequency);
    delay(delayTime);
  } 
  else {
    holdTime = 0;
    frequency = 500;
    delayTime = 500;
    noTone(buzzerPin);

    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
}
