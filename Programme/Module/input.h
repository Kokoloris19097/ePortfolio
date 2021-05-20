#include "WiFi.h"

#define ultraschalltrigger 34 // Arduino Pin an HC-SR04 Trig
#define ultraschallecho 35    // Arduino Pin an HC-SR04 Echo
  
const char* ssid = "";
const char* password = "";

void wlan() {
  //Initalisieren des Seriellen Monitors
  Serial.begin(115200);
  delay(800);
  //Starten des WiFi Client
  WiFi.begin(ssid, password);
  delay(500);
  Serial.println();
  int counter = 0;
  Serial.print("Connecting to WiFi");
  while ((WiFi.status() != WL_CONNECTED)) {
    // Auf verbindung warten
    counter++;
    delay(1000);
    if(counter % 20 == 0){
      Serial.println(".");//Zeilenumbruch alle 20 Zeichen
    }else if(counter % 50 == 0){
      WiFi.begin(ssid, password); //Retry alle 50 Versuche
      Serial.println("Retry");
    }else
    {
      Serial.print(".");
    }    
  }
  Serial.println();
  Serial.println("Connected");  
}

void initSensor() {
  pinMode(ultraschalltrigger, OUTPUT);
  pinMode(ultraschallecho, INPUT);
}
int entfernung(){
  long entfernung=0;
  long zeit=0;
  digitalWrite(ultraschalltrigger, LOW);
  delayMicroseconds(3);
  noInterrupts();
  digitalWrite(ultraschalltrigger, HIGH); //Trigger Impuls 10 us
  delayMicroseconds(10);
  digitalWrite(ultraschalltrigger, LOW);
  zeit = pulseIn(ultraschallecho, HIGH); // Echo-Zeit messen
  interrupts();
  zeit = (zeit/2); // Zeit halbieren
  entfernung = zeit / 29.1; // Zeit in Zentimeter umrechnen
  return(entfernung);
}
