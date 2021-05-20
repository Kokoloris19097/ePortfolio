#include "input.h"

void setup() {
  connect();

}

void loop() {
  Serial.print("Entfernung: ");
  Serial.println(entfernung());
  Serial.println();
  delay(1000);
}
