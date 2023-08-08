#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

namespace Screen {

Adafruit_ST7789 screen = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void initialise();

void clear();

/**
 * @brief initialise screen
 *
 * @param text_size  the text size
 */
void initialise(size_t text_size) {
  pinMode(TFT_BACKLITE, OUTPUT);
  digitalWrite(TFT_BACKLITE, HIGH);
  pinMode(TFT_I2C_POWER, OUTPUT);
  digitalWrite(TFT_I2C_POWER, HIGH);
  delay(10);

  screen.init(135, 240);
  screen.setRotation(3);
  screen::clear();
  screen.setTextSize(text_size);
}

/**
 * @brief clear screen
 *
 * @note sets cursor to (0, 10) each time
 */
void clear() {
  screen.fillScreen(ST77XX_BLACK);
  screen.setCursor(0, 10);
}

} // namespace screen
