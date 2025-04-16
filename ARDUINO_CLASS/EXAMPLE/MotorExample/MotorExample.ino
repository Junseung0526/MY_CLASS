#include <Servo.h>;
Servo myservo;

int motor = 2;
int sw = 6;
int sb = 5;

int speed = 127;

void setup() {
  pinMode(motor, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
  Serial.begin(9600);
  // myservo.attach(sb);
}

void loop() {
  int MValue = digitalRead(sw);
  if (MValue == LOW) {
    analogWrite(motor, speed);
    // myservo.write(90);
  } else {
    analogWrite(motor, 0);
  }
}