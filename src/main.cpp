#include "accelerometer.cpp"
#include "gps.cpp"

void setup() {
  Serial.begin(115200);

  GPS::initialise();
  Accelerometer::initialise();

  delay(500);
}

void loop() {
  GPS::pretty_serial_print();
  Accelerometer::pretty_serial_print();

  delay(5000);
}
