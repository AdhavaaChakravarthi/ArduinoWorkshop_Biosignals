// ═══════════════════════════════════════════════════
// 🧱 BLOCK 04 — EEG Serial Streamer
// ═══════════════════════════════════════════════════
// WHAT IT DOES: High-speed EEG streaming over Serial
//               in CSV format for Python / Processing.
// WIRING: EEG OUT → A0 | VCC → 3.3V | GND → GND
// OUTPUT: timestamp_ms, raw_value, voltage
// ═══════════════════════════════════════════════════

const int   EEG_PIN   = A0;
const int   ADC_MAX   = 1023;
const float VREF      = 5.0;
const int   SAMPLE_MS = 4;    // 4ms = 250 Hz

unsigned long startTime = 0;

void setup() {
  Serial.begin(115200);   // High baud for fast streaming
  startTime = millis();
  Serial.println("timestamp_ms,raw,voltage");
}

void loop() {
  unsigned long t   = millis() - startTime;
  int           raw = analogRead(EEG_PIN);
  float         v   = (raw / (float)ADC_MAX) * VREF;

  Serial.print(t);
  Serial.print(",");
  Serial.print(raw);
  Serial.print(",");
  Serial.println(v, 4);

  delay(SAMPLE_MS);
}