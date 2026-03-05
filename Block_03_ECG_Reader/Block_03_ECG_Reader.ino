// BLOCK 03 — ECG Reader (AD8232)
// Reads ECG signal, detects leads-off, streams PQRST waveform.
// WIRING:
//   AD8232 OUTPUT -> A0
//   AD8232 LO+    -> Pin 10
//   AD8232 LO-    -> Pin 11
//   AD8232 VCC    -> 3.3V  (NOT 5V!)
//   AD8232 GND    -> GND

const int ECG_PIN      = A0;
const int LEADS_OFF_P  = 10;
const int LEADS_OFF_N  = 11;
const int SAMPLE_DELAY = 4;

void setup() {
  Serial.begin(9600);
  pinMode(LEADS_OFF_P, INPUT);
  pinMode(LEADS_OFF_N, INPUT);
  Serial.println("# Block 03 — ECG Reader (AD8232)");
}

void loop() {
  bool leadsOff = (digitalRead(LEADS_OFF_P) == 1) ||
                  (digitalRead(LEADS_OFF_N) == 1);

  if (leadsOff) {
    Serial.println(0);
  } else {
    Serial.println(analogRead(ECG_PIN));
  }

  delay(SAMPLE_DELAY);
}