// ═══════════════════════════════════════════════════
// 🧱 BLOCK 03 — ECG Reader (AD8232)
// ═══════════════════════════════════════════════════
// WHAT IT DOES: Reads ECG signal from AD8232 module.
//               Detects leads-off and streams PQRST.
// WIRING:
//   AD8232 OUTPUT → A0
//   AD8232 LO+    → Pin 10
//   AD8232 LO-    → Pin 11
//   AD8232 VCC    → 3.3V  ⚠️ NOT 5V!
//   AD8232 GND    → GND
// ═══════════════════════════════════════════════════

const int ECG_PIN      = A0;
const int LEADS_OFF_P  = 10;
const int LEADS_OFF_N  = 11;
const int SAMPLE_DELAY = 4;   // 4ms = 250 Hz

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
    Serial.println(0);  // Flat line when leads disconnected
  } else {
    Serial.println(analogRead(ECG_PIN));
  }

  delay(SAMPLE_DELAY);
}