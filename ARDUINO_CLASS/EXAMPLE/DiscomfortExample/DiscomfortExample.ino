#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define SOIL_PIN A0  
#define RED_PIN 3
#define GREEN_PIN 5
#define BLUE_PIN 6
#define BUZZER_PIN 9
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  lcd.clear();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error    ");
    lcd.setCursor(0, 1);
    lcd.print("Check DHT11     ");
    noTone(BUZZER_PIN);
    return;
  }

  float discomfortIndex = 0.81 * temperature + 0.01 * humidity * (0.99 * temperature - 14.3) + 46.3;

  lcd.setCursor(0, 0);
  lcd.print("TEM:");
  lcd.print(temperature, 1);
  lcd.print(" H:");
  lcd.print(humidity, 1);
  lcd.print("   ");

  lcd.setCursor(0, 1);
  lcd.print("DI:");
  lcd.print(discomfortIndex, 1);
  lcd.print("         ");

  setRGBColor(discomfortIndex);

  delay(3000);
}

void setRGBColor(float di) {
  if (di >= 80) {        
    analogWrite(RED_PIN, 255);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 0);
    tone(BUZZER_PIN, 1000);
  } else if (di >= 75) { 
    analogWrite(RED_PIN, 255);
    analogWrite(GREEN_PIN, 255);
    analogWrite(BLUE_PIN, 0);
    noTone(BUZZER_PIN);
  } else if (di >= 68) { 
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 255);
    analogWrite(BLUE_PIN, 0);
    noTone(BUZZER_PIN);
  } else {               
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 255);
    noTone(BUZZER_PIN);
  }
}
