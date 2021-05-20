#include "WiFi.h"

const char* ssid = "";
const char* password = "";
void setup() {
  Serial.begin(115200);
  delay(800);
  WiFi.begin(ssid, password);
  delay(500);
  Serial.println();
  int counter = 0;
  Serial.print("Connecting to WiFi");
  while ((WiFi.status() != WL_CONNECTED)) {
    counter++;
    delay(1000);
    if(counter % 20 == 0){
      Serial.println(".");
    }else if(counter % 50 == 0){
      WiFi.begin(ssid, password);
      Serial.println("Retry");
    }else
    {
      Serial.print(".");
    }    
  }
  Serial.println();
  Serial.println("Connected");
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
