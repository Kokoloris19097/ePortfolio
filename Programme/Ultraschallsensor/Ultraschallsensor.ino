//Declarationen

  //Sensoren 
  #define ultraschalltrigger 34 // Arduino Pin an HC-SR04 Trig
  #define ultraschallecho 35    // Arduino Pin an HC-SR04 Echo

void setup() {
  pinMode(ultraschalltrigger, OUTPUT);
  pinMode(ultraschallecho, INPUT);
  Serial.begin(115200);//Test
  delay(800);
}

// Funktionen
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

//Main
void loop() {
  Serial.print("Entfernung: ");
  Serial.println(entfernung());
  Serial.println();
  delay(1000);  
}
  
