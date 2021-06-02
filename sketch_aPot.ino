/*
Upload : 2021. 05. 26
Update : 2021. 06. 02 
Author : Sukkot
*/

// LCD 라이브러리
#include <LiquidCrystal_I2C.h>
// I2C 통신 라이브러리
#include <Wire.h>
// 시간,날짜 라이브러리
#include <swRTC.h>

// 슬립모드 논리변수
boolean lightMod = true;
// 4번 핀 - 파란색 LED
// 7번 핀 - 빨간색 LED
int ledBlue = 4;
int ledRed = 7;
// 광 포토셀은 0 ~ 1023 까지 표기
// 밝기 값 변수
int lux;

// 시간 텍스트 이모티콘
// Time Emoji
byte Time_A[] = { B00001, B01001, B01001, B10101,
                  B10101, B00001, B00001, B00001 };
byte Time_B[] = { B00010, B11110, B00110, B01011,
                  B10010, B01010, B01000, B01111 };

// 이모티콘 베이스
// Emoji Base
byte Base_A[] = { B01000, B00100, B00010, B00010,
                  B00011, B00010, B00011, B00000 };
byte Base_B[] = { B00010, B00100, B01000, B01000,
                  B11000, B01000, B11000, B00000 };
             
// 이모티콘-LED 활성화
// Sun Emoji
byte Sun_A[] = { B00100, B10010, B01000, B00011,
                 B00100, B01000, B01010, B01010 };    
byte Sun_B[] = { B00100, B01001, B00010, B11000,
                 B00100, B00010, B01010, B01010 };
byte Sun_C[] = { B10101, B10101, B11101, B10101,
                 B10101, B00000, B00000, B00000 };

// 이모티콘-LED 비활성화
// Moon Emoji
byte Moon_A[] = { B00000, B00000, B00000, B00011,
                  B00100, B01000, B01000, B01010 };
byte Moon_B[] = { B00000, B00000, B00000, B11000,
                  B00100, B00010, B00010, B01010 };
byte Moon_C[] = { B11100, B00100, B01000, B10000,
                  B11100, B00000, B00000, B00000 };

// LCD 등록
LiquidCrystal_I2C lcd(0x27, 16, 2);
// RTC 라이브러리 호출
swRTC rtc;



void setup() {
  // rtc 타이머 정지
  rtc.stopRTC();
  // 현재 시간 0시 0분 0초로 변경
  rtc.setTime(0, 0, 0);
  // 현재 날짜를 2021/05/26일로 변경
  // 5.26 = 실습 및 실험 날짜
  rtc.setDate(26, 5, 2021);
  // rtc 타이머 시작
  rtc.startRTC();
  
  // lcd 초기화
  lcd.init();
  // lcd 백라이트 활성화
  lcd.backlight();

  // 커스텀 LCD 문자 등록
  lcd.createChar(0, Base_A);
  lcd.createChar(1, Base_B);
  lcd.createChar(2, Sun_A);
  lcd.createChar(3, Sun_B);  
  lcd.createChar(4, Sun_C);  
  lcd.createChar(5, Moon_A);
  lcd.createChar(6, Moon_B);
  lcd.createChar(7, Moon_C);

  // 'L' 문자 표기
  // L = light 의 약자
  lcd.setCursor(6, 0);
  lcd.print("L");
  
  // 4, 7번 핀을 출력모드로 변환
  // 입력모드로 할 시 LED 어두움
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);
}

void loop() {
  // 3시간 간격으로 해당 구문 실행
  if (rtc.getHours() > 2) {
    // rtc 시간 초기화
    rtc.setTime(0, 0, 0);
    // 스마트 화분 모드 변경
    lightMod = !lightMod;
  }

  
  // 스마트 화분모드 - LED모드
  if (lightMod) {
    // 광 포토셀에서 입력된 저항값을 lux 변수에 저장
    lux = analogRead(A3);

    // 현재 작동시간을 LCD에 표시
    // 현재 밝기를 LCD에 표시
    // State Display
    onDisplayTimer(lux);

    
    // LED 및 이모티콘 동작 코드
    // LED & Emoji
    onLEDEvent(lux);
  }
  else {
    // 스마트 화분모드 - 슬립모드
    // lcd 초기화
    lcd.clear();
    // lcd 백라이트 비활성화
    lcd.noBacklight();

    // 현재 작동시간을 LCD에 표시
    lcd.setCursor(5, 1);  
    lcd.print(formatTime(rtc.getHours()));
    lcd.print(":");
    lcd.print(formatTime(rtc.getMinutes()));
    lcd.print(":");
    lcd.print(formatTime(rtc.getSeconds()));
  }

  // 1초 단위로 루프
  delay(1000);
}


// 스마트 화분 모드 - LED모드 시
// LCD 상에 현재 작동시간과 현재 밝기를 표시
void onDisplayTimer(int lux) {
  lcd.setCursor(5, 1);  
  lcd.print(formatTime(rtc.getHours()));
  lcd.print(":");
  lcd.print(formatTime(rtc.getMinutes()));
  lcd.print(":");
  lcd.print(formatTime(rtc.getSeconds()));
  
  lcd.setCursor(8, 0);
  lcd.print((String)lux + " ");
}

// 현재 밝기에 따른 LED 상태 변경 코드
void onLEDEvent(int lux) {
    if (lux >= 650) {
    // 저항값 650 이상일 시
    // 파란색 LED, 빨간색 LED 점등
    digitalWrite(ledBlue, HIGH);
    digitalWrite(ledRed, HIGH);
    
    // LED 활성화 이모티콘 표시
    onLightOnMod();
    lcd.setCursor(2, 0);
    lcd.write(byte(4));
  }
  else if (lux >= 500) {
    // 저항값 500 이상일 시
    // 파란색 LED 소등, 빨간색 LED 점등
      digitalWrite(ledBlue, LOW);
      digitalWrite(ledRed, HIGH);
      
    // LED 활성화 이모티콘 표시
      onLightOnMod();
      lcd.setCursor(2, 0);
      lcd.print(" ");
  }
  else if (lux > 249) {
    // 저항값 250 이상일 시
    // 파란색 LED 소등, 빨간색 LED 소등
    digitalWrite(ledBlue, LOW);
    digitalWrite(ledRed, LOW);

    // LED 비활성화 이모티콘 표시
    onLightOffMod();
  }
  else {
    // LCD 백라이트 
    lcd.noBacklight();
  }
}


// LED 활성화 이모티콘
// Light Mod Emoji
void onLightOnMod() {
  lcd.home();
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.setCursor(0, 1);
  lcd.write(byte(0));
  lcd.write(byte(1));

  lcd.backlight();
}

// LED 비활성화 이모티콘
// Light Off Mod Emoji
void onLightOffMod() {
  lcd.home();
  lcd.write(byte(5));
  lcd.write(byte(6));
  lcd.write(byte(7));
  lcd.setCursor(0, 1);
  lcd.write(byte(0));
  lcd.write(byte(1));

  lcd.backlight();
}


// 00:00:00 형식으로 변환
String formatTime(int value) {
  if (value < 10)
    return 0 + (String)value;
  else
    return (String)value;
}
