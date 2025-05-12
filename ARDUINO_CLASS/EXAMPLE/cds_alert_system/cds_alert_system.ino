const int cdsPin = A0;
const int ledPin = 7;
const int buzzerPin = 5;

const int threshold = 400;
const unsigned long alertDuration = 3000;

bool alertActive = false;
unsigned long alertStartTime = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int cdsValue = analogRead(cdsPin);
  Serial.print("CDS = ");
  Serial.println(cdsValue);

  if (cdsValue > threshold && !alertActive) {
    alertActive = true;
    alertStartTime = millis();
  }

  if (alertActive) {
    unsigned long currentTime = millis();

    if ((currentTime / 100) % 2 == 0) {
      digitalWrite(ledPin, HIGH);
      tone(buzzerPin, 1000);
    } else {
      digitalWrite(ledPin, LOW);
      noTone(buzzerPin);
    }

    if (currentTime - alertStartTime >= alertDuration) {
      alertActive = false;
      digitalWrite(ledPin, LOW);
      noTone(buzzerPin);
    }
  }
}
