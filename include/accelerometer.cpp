#include <Adafruit_ADXL345_U.h>
#include <Arduino.h>

namespace Accelerometer {

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

/**
 * @brief initialise accelerometer
 *
 * @note uses serial
 * @warning blocking operation
 *
 */
void initialise() {
  if (!accel.begin()) {
    Serial.println("Ooops, no ADXL345 detected");
    while (1)
      ;
  }
  accel.setRange(ADXL345_RANGE_16_G);
}

/**
 * @brief pring accelerometer prettily
 *
 */
void pretty_serial_print() {
  sensors_event_t event;
  accel.getEvent(&event);

  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("X: ");
  Serial.print(event.acceleration.x);
  Serial.print("m/s^2\n");

  Serial.print("Y: ");
  Serial.print(event.acceleration.y);
  Serial.print("m/s^2\n");

  Serial.print("Z: ");
  Serial.print(event.acceleration.z);
  Serial.print("m/s^2\n\n");
}

} // namespace Accelerometer
