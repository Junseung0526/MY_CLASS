// --- 핀 설정 ---
const int buttonPin = 2;
const int segmentPins[7] = {3, 4, 5, 6, 7, 8, 9};
const int redPin = 10;
const int greenPin = 11;
const int bluePin = 12;
const int piezoPin = 1;

// --- 상태 정의 ---
enum State { IDLE, COUNT };
State currentState = IDLE;

// --- 세그먼트 숫자 매핑 ---
const byte digits[10][7] = {
{1,1,1,1,1,1,0},  // 0 (원래 0 자리)
{0,1,1,0,0,0,0},  // 1 (원래 1 자리)
{1,1,0,1,1,0,1},  // 2
{1,1,1,1,0,0,1},  // 3
{0,1,1,0,0,1,1},  // 4
{1,0,1,1,0,1,1},  // 5
{1,0,1,1,1,1,1},  // 6
{1,1,1,0,0,0,0},  // 7
{1,1,1,1,1,1,1},  // 8
{1,1,1,1,0,1,1}   // 9
};

int count = 0;
unsigned long nextTick = 0;

void setup() {
  // 핀 설정
  for (int i = 0; i < 7; i++) pinMode(segmentPins[i], OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(piezoPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // 풀업 버튼

  clearSegment();
  rgbOff();
}

void loop() {
  switch (currentState) {
    case IDLE:
      if (digitalRead(buttonPin) == LOW) { // 버튼 누름
        count = 9;
        nextTick = millis() + 1000;
        currentState = COUNT;
        showDigit(count);
      }
      break;

    case COUNT:
      if (millis() >= nextTick) {
        count--;
        if (count >= 0) {
          showDigit(count);
          nextTick = millis() + 1000;

          if (count <= 3) {
            // 3초 이내: RGB 및 부저
            switch (count) {
              case 3: setRGB(0, 255, 0); break; // 초록
              case 2: setRGB(255, 165, 0); break; // 주황
              case 1: setRGB(255, 0, 0); break; // 빨강
              case 0: setRGB(255, 0, 0); break; // 빨강
            }
            tone(piezoPin, 1000, 200); // 짧은 삐 소리
          }
        } else {
          // 0 이후: 종료
          setRGB(255, 0, 0); // 빨간 LED 고정
          noTone(piezoPin);
          delay(1000); // 잠시 유지
          clearSegment();
          rgbOff();
          currentState = IDLE;
        }
      }
      break;
  }
}

void showDigit(int n) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[n][i]);
  }
}

void clearSegment() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], HIGH); // HIGH = 꺼짐
  }
}

void setRGB(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

void rgbOff() {
  setRGB(0, 0, 0);
}   