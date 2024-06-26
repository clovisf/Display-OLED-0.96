#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  // put your setup code here, to run once:
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  display.clearDisplay();
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);

}

void loop() {
  // put your main code here, to run repeatedly:
  

  for(uint8_t i=0; i < 128; i++){
    for(uint8_t j=0; j < 32; j++){
    display.drawPixel(i, j, WHITE);
    display.display();
    }
  }
  

  //delay(10);
  display.clearDisplay();

}
