
// Timing and space used measured with SpenceKonde's ATTinyCore
// and an ATTiny85 at 8MHz

// Without any other includes, this library uses the standard Wire library.
// See timing below for the Wire-specific include
#include <C:\Users\Usuario\Documents\GitHub\Display-OLED-0.96\teste-display-oled-0.96\tiny4k-oled\Tiny4kOLED.h>

// 4264 bytes program, 101 bytes dynamic memory
// 348ms to fill the screen
//#include <Tiny4kOLED_Wire.h>

// 3920 bytes program, 80 bytes dynamic memory
// 142ms to fill the screen
//#include <Tiny4kOLED_TinyWireM.h>

// 3672 bytes program, 60 bytes dynamic memory
// 56ms to fill the screen
#include <C:\Users\Usuario\Documents\GitHub\Display-OLED-0.96\teste-display-oled-0.96\tiny4k-oled\Tiny4kOLED_tiny-i2c.h>

// 3622 bytes program, 60 bytes dynamic memory
// 45ms to fill the screen
//#include <Tiny4kOLED_bitbang.h>

unsigned long lastTime = 0L;

#ifndef TINY4KOLED_NO_PRINT
//SSD1306PrintDevice oled(&tiny4koled_begin_tinyi2c, &tiny4koled_beginTransmission_tinyi2c, &datacute_write_tinyi2c, &datacute_endTransmission_tinyi2c);
#else
SSD1306Device oled(&tiny4koled_begin_tinyi2c, &tiny4koled_beginTransmission_tinyi2c, &datacute_write_tinyi2c, &datacute_endTransmission_tinyi2c);
#endif

void setup() {
  // Test by writing to the entire memory space of the SSD1306
  oled.begin(128, 64, sizeof(tiny4koled_init_128x64br), tiny4koled_init_128x64br);
  oled.clear();
  oled.setFont(FONT8X16);
  oled.on();
  lastTime = millis();
}

uint8_t b = 0;
void loop() {
  oled.fill(b);
  if (b==255) {
    unsigned long thisTime = millis();
    oled.setCursor(0,0);
    oled.println((thisTime-lastTime)>>8, DEC);
    delay(4000);
    lastTime = millis();
  }
  b++;
}
