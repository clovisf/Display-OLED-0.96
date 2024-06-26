/*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

This example is for a 128x64 size display using I2C to communicate
3 pins are required to interface (2 I2C and one reset)

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);

// Conexão do termistor
const int pinTermistor = A0;
 
// Parâmetros do termistor
const double beta = 3950.0;
const double r0 = 10000.0;
const double t0 = 273.0 + 25.0;
const double rx = r0 * exp(-beta/t0);
 
// Parâmetros do circuito
const double vcc = 4.92;
const double R = 9810.0;
 
// Numero de amostras na leitura
const int nAmostras = 5;

void setup(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    
}
void loop(){

  int soma = 0;
  for (int i = 0; i < nAmostras; i++) {
    soma += analogRead(pinTermistor);
    delay (100);
  }
 
  // Determina a resistência do termistor
  double v = (vcc*soma)/(nAmostras*1024.0);
  double rt = (vcc*R)/v - R;
 
  // Calcula a temperatura
  double t = beta / log(rt/rx);
  t= t-273;

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);  
  display.println("FritzenLab");
  display.setTextColor(WHITE); 
  display.setTextSize(3);   
  //display.setTextColor(WHITE);
  display.setCursor(0,9);
  display.print(t);
  display.println(" C");
  display.display();
  delay(1000);
  
  
}