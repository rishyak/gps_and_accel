#include "GPS.cpp"
#include "accelerometer.cpp"

void setup() {
  Serial.begin(115200);

  GPS::initialise();
  Accelerometer::initialise();

  delay(500);
}

void loop() {
  GPS::pretty_print();
  Accelerometer::pretty_print();

  delay(5000);
}
