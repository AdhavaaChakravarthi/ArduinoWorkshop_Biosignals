// BLOCK 06 — Full Biosignal Pipeline
// Complete end-to-end pipeline:
//   READ -> LOW-PASS FILTER -> RMS -> THRESHOLD -> LED
// WIRING:
//   Sensor SIG -> A0 | VCC -> 5V | GND -> GND
//   LED+ -> Pin 13 (built-in LED)
// SERIAL PLOTTER: Raw | Filtered | RMS | Threshold

const int   SENSOR_PIN     = A0;
const int   LED_PIN        = 13;
const int   ADC_MAX        = 1023;
const float LPF_ALPHA      = 0.25;
const int   RMS_WINDOW     = 50;
const int   ACTIVATION_THR = 300;
const int   SAMPLE_MS      = 4;

float lpfValue   = 0.0;
long  sumSquares = 0;
int   rmsBuffer[50];
int   rmsIndex   = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  for (int i = 0; i < RMS_WINDOW; i++) rmsBuffer[i] = 0;
  Serial.println("# Block 06 — Full Pipeline");
  Serial.println("# Raw,Filtered,RMS,Threshold");
}

void loop() {
  int raw = analogRead(SENSOR_PIN);

  lpfValue = LPF_ALPHA * raw + (1.0 - LPF_ALPHA) * lpfValue;
  int filtered = (int)lpfValue;

  sumSquares -= (long)rmsBuffer[rmsIndex] * rmsBuffer[rmsIndex];
  rmsBuffer[rmsIndex] = filtered;
  sumSquares += (long)filtered * filtered;
  rmsIndex = (rmsIndex + 1) % RMS_WINDOW;
  int rms = (int)sqrt((float)sumSquares / RMS_WINDOW);

  bool activated = (rms > ACTIVATION_THR);
  digitalWrite(LED_PIN, activated ? HIGH : LOW);

  Serial.print(raw);      Serial.print(",");
  Serial.print(filtered); Serial.print(",");
  Serial.print(rms);      Serial.print(",");
  Serial.println(ACTIVATION_THR);

  delay(SAMPLE_MS);
}