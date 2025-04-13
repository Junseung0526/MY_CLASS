void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char a = Serial.read();
    
    if (a == '1') {
      digitalWrite(2, LOW);   // 푸른색 LED 끄기
      digitalWrite(3, LOW);   // 녹색 LED 끄기
      digitalWrite(4, HIGH);  // 붉은색 LED 켜기
      Serial.println("RED LED ON!");
    } else if (a == '2') {
      digitalWrite(2, LOW);   // 푸른색 LED 끄기
      digitalWrite(3, HIGH);  // 녹색 LED 켜기
      digitalWrite(4, LOW);   // 붉은색 LED 끄기
      Serial.println("GREEN LED ON!");
    } else if (a == '3') {
      digitalWrite(2, HIGH);  // 푸른색 LED 켜기
      digitalWrite(3, LOW);   // 녹색 LED 끄기
      digitalWrite(4, LOW);   // 붉은색 LED 끄기
      Serial.println("BLUE LED ON!");
    } else if (a == '4') {
      digitalWrite(2, HIGH);
      delay(500);
      digitalWrite(2, LOW);
      
      digitalWrite(3, HIGH);
      delay(500);
      digitalWrite(3, LOW);
    
      digitalWrite(4, HIGH);
      delay(500);
      digitalWrite(4, LOW);

      Serial.println("ALL LED BLINK SEQUENTIALLY!");      
    }
  }
}