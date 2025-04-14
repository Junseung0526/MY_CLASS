int potPin = A0;
int ledPin = 9;
int buzzerPin = 6;
int potValue = 0;
int ledBrightness = 0;
int buzzerFreq = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(potPin);
  ledBrightness = map(potValue, 0, 1023, 0, 255);
  buzzerFreq = map(potValue, 0, 1023, 500, 2000);

  analogWrite(ledPin, ledBrightness);
  tone(buzzerPin, buzzerFreq);


  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print("\tLED Brightness: ");
  Serial.print(ledBrightness);
  Serial.print("\tBuzzer Frequency: ");
  Serial.println(buzzerFreq);

  delay(100);
}