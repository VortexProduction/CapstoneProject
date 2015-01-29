#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code


  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop(){
  strip.setBrightness(150);
 for(int n=0;n<12;n++)
{
 strip.setPixelColor(n,255,0,0);
 strip.show();
 delay(20);
 strip.setPixelColor(n,0,0,0);
} 
 for(int n=0;n<12;n++)
{
 strip.setPixelColor(n,0,255,0);
 strip.show();
 delay(20);
 strip.setPixelColor(n,0,0,0);
} 
 for(int n=0;n<12;n++)
{
 strip.setPixelColor(n,0,0,255);
 strip.show();
 delay(20);
 strip.setPixelColor(n,0,0,0);
} 
}
