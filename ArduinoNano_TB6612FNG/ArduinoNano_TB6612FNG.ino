// Arduino Nano
/****************************
 * | IN1 | IN2 | output     |
 * |HIGH |HIGH |short break |
 * |LOW  |HIGH |turn left   |(go back)
 * |HIGH |LOW  |turn right  |(go straight)
 * |LOW  |LOW  |stop        |
*****************************/
const int AIN1 = 4;     // 1つ目のDCモーターの制御
const int AIN2 = 2;     // 1つ目のDCモーターの制御
const int BIN1 = 7;     // 2つ目のDCモーターの制御
const int BIN2 = 8;     // 2つ目のDCモーターの制御
const int PWMA = 3;     // 1つ目のDCモーターの回転速度
const int PWMB = 9;    // 2つ目のDCモーターの回転速度
const int CIN1 = 15;     // 1つ目のDCモーターの制御
const int CIN2 = 14;     // 1つ目のDCモーターの制御
const int DIN1 = 16;     // 2つ目のDCモーターの制御
const int DIN2 = 17;     // 2つ目のDCモーターの制御
const int PWMC = 11;     // 1つ目のDCモーターの回転速度
const int PWMD = 10;    // 2つ目のDCモーターの回転速度

void setup() {
    Serial.begin(9600);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
    pinMode(PWMA, OUTPUT);
    pinMode(PWMB, OUTPUT);
    pinMode(CIN1, OUTPUT);
    pinMode(CIN2, OUTPUT);
    pinMode(DIN1, OUTPUT);
    pinMode(DIN2, OUTPUT);
    pinMode(PWMC, OUTPUT);
    pinMode(PWMD, OUTPUT);
    Serial.println("connected");
}
void loop() {
  char cmd;

  if(Serial.available()){
    cmd = Serial.read();
    Move(cmd);
  }
  
  rpm(100);

}

int rpm(int x) {
  analogWrite(PWMA, x);
  analogWrite(PWMB, x);
  analogWrite(PWMC, x);
  analogWrite(PWMD, x);
}

void Move(int i) {
  //適宜調整してください。
  switch(i) {
    case ' ': //停止
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, LOW);
      digitalWrite(BIN1, LOW);
      digitalWrite(BIN2, LOW);
      digitalWrite(CIN1, LOW);
      digitalWrite(CIN2, LOW);
      digitalWrite(DIN1, LOW);
      digitalWrite(DIN2, LOW);
      delay(1000);
      break;
    case 't': // 右回転
      digitalWrite(AIN1, HIGH);
      digitalWrite(AIN2, LOW);
      digitalWrite(BIN1, HIGH);
      digitalWrite(BIN2, LOW);
      digitalWrite(CIN1, HIGH);
      digitalWrite(CIN2, LOW);
      digitalWrite(DIN1, HIGH);
      digitalWrite(DIN2, LOW);
      delay(1000);
      break;
    case 'r': // 左回転
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, HIGH);
      digitalWrite(BIN1, LOW);
      digitalWrite(BIN2, HIGH);
      digitalWrite(CIN1, LOW);
      digitalWrite(CIN2, HIGH);
      digitalWrite(DIN1, LOW);
      digitalWrite(DIN2, HIGH);
      delay(1000);
      break;
    case 'w': // 前進
      digitalWrite(AIN1, HIGH);
      digitalWrite(AIN2, LOW);
      digitalWrite(BIN1, LOW);
      digitalWrite(BIN2, HIGH);
      digitalWrite(CIN1, LOW);
      digitalWrite(CIN2, HIGH);
      digitalWrite(DIN1, HIGH);
      digitalWrite(DIN2, LOW);
      delay(1000);
      break;
    case 's': // 後進
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, HIGH);
      digitalWrite(BIN1, HIGH);
      digitalWrite(BIN2, LOW);
      digitalWrite(CIN1, HIGH);
      digitalWrite(CIN2, LOW);
      digitalWrite(DIN1, LOW);
      digitalWrite(DIN2, HIGH);
      delay(1000);
      break;
    case 'q': //左上
      digitalWrite(AIN1, HIGH);
      digitalWrite(AIN2, LOW);
      digitalWrite(BIN1, LOW);
      digitalWrite(BIN2, LOW);
      digitalWrite(CIN1, LOW);
      digitalWrite(CIN2, HIGH);
      digitalWrite(DIN1, LOW);
      digitalWrite(DIN2, LOW);
      break;
    case 'c': //右下
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, HIGH);
      digitalWrite(BIN1, LOW);
      digitalWrite(BIN2, LOW);
      digitalWrite(CIN1, HIGH);
      digitalWrite(CIN2, LOW);
      digitalWrite(DIN1, LOW);
      digitalWrite(DIN2, LOW);
      break;
    case 'z': //左下
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, LOW);
      digitalWrite(BIN1, HIGH);
      digitalWrite(BIN2, LOW);
      digitalWrite(CIN1, LOW);
      digitalWrite(CIN2, LOW);
      digitalWrite(DIN1, LOW);
      digitalWrite(DIN2, HIGH);
      break;
    case 'e': //右上
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, LOW);
      digitalWrite(BIN1, LOW);
      digitalWrite(BIN2, HIGH);
      digitalWrite(CIN1, LOW);
      digitalWrite(CIN2, LOW);
      digitalWrite(DIN1, HIGH);
      digitalWrite(DIN2, LOW);
      break;
    case 'd': //右
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, HIGH);
      digitalWrite(BIN1, LOW);
      digitalWrite(BIN2, HIGH);
      digitalWrite(CIN1, HIGH);
      digitalWrite(CIN2, LOW);
      digitalWrite(DIN1, HIGH);
      digitalWrite(DIN2, LOW);
      break;
    case 'a': //左
      digitalWrite(AIN1, HIGH);
      digitalWrite(AIN2, LOW);
      digitalWrite(BIN1, HIGH);
      digitalWrite(BIN2, LOW);
      digitalWrite(CIN1, LOW);
      digitalWrite(CIN2, HIGH);
      digitalWrite(DIN1, LOW);
      digitalWrite(DIN2, HIGH);
      break;
  }
}
