#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define TRIG_PIN 11
#define ECHO_PIN 12
#define RED_PIN 3
#define GREEN_PIN 5
#define BLUE_PIN 6
#define BUTTON_PIN 8
#define BUZZER_PIN 9

unsigned long lastBeepTime = 0;
float maxDistance = 100.0;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Dist: --.- cm");
  lcd.setCursor(0, 1);
  lcd.print("Max: 100.0 cm");

  setLEDColor(0, 255, 0);
}

void loop() {
  float distance = getDistance();

  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance, 1);
  lcd.print(" cm   ");

  handleDistanceFeedback(distance);
  handleButtonCalibration(distance);

  delay(50);
}

float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2.0;
  return distance;
}

void handleDistanceFeedback(float d) {
  unsigned long now = millis();
  static unsigned long beepInterval = 0;

  if (d >= maxDistance) {
    setLEDColor(0, 255, 0);
    noTone(BUZZER_PIN);
  } else if (d > 40) {
    setLEDColor(255, 255, 0);
    beepInterval = 250;
  } else if (d > 20) {
    setLEDColor(255, 128, 0);
    beepInterval = 100;
  } else {
    setLEDColor(255, 0, 0);
    beepInterval = 50;
  }

  if (d < maxDistance && now - lastBeepTime >= beepInterval) {
    tone(BUZZER_PIN, 1000, 20);
    lastBeepTime = now;
  }
}

void handleButtonCalibration(float currentDistance) {
  static bool isPressed = false;
  static unsigned long pressStart = 0;

  bool buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW && !isPressed) {
    isPressed = true;
    pressStart = millis();
    lcd.setCursor(0, 1);
    lcd.print("Hold to Calib... ");
  }

  if (buttonState == HIGH && isPressed) {
    unsigned long pressDuration = millis() - pressStart;
    if (pressDuration >= 1000) {  // 1초 이상 눌렀을 때
      maxDistance = currentDistance;
      Serial.print("Calibrated maxDistance: ");
      Serial.println(maxDistance);

      lcd.setCursor(0, 1);
      lcd.print("Cal OK -> ");
      lcd.print(currentDistance, 1);
      lcd.print("cm    ");

      setLEDColor(0, 0, 255);
      tone(BUZZER_PIN, 1500, 100);
      delay(300);
      handleDistanceFeedback(currentDistance);
    } else {
      // 1초 미만이면 다시 maxDistance 표시
      lcd.setCursor(0, 1);
      lcd.print("Max: ");
      lcd.print(maxDistance, 1);
      lcd.print(" cm   ");
    }
    isPressed = false;
  }
}

void setLEDColor(int r, int g, int b) {
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
}
