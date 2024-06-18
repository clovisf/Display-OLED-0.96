#include <C:\Users\Clovisf\Documents\GitHub\Display-OLED-0.96\teste-display-oled-0.96\DigisparkOLED.h>
#include <Wire.h>
// ============================================================================
int counter= 0;
void setup() 
{
  // put your setup code here, to run once:
  oled.begin();
  oled.clear(); //all black
}

void loop()
{
  delay(1000);
  counter++; 
  oled.setCursor(0, 0); //top left
  oled.setFont(FONT6X8);
  oled.print(F("This is a text test")); //lines auto wrap
  oled.setCursor(0, 1);
  oled.print(F("from FritzenLab")); //lines auto wrap
  oled.setFont(FONT8X16);
  oled.setCursor(0, 2); //two rows down because the 8x16 font takes two rows of 8
  oled.print(F("FritzenLab.net")); //wrap strings in F() to save RAM!
  oled.setFont(FONT6X8);
  oled.setCursor(0, 4); //two rows down because the 8x16 font takes two rows of 8
  oled.print(F("FritzenLab.com.br")); //wrap strings in F() to save RAM!
  oled.setFont(FONT8X16);
  oled.setCursor(10, 5); //two rows down because the 8x16 font takes two rows of 8
  oled.print(counter); //wrap strings in F() to save RAM!

  //delay(3000);
}