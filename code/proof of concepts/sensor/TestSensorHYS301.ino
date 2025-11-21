// HY-S301 IR Sensor Module - 6 sensoren (A0–A5)
// Arduino Leonardo voorbeeld
// Deze code leest 6 IR-sensoren uit en toont de waarden in de Serial Monitor.

const int IR_LED = 9;  // Pin die de IR-LEDs aan/uit zet

void setup() {
  Serial.begin(115200);          // Start communicatie met de computer
  while (!Serial);             // Wacht tot de seriële monitor open is (nodig bij Leonardo)
  pinMode(IR_LED, OUTPUT);     // Zet pin 8 als uitgang voor de IR-LEDs

  Serial.println("HY-S301 IR-sensor klaar!");
}

void loop() {
  digitalWrite(IR_LED, HIGH);  // Zet de IR-LEDs aan

  // Lees de zes sensoren op de analoge pinnen A0 t/m A5
  int sensor0 = analogRead(A0);
  int sensor1 = analogRead(A1);
  int sensor2 = analogRead(A2);
  int sensor3 = analogRead(A3);
  int sensor4 = analogRead(A4);
  int sensor5 = analogRead(A5);

  // Stuur de waarden naar de computer (via Serial Monitor)
  Serial.print("Sensorwaarden: ");
  Serial.print(sensor0); Serial.print(" ");
  Serial.print(sensor1); Serial.print(" ");
  Serial.print(sensor2); Serial.print(" ");
  Serial.print(sensor3); Serial.print(" ");
  Serial.print(sensor4); Serial.print(" ");
  Serial.println(sensor5);  // println zet een nieuwe regel erachter

  delay(200);  // Even wachten voordat we opnieuw meten
}
