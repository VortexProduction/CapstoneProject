#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN 6
int blue = 0;
int green = 0;
int red = 0;
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
  strip.setBrightness(250);
  green = random(0,255);
  red = random(0,255);
  blue = random(0,255);
  int i = random(0,12);
    strip.setPixelColor(i,red,green,blue);
    strip.show();
    strip.setPixelColor(i,0,0,0);
  
}
