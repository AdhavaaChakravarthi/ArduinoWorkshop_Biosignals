// BLOCK 02 — EMG Reader
// Reads EMG muscle signal, applies moving average smoothing,
// and detects muscle activation via threshold.
// WORKS WITH: MyoWare Muscle Sensor / generic EMG
// WIRING: Sensor SIG -> A0 | VCC -> 5V | GND

const int SENSOR_PIN   = A0;
const int WINDOW_SIZE  = 10;
const int THRESHOLD    = 600;
const int SAMPLE_DELAY = 5;

int  readings[10];
int  readIndex = 0;
long total     = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < WINDOW_SIZE; i++) readings[i] = 0;
  Serial.println("# Block 02 — EMG Reader");
  Serial.println("# Raw,Smoothed,Activated");
}

void loop() {
  int raw = analogRead(SENSOR_PIN);

  total -= readings[readIndex];
  readings[readIndex] = raw;
  total += readings[readIndex];
  readIndex = (readIndex + 1) % WINDOW_SIZE;
  int smoothed = total / WINDOW_SIZE;

  bool activated = (smoothed > THRESHOLD);

  Serial.print(raw);
  Serial.print(",");
  Serial.print(smoothed);
  Serial.print(",");
  Serial.println(activated ? 1023 : 0);

  delay(SAMPLE_DELAY);
}