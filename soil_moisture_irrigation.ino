// Automated Soil Moisture Detection & Irrigation System
// Hardware: Arduino Uno, Capacitive Soil Moisture Sensor, 5V Relay Module, Water Pump

const int SENSOR_PIN = A0;   // Analog pin connected to capacitive moisture sensor
const int RELAY_PIN = 7;     // Digital pin connected to 5V relay IN pin

// Calibration thresholds (adjust based on dry/wet analog readings: 0-1023)
const int DRY_THRESHOLD = 550;  // Above this value = soil is dry
const int WET_THRESHOLD = 350;  // Below this value = soil is sufficiently wet

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Keep pump OFF initially (active-LOW relay)
  Serial.println("Soil Moisture Irrigation System Initialized...");
}

void loop() {
  int moistureValue = analogRead(SENSOR_PIN);
  Serial.print("Soil Moisture Reading: ");
  Serial.println(moistureValue);

  if (moistureValue > DRY_THRESHOLD) {
    Serial.println("Status: Soil Dry -> Turning Pump ON");
    digitalWrite(RELAY_PIN, LOW);  // Activate relay to turn pump ON
  } 
  else if (moistureValue < WET_THRESHOLD) {
    Serial.println("Status: Soil Moist -> Turning Pump OFF");
    digitalWrite(RELAY_PIN, HIGH); // Deactivate relay to turn pump OFF
  }

  delay(2000); // Check moisture every 2 seconds
}
