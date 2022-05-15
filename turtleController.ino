#include <Wire.h>
#include <RTC.h>
#define relay 4
bool isSetTime = false; // Установка времени
static PCF8563 RTC;

void taskSetTime() {
  RTC.setDate(15, 05, 22);
  RTC.setTime(14, 45, 00);
  RTC.setWeek(1); // 1 - Воскресенье
}

void taskSetRelay() {
  if (RTC.getHours() >= 6 && RTC.getHours() <= 13) {
    digitalWrite(relay, LOW);
  }
  else if (RTC.getHours() >= 16 && RTC.getHours() <= 22) {
    digitalWrite(relay, LOW);
  }
  else {
    digitalWrite(relay, HIGH);
  }
}

void setup() {
  RTC.begin();
  pinMode(relay, OUTPUT);
  if (isSetTime) {
    taskSetTime();
  }
}

void loop() {
  taskSetRelay();
}
