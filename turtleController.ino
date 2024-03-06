#include "RTClib.h"

RTC_DS3231 rtc;

#define UVrelay 4
#define IKrelay 5 // Normally closed relay, invert HIGH and LOW

// Set uv and ik lamps working period
#define uvOnHour 7
#define uvOffHour 20
#define ikOnHour 7
#define ikOffHour 20

void taskSetRelay() {
  DateTime now = rtc.now();
  if (now.hour() >= uvOnHour && now.hour() <= uvOffHour) {
    digitalWrite(UVrelay, LOW);
  }
  else {
    digitalWrite(UVrelay, HIGH);
  }

  if (now.hour() >= ikOnHour && now.hour() <= ikOffHour) { // Normally closed relay
    digitalWrite(IKrelay, HIGH);
  }
  else {
    digitalWrite(IKrelay, LOW);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(UVrelay, OUTPUT);
  pinMode(IKrelay, OUTPUT);
}

void loop() {
  //taskSetRelay();
  DateTime now = rtc.now();
  Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
}
