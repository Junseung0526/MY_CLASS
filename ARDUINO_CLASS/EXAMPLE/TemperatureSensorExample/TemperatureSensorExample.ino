#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int soilSensorPin = A1;

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  int soilValue = analogRead(soilSensorPin); 

  lcd.clear();       
  lcd.setCursor(0, 0);
  lcd.print("Soil: ");
  lcd.print(soilValue);

  lcd.setCursor(0, 1);
  if (soilValue > 450) {
    lcd.print("Water, Please");
  } else {
    lcd.print("Enough Water");
  }

  delay(2000);
}
