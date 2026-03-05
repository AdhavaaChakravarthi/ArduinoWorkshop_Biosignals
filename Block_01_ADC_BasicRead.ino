// ═══════════════════════════════════════════════════
// 🧱 BLOCK 01 — ADC Basic Read
// ═══════════════════════════════════════════════════
// WHAT IT DOES: Reads any analog sensor on pin A0
//               and converts the raw value to voltage.
// BOARD: Arduino Uno / Nano (10-bit ADC)
// WIRING: Sensor OUT → A0 | VCC → 5V | GND → GND
// ═══════════════════════════════════════════════════

const int   SENSOR_PIN  = A0;
const int   ADC_MAX     = 1023;   // 4095 for ESP32
const float VREF        = 5.0;
const int   SAMPLE_RATE = 10;     // 10ms = 100 Hz

void setup() {
  Serial.begin(9600);
  Serial.println("# Block 01 — ADC Basic Read");
  Serial.println("# Raw,Voltage");
}

void loop() {
  int rawValue = analogRead(SENSOR_PIN);
  float voltage = (rawValue / (float)ADC_MAX) * VREF;

  Serial.print(rawValue);
  Serial.print(",");
  Serial.println(voltage);

  delay(SAMPLE_RATE);
}