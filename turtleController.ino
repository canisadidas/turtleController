#include "RTClib.h"

RTC_DS3231 rtc;

#define UVrelay 4
#define IKrelay 5 // Normally closed relay, invert HIGH and LOW

// Set uv and ik lamps working period
#define uvOnHour 7
#define uvOffHour 13
#define ikOnHour 7
#define ikOffHour 21

void setup () {
  Serial.begin(57600);

  pinMode(UVrelay, OUTPUT);
  pinMode(IKrelay, OUTPUT);

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop () {
  DateTime now = rtc.now();

  if (now.hour() >= uvOnHour && now.hour() <= uvOffHour - 1) {
    digitalWrite(UVrelay, LOW);
  }
  else {
    digitalWrite(UVrelay, HIGH);
  }

  if (now.hour() >= ikOnHour && now.hour() <= ikOffHour - 1) { // Normally closed relay
    digitalWrite(IKrelay, HIGH);
  }
  else {
    digitalWrite(IKrelay, LOW);
  }
}
