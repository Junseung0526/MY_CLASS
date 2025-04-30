#include <Servo.h>

const int servoPin = 9;
const int buttonPin = 2;
const int ledPin = 3;
const int buzzerPin = 4;

Servo myServo;

bool doorOpen = false;
bool lastButtonState = HIGH;

void setup() {
  myServo.attach(servoPin);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  myServo.write(0);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && buttonState == LOW) {
    doorOpen = !doorOpen;

    if (doorOpen) {
      myServo.write(90);
      digitalWrite(ledPin, HIGH);
      tone(buzzerPin, 1000, 100);
      delay(150);
      tone(buzzerPin, 1500, 100);
      delay(150);
      tone(buzzerPin, 2000, 100);
      delay(150);
      noTone(buzzerPin);
    } else {
      myServo.write(0);
      digitalWrite(ledPin, LOW);
      tone(buzzerPin, 500, 300); 
      delay(350);
      tone(buzzerPin, 400, 300); 
      delay(350);
      noTone(buzzerPin);
    }

    delay(300);
  }

  lastButtonState = buttonState;
}
