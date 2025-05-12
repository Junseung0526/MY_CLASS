const int cds = A0;
const int red = 7;
const int green = 5;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  int cdsValue = analogRead(cds);

  Serial.print("cds = ");
  Serial.println(cdsValue);

  if (cdsValue > 300) {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
  } else {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
  }

  delay(200);
}
