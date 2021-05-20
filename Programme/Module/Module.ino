#include "input.h"

void setup() {
  wlan();
  initSensor();
}

void loop() {
  Serial.print("Entfernung: ");
  Serial.println(entfernung());
  Serial.println();
  delay(1000);
}
