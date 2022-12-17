#include <Wire.h>
#include <I2C_RTC.h> // https://github.com/cvmanjoo/RTC

#define UVrelay 4
#define IKrelay 5 // Normally closed relay, invert HIGH and LOW

// Set date, time, week
#define date 17,12,22
#define time 13,19,00
#define week 7 // 1 - Sunday, 2 - Monday, etc.
// Set uv and ik lamps working period
#define uvOnHour 8
#define uvOffHour 14
#define ikOnHour 8
#define ikOffHour 23

bool isSetTime = false; // True if want set up time
static PCF8563 RTC;

void taskSetTime() {
  RTC.setDate(date);
  RTC.setTime(time);
  RTC.setWeek(week);
}

void taskSetRelay() {
  if (RTC.getHours() >= uvOnHour-1 && RTC.getHours() <= uvOffHour-1) {
    digitalWrite(UVrelay, LOW);
  }
  else {
    digitalWrite(UVrelay, HIGH);
  }

  if (RTC.getHours() >= ikOnHour-1 && RTC.getHours() <= ikOffHour-1) { // Normally closed relay
    digitalWrite(IKrelay, HIGH);
  }
  else {
    digitalWrite(IKrelay, LOW);
  }
}

void setup() {
  RTC.begin();

  pinMode(UVrelay, OUTPUT);
  pinMode(IKrelay, OUTPUT);

  if (isSetTime) {
    taskSetTime();
  }
}

void loop() {
  taskSetRelay();
}
