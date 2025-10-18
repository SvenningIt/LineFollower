// 1) Vooruit: volle snelheid -> langzaam (255 -> 0)
// 2) Kort pauze
// 3) Achteruit: langzaam -> volle snelheid (0 -> 255)
// 4) 1 seconde pauze, dan opnieuw

// Wiring (voorbeeld):
//  - VCC  -> Arduino 5V (logica)
//  - GND  -> Arduino GND (gedeelde massa met motorspanning)
//  - VM   -> Motorspanning naar TB6612 VM
//  - STBY -> Arduino pin 6 (standby, HIGH = ingeschakeld)
// Motor A: AIN1=7, AIN2=8, PWMA=5 (PWM)
// Motor B: BIN1=9, BIN2=10, PWMB=11 (PWM)

const int PIN_AIN1 = 7;
const int PIN_AIN2 = 8;
const int PIN_PWMA = 11;

const int PIN_BIN1 = 9;
const int PIN_BIN2 = 10;
const int PIN_PWMB = 5;

const int PIN_STBY = 6; // gedeelde STBY voor beide kanalen

// Instellingen
const int STEP = 5;        // stapgrootte PWM
const int STEP_DELAY = 25; // ms tussen stappen
const int SHORT_PAUSE_MS = 300; // korte pauze bij 0 tussen richtingen
const int PAUSE_MS = 1000; // pauze tussen herhalingen

void setup() {
  // Zet pinnen als uitgang
  pinMode(PIN_AIN1, OUTPUT);
  pinMode(PIN_AIN2, OUTPUT);
  pinMode(PIN_PWMA, OUTPUT);

  pinMode(PIN_BIN1, OUTPUT);
  pinMode(PIN_BIN2, OUTPUT);
  pinMode(PIN_PWMB, OUTPUT);

  pinMode(PIN_STBY, OUTPUT);

  // Activeer driver
  digitalWrite(PIN_STBY, HIGH);
}

void loop() {
  // --- Vooruit: beide motoren 255 -> 0 ---
  digitalWrite(PIN_AIN1, HIGH);
  digitalWrite(PIN_AIN2, LOW);
  digitalWrite(PIN_BIN1, HIGH);
  digitalWrite(PIN_BIN2, LOW);
  for (int s = 255; s >= 0; s -= STEP) {
    analogWrite(PIN_PWMA, s);
    analogWrite(PIN_PWMB, s);
    delay(STEP_DELAY);
  }

  // korte pauze bij 0
  analogWrite(PIN_PWMA, 0);
  analogWrite(PIN_PWMB, 0);
  delay(SHORT_PAUSE_MS);

  // --- Achteruit: beide motoren 0 -> 255 ---
  digitalWrite(PIN_AIN1, LOW);
  digitalWrite(PIN_AIN2, HIGH);
  digitalWrite(PIN_BIN1, LOW);
  digitalWrite(PIN_BIN2, HIGH);
  for (int s = 0; s <= 255; s += STEP) {
    analogWrite(PIN_PWMA, s);
    analogWrite(PIN_PWMB, s);
    delay(STEP_DELAY);
  }

  // pauze voor we opnieuw beginnen
  analogWrite(PIN_PWMA, 0);
  analogWrite(PIN_PWMB, 0);
  delay(PAUSE_MS);
}
