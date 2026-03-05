// BLOCK 01 - ADC Basic Read
// WHAT IT DOES: Reads any analog sensor on pin A0 and converts raw value to voltage.
// WORKS WITH:   Any analog biosignal sensor
// BOARD:        Arduino Uno / Nano (10-bit ADC)
//
// WIRING:
//   Sensor OUT -> A0
//   Sensor VCC -> 5V
//   Sensor GND -> GND
//
// HOW TO USE:
//   1. Upload this sketch
//   2. Open Tools -> Serial Plotter
//   3. Watch your signal appear as a live graph!
//
// SETTINGS (change these if needed)
const int   SENSOR_PIN  = A0;     // Analog input pin
const int   ADC_MAX     = 1023;   // 1023 for Arduino Uno/Nano | 4095 for ESP32
const float VREF        = 5.0;    // Reference voltage (5V for Uno, 3.3V for ESP32)
const int   SAMPLE_RATE = 10;     // Delay in ms (10ms = 100 Hz)

void setup() {
  Serial.begin(9600);
  Serial.println("# Block 01 - ADC Basic Read");
  Serial.println("# Raw,Voltage");
}

void loop() {
  // Step 1: Read raw ADC value (0 to ADC_MAX)
  int rawValue = analogRead(SENSOR_PIN);

  // Step 2: Convert to voltage
  float voltage = (rawValue / (float)ADC_MAX) * VREF;

  // Step 3: Print to Serial Monitor / Plotter
  Serial.print(rawValue);
  Serial.print(",");
  Serial.println(voltage);

  // Step 4: Wait before next sample
  delay(SAMPLE_RATE);
}