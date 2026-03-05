// ═══════════════════════════════════════════════════
// 🧱 BLOCK 05 — Software Signal Filter
// ═══════════════════════════════════════════════════
// WHAT IT DOES: Demonstrates software filtering:
//   1. Low-Pass Filter  — removes high-freq noise
//   2. Notch Filter     — removes 50 Hz power hum
// SERIAL PLOTTER shows: Raw | LowPass | Notch
// ═══════════════════════════════════════════════════

const int   SENSOR_PIN = A0;
const int   SAMPLE_MS  = 4;      // 4ms = 250 Hz
const float ALPHA      = 0.2;    // 0 = heavy smooth, 1 = no smooth

float lpfOutput = 0.0;

// IIR Notch filter coefficients (~50 Hz @ 250 Hz sample rate)
const float B0 =  0.9522, B1 = -1.1736, B2 = 0.9522;
const float A1 = -1.1736, A2 =  0.9044;

float notchOut = 0, notchIn_1 = 0, notchIn_2 = 0;
float notchOut_1 = 0, notchOut_2 = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("# Block 05 — Signal Filter Demo");
  Serial.println("# Raw,LowPass,Notch");
}

void loop() {
  int raw = analogRead(SENSOR_PIN);

  // Low-Pass Filter (Exponential Moving Average)
  lpfOutput = ALPHA * raw + (1.0 - ALPHA) * lpfOutput;

  // Notch Filter (IIR)
  notchOut   = B0 * raw   + B1 * notchIn_1  + B2 * notchIn_2
                           - A1 * notchOut_1 - A2 * notchOut_2;
  notchIn_2  = notchIn_1;   notchIn_1  = raw;
  notchOut_2 = notchOut_1;  notchOut_1 = notchOut;

  Serial.print(raw);          Serial.print(",");
  Serial.print((int)lpfOutput); Serial.print(",");
  Serial.println((int)notchOut);

  delay(SAMPLE_MS);
}