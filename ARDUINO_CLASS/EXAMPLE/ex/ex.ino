// 핀 번호 정의 (제공된 설정 적용)
const int ldrPin = A0;                        // 조도센서(A0)
const int segPins[7] = {3, 4, 5, 6, 7, 8, 9}; // 7-세그먼트 a~g : D3~D9
const int redPin = 10;                        // RGB LED Red
const int greenPin = 11;                      // RGB LED Green  
const int bluePin = 12;                       // RGB LED Blue
const int buzzerPin = 1;                      // 피에조 부저

// 설정값
const int lightThreshold = 300;               // 조도센서 임계값 (어두워짐 감지)
const int countdownStart = 9;                 // 카운트다운 시작값 (9초)
const int buzzerDuration = 2000;              // 부저 울리는 시간 (2초)

// 7-세그먼트 숫자 패턴 (공통음극, a~g 순서)
const byte segNumbers[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1  
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

// 상태 정의
enum TimerState { STANDBY, COUNTING, FINISHED };
TimerState currentState = STANDBY;

// 변수
int countdown = countdownStart;
unsigned long previousMillis = 0;
unsigned long buzzerStartTime = 0;
int baselineLight = 0;

void setup() {
  Serial.begin(9600);
  
  // 핀 모드 설정
  pinMode(ldrPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  for (int i = 0; i < 7; i++) {
    pinMode(segPins[i], OUTPUT);
  }
  
  // 초기 조도값 측정 (기준값)
  delay(1000);
  baselineLight = analogRead(ldrPin);
  
  // 초기 상태 설정
  setLEDColor(0, 255, 0);    // 초록색 (대기)
  displayNumber(countdownStart);
  
  Serial.println("빛 감지 카운트다운 타이머 시작");
  Serial.print("기준 조도값: ");
  Serial.println(baselineLight);
}

void loop() {
  int currentLight = analogRead(ldrPin);
  
  switch (currentState) {
    case STANDBY:
      handleStandbyState(currentLight);
      break;
      
    case COUNTING:
      handleCountingState(currentLight);
      break;
      
    case FINISHED:
      handleFinishedState(currentLight);
      break;
  }
  
  delay(50); // 안정성을 위한 짧은 딜레이
}

void handleStandbyState(int lightValue) {
  setLEDColor(0, 255, 0);           // 초록색
  displayNumber(countdownStart);
  
  // 급격한 조도 변화 감지 (손으로 가리기 등)
  if (lightValue < lightThreshold || lightValue < baselineLight - 200) {
    Serial.println("어두워짐 감지! 카운트다운 시작");
    currentState = COUNTING;
    countdown = countdownStart;
    previousMillis = millis();
    setLEDColor(255, 255, 0);       // 노란색
  }
}

void handleCountingState(int lightValue) {
  setLEDColor(255, 255, 0);         // 노란색
  
  // 1초마다 카운트다운
  if (millis() - previousMillis >= 1000) {
    previousMillis = millis();
    countdown--;
    displayNumber(countdown);
    
    Serial.print("카운트다운: ");
    Serial.println(countdown);
    
    if (countdown <= 0) {
      Serial.println("카운트다운 종료!");
      currentState = FINISHED;
      setLEDColor(255, 0, 0);       // 빨간색
      tone(buzzerPin, 5000, buzzerDuration);
      buzzerStartTime = millis();
    }
  }
}

void handleFinishedState(int lightValue) {
  setLEDColor(255, 0, 0);           // 빨간색
  displayNumber(0);
  
  // 부저가 끝나고 밝아지면 초기화
  if (millis() - buzzerStartTime > buzzerDuration) {
    if (lightValue > lightThreshold && lightValue > baselineLight - 100) {
      Serial.println("시스템 초기화");
      currentState = STANDBY;
      countdown = countdownStart;
      // 새로운 기준값 설정
      baselineLight = lightValue;
    }
  }
}

// 7-세그먼트에 숫자 표시
void displayNumber(int num) {
  if (num < 0) num = 0;
  if (num > 9) num = 9;
  
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], segNumbers[num][i]);
  }
}

// RGB LED 색상 설정 (0-255 범위)
void setLEDColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
