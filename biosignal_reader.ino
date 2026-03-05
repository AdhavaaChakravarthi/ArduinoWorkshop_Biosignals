// Biosignal Reader — Arduino
// Reads analog signal from sensor on pin A0

void setup() {
  Serial.begin(9600);  // Start serial communication
}

void loop() {
  int rawValue = analogRead(A0);           // Read 0–1023
  float voltage = (rawValue / 1023.0) * 5.0;  // Convert to voltage

  Serial.print("Raw: ");
  Serial.print(rawValue);
  Serial.print("  Voltage: ");
  Serial.println(voltage);

  delay(10);  // Sample every 10ms = 100 Hz sampling rate
}