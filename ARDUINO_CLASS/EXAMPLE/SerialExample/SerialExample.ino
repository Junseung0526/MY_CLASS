int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("시리얼 통신 시작됨. 숫자 0~9 입력시 LED가 해당 횟수만큼 깜빡입니다.");
}

void loop() {
  if(Serial.available() > 0){
    char inputChar = Serial.read();

    if (inputChar >= '0' && inputChar <= '9') {
      int blinkCount = inputChar - '0';

      Serial.print("LED 깜빡이기 횟수: ");
      Serial.println(blinkCount);

      for (int i = 0; i < blinkCount; i++){
        digitalWrite(ledPin, HIGH);
        delay(300);
        digitalWrite(ledPin, LOW);
        delay(300);
      }
    }else{
      Serial.println("숫자(0~9)만 입력 가능합니다.")
    }
  }
}
