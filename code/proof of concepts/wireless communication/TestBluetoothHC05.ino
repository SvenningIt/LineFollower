int LED13 = 13;
int pinF = 6;
int pinL = 8;

void setup() {
  pinMode(LED13, OUTPUT); // interne LED
  pinMode(pinF, OUTPUT);
  pinMode(pinL, OUTPUT);

  Serial.begin(9600);     // USB → Serial Monitor op PC
  Serial1.begin(9600);    // HC-05 → hardware Serial1

  Serial.println("'F' or 'L'");
}

void loop() {
  // Data van Bluetooth → Arduino → Serial Monitor
  if (Serial1.available()) {
    char cmd = Serial1.read();
    Serial.print("Received: ");
    Serial.println(cmd);

    digitalWrite(LED13, HIGH); // LED aan voor feedback
    delay(50);
    digitalWrite(LED13, LOW);

    // Controleer commando
    if (cmd == 'F') {
      digitalWrite(pinF, HIGH);
      digitalWrite(pinL, LOW);
    } 
    else if (cmd == 'L') {
      digitalWrite(pinF, LOW);
      digitalWrite(pinL, HIGH);
    } 
    else {
      digitalWrite(pinF, LOW);
      digitalWrite(pinL, LOW);
    }
  }

  // Data van Serial Monitor → Bluetooth app
  if (Serial.available()) {
    char sent = Serial.read();
    Serial1.write(sent);
  }
}
