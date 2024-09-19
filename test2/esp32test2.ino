#include "HX711.h"

// Define pins connected to HX711
const int LOADCELL_DOUT_PIN = 19;  // DT pin
const int LOADCELL_SCK_PIN = 18;   // SCK pin

HX711 scale;

void setup() {
  Serial.begin(115200);
  
  // Initialize the scale
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  // Set the calibration factor (you'll need to find this)
  scale.set_scale(2280.f);  // This value is just an example, you'll need to calibrate

  // Reset the scale to zero
  scale.tare(); 
  Serial.println("Scale is ready");
}

void loop() {
  if (scale.is_ready()) {
    // Take an average of 10 readings
    float weight = scale.get_units(10);  
    
    Serial.print("Weight: ");
    Serial.println(weight, 2);  // Print with 2 decimal places
  } else {
    Serial.println("HX711 not found.");
  }

  delay(100); // Wait for 1 second
}
