#include "WiFi.h"
#include <HTTPClient.h>
#include <Arduino_JSON.h>

#define max_n_Value 4

String token = "";
String id = "";
String ServerPath = "https://api.kie.one/api/Members/"+id+"/?access_token="+ token;
const char* ssid = "";
const char* password = "";

void setup() {
  Serial.begin(115200);
  //WiFi
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
  

  //HTTP GET
  HTTPClient http;
  http.begin(ServerPath); //Startet Verbindung zu Server
  int httpResponseCode = http.GET();
  
  String body = "{empty}"; 

  // Responsecode checken
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    body = http.getString();
  }
  else {
    Serial.print("Error");
  }
  http.end(); // Free resources
  
  //Konvertieren in JSON Objekt
   JSONVar json = JSON.parse(body);

  /*
  // JSON.typeof(jsonVar) can be used to get the type of the var
  if (JSON.typeof(json) == "undefined") {
    Serial.println("Parsing input failed! Retry..");
    JSONVar json = JSON.parse(body);
  }
  */
  Serial.print("JSON object = ");
  Serial.println(json);
    
  // myObject.keys() can be used to get an array of all the keys in the object
  JSONVar keys = json.keys();

  //Ausgabe
  for (int i = 0; i < keys.length(); i++) {
    JSONVar value = json[keys[i]];
    Serial.print(keys[i]);
    Serial.print(" = ");
    Serial.println(value);
  }  
}

void loop() {
 
}
