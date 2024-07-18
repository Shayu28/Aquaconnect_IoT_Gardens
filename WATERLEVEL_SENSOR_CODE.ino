#include <ESP8266WiFi.h>

const int waterLevelPin = A0; // Analog pin connected to water level sensor
const int relayPin = D1;      // Digital pin connected to relay

const int threshold = 500;    // Set the threshold value for water level

void setup() {
  Serial.begin(115200);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Initialize relay to off
}

void loop() {
  int waterLevel = analogRead(waterLevelPin);

  Serial.print("Water Level: ");
  Serial.println(waterLevel);

  if (waterLevel < threshold) {
    digitalWrite(relayPin, HIGH); // Turn on relay
    Serial.println("Motor turned on");
  } else {
    digitalWrite(relayPin, LOW); // Turn off relay
    Serial.println("Motor turned off");
  }

  delay(1000); // Delay for stability
}
