const int buttonPin = 2; // interrupt pin
const int ledPin    = 6; // LED

volatile bool running = true;      

unsigned long previousMillis = 0;
const long interval = 500;

volatile unsigned long lastButtonTime = 0; // debounce

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  // Interrupt koppelen aan knop
  attachInterrupt(digitalPinToInterrupt(buttonPin), stopLed, FALLING);
}

void loop() {
  if (running) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      digitalWrite(ledPin, !digitalRead(ledPin)); // toggle LED
    }
  } else {
    digitalWrite(ledPin, LOW); // LED uit
  }
}

// Interrupt Service Routine (ISR)
void stopLed() {
  unsigned long currentTime = millis();
  if (currentTime - lastButtonTime > 50) { // debounce
    running = false;
    lastButtonTime = currentTime;
  }
}
