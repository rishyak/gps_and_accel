#include <Adafruit_GPS.h>
#include <Arduino.h>

namespace GPS {

Adafruit_GPS GPS(&Wire);

/**
 * @brief initialises the GPS
 *
 */
void initialise() {
  GPS.begin(0x10);

  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);

  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);

  GPS.sendCommand(PGCMD_ANTENNA);
}

/**
 * @brief prints GPS prettily
 *
 */
void pretty_print() {
  Serial.print("Lat: ");
  Serial.print(GPS.latitude, 4);
  Serial.println(GPS.lat);

  Serial.print("Lon: ");
  Serial.print(GPS.longitude, 4);
  Serial.println(GPS.lon);

  Serial.print("Alt: ");
  Serial.print(GPS.altitude);
  Serial.println("m\n\n");
}

} // namespace GPS
