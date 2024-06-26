#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

// this is the bitmap, change this variable for your specification.
const unsigned char myBitmap [] PROGMEM = 

{
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x80, 0x7f, 0xbf, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x80, 0x7f, 0xb3, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x9f, 0xff, 0xf3, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x9f, 0xe9, 0xa1, 0x03, 0xc7, 0xa3, 0xdf, 0xf0, 0xe8, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x9f, 0xe1, 0xb1, 0x03, 0x03, 0x81, 0xdf, 0xe0, 0x60, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x80, 0xe7, 0xb3, 0xf3, 0x79, 0xbd, 0xdf, 0xce, 0x67, 0x3f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x80, 0xe7, 0xb3, 0xe7, 0x79, 0xbd, 0xdf, 0xfc, 0x6f, 0x3f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x9f, 0xe7, 0xb3, 0xce, 0x01, 0xbd, 0xdf, 0xe0, 0x6f, 0x3f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x9f, 0xe7, 0xb3, 0x9f, 0x7f, 0xbd, 0xdf, 0xcf, 0x6f, 0x3f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x9f, 0xe7, 0xb3, 0x3f, 0x39, 0xbd, 0xdf, 0xce, 0x67, 0x3f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x9f, 0xe7, 0xb1, 0x01, 0x03, 0xbd, 0xc0, 0x40, 0x60, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x9f, 0xe7, 0xb8, 0x01, 0xc7, 0xbd, 0xc0, 0x73, 0x6c, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xef, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xef, 0xf9, 0xcc, 0xd9, 0xad, 0x9c, 0xfc, 0xe7, 0x5f, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xe0, 0xf6, 0xb5, 0xb6, 0xb5, 0x6b, 0x7a, 0xd6, 0x9f, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xef, 0xe0, 0xbd, 0xee, 0xb5, 0x78, 0xf8, 0xfd, 0xdf, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xef, 0xef, 0xbd, 0xfe, 0xb5, 0x7f, 0x77, 0xfd, 0xdf, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xe0, 0xf0, 0x84, 0xf0, 0xb5, 0x08, 0x78, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xfb, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xbf, 0xfe, 0xfb, 0xff, 0x7f, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xfb, 0xed, 0xaf, 0x78, 0xeb, 0x3d, 0x7d, 0xfe, 0x66, 0xfb, 0x73, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xf4, 0x92, 0x96, 0x92, 0xd2, 0x5a, 0x7a, 0xf5, 0xad, 0x24, 0xad, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xe0, 0xb6, 0xb8, 0x16, 0xba, 0x17, 0x79, 0xd4, 0x68, 0x2d, 0xa3, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xe7, 0xb6, 0xb8, 0xf6, 0xba, 0xf7, 0x7e, 0x4f, 0x29, 0xed, 0xb9, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xf0, 0xb6, 0x86, 0x10, 0xc2, 0x18, 0x78, 0xec, 0x24, 0x2d, 0xa1, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};


void setup() 
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // here the 0x3c is the I2C address, check your i2c address if u have multiple devices.
  display.clearDisplay();
  delay(2000);

}

void loop() 
{
  display.drawBitmap(0, 0, myBitmap, 128, 64, WHITE);
  display.display();
}