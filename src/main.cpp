#include "accelerometer.cpp"
#include "gps.cpp"
#include "screen.cpp"

#define SECOND *1000

void setup() {
  Serial.begin(115200);

  GPS::initialise();
  Accelerometer::initialise();

  delay(500);
}

void loop() {
  GPS::pretty_serial_print();
  Accelerometer::pretty_serial_print();

  delay(5 SECOND);
}
