#define trigger 34
#define echo 35

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);
  delay(800);
}

void loop() {
  long entfernung = 0;
  long zeit = 0;
  digitalWrite(trigger, LOW);
  delayMicroseconds(3);
  noInterrupts();
  digitalWrite(trigger, HIGH); //Trigger Impuls 10 us
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  zeit = pulseIn(echo, HIGH);
  interrupts();
  zeit = zeit/2; // Hin und Rückweg
   entfernung = zeit / 29.1; //Teit umrechnen in cm
  Serial.print("Entfernung: ");
  Serial.println(entfernung);
  delay(1000);
}
