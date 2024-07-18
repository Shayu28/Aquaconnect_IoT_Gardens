// Include required libraries
#include <Arduino.h>

// Define pin numbers
const int relayPin = 2;  // Relay control pin
const int lm35Pin = A0;  // LM35 temperature sensor pin

// Define variables
int temperatureThreshold = 50; // Temperature threshold in Celsius

void setup() {
  // Initialize relay pin as an output
  pinMode(relayPin, OUTPUT);
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the LM35 temperature sensor
  int sensorValue = analogRead(lm35Pin);
  // Convert the sensor value to temperature in Celsius
  float temperature = (sensorValue / 1024.0) * 5000 / 10;

  // Print temperature to serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Check if temperature is below the threshold
  if (temperature < temperatureThreshold) {
    // Turn on the relay
    digitalWrite(relayPin, HIGH);
    Serial.println("Relay turned on");
  } else {
    // Turn off the relay
    digitalWrite(relayPin, LOW);
    Serial.println("Relay turned off");
  }

  // Delay for stability
  delay(1000);
}
