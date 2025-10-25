const int buttonPin = 2; // knop
const int ledPin    = 6; // LED

bool running = true;      
unsigned long previousMillis = 0;
const long interval = 500;

unsigned long lastButtonTime = 0; // voor debounce

/*Led knippert totdat de knop een interrupt aanstuurt
hierdoor zal het programma even pauzeren voordat het de loop verder uitvoert*/

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Knipperlicht
  if (running) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      digitalWrite(ledPin, !digitalRead(ledPin)); // toggle LED
    }
  } else {
    digitalWrite(ledPin, LOW); // LED uit
  }

  // Knop check met debounce
  if (digitalRead(buttonPin) == LOW) {
    unsigned long currentTime = millis();
    if (currentTime - lastButtonTime > 50) { // 50 ms debounce
      running = false; // LED stoppen
    }
    lastButtonTime = currentTime;
  }
}
