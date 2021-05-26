#include "WiFi.h"

const char* ssid = "TrojaNet";
const char* pw = "50023282650157230429";

void setup() {
  Serial.begin(115200);
  delay(800);
  ///Starten WiFi Client
  WiFi.begin(ssid, pw);
  Serial.println();
  Serial.println("Conneting to WiFi");
  
  int counter =0;
  while (WiFi.status() != WL_CONNECTED){
    counter++;
    delay(1000);
    if(counter % 20 == 0){
      Serial.println(".");
    }else if(counter % 50 == 0){
      WiFi.begin(ssid, pw);
      Serial.println("Retry");
    }else{
      Serial.print(".");
    }
  }
  Serial.println("Connected");
}

void loop() {

}
