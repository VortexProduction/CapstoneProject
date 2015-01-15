// include the library code:
#include <LiquidCrystal.h>
#include <Wire.h>
 
#define BLUELITE 11
 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 12, 4, 2);
 
// you can change the overall brightness by range 0 -> 255
int brightness = 255;
int counter = 0;
int counter2 = 0;
 
void setup() {
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("HashtagYoloSwag");
  
  pinMode(BLUELITE, OUTPUT);
  pinMode(10,OUTPUT);    //Yellow
  pinMode(3,OUTPUT);     //Red
  pinMode(6,OUTPUT);     //Green
  pinMode(5,OUTPUT);     //Blue

  brightness = 100;
}
 
 
void loop() {
  
  setBacklight(255, 0, 255);
  analogWrite(3,counter);
  analogWrite(6,counter2);
  counter+= 10;
  counter2+= 20;
  if(counter == 250)
  {
    counter = 0;
  } 
  if(counter2 >= 127)
  {
    counter2 = 50;
  }
 delay(50); 
}

 
 
void setBacklight(uint8_t r, uint8_t g, uint8_t b) {
  // normalize the red LED - its brighter than the rest!
 

  b = map(b, 0, 255, 0, brightness);
 
  // common anode so invert!
  b = map(b, 0, 255, 255, 0);

  Serial.print(" B = "); Serial.println(b, DEC);
  analogWrite(BLUELITE, b);
}
