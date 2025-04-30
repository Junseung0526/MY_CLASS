#include <Servo.h>
Servo myServo;
const int buttonPin = 5;
int input;
int mop = A0;

void setup() {
  myServo.attach(A3);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  Serial.println("1: 45도, 2: 90도, 3: 180도 입력하세요");
}

void loop() {

int mopValue = analogRead(mop);
int mapMopValue = map(mopValue, 0, 1023, 0, 180);
myServo.write(mapMopValue);

  if (Serial.available()) {
    input = Serial.parseInt();
    switch (input) {
      case 1:
        myServo.write(45);
        delay(1000);
        myServo.write(0);
        break;

      case 2:
        myServo.write(90);
        delay(1000);
        myServo.write(0);
        break;

      case 3:
        myServo.write(180);
        delay(1000);
        myServo.write(0);
        break;

      default:
        Serial.println("1, 2, 3 중 하나를 입력하세요");
        break;
    }
  }
}
