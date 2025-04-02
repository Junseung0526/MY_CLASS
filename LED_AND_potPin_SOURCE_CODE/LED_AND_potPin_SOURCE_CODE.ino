const int potPin = A0;
const int ledPin = 9;
const int buzzerPin = 3;
const int buttonPin = 1;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);

void loop() {

  int potValue = analogRead(potPin);
  int ledBrightness = map(potValue, 0, 1023, 0, 255);

  analogWrite(ledPin, ledBrightness);

  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {

    int buzzerFrequency = map(potValue, 0, 1023, 0, 1000);
    tone(buzzerPin, buzzerFrequency);
    
  } else {
    
    noTone(buzzerPin);
    
  }

  delay(100);
