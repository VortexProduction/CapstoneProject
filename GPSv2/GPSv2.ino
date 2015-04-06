// Test code for Adafruit GPS modules using MTK3329/MTK3339 driver
//
// This code shows how to listen to the GPS module in an interrupt
// which allows the program to have more 'freedom' - just parse
// when a new NMEA sentence is available! Then access data when
// desired.
//
// Tested and works great with the Adafruit Ultimate GPS module
// using MTK33x9 chipset
//    ------> http://www.adafruit.com/products/746
// Pick one up today at the Adafruit electronics shop 
// and help support open source hardware & software! -ada

#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
#include <TinyGPS++.h>

SoftwareSerial ss(3, 2);
LiquidCrystal lcd(7,8,9,12,4,13);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, 6, NEO_GRB + NEO_KHZ800);

//true north: Longitude = 78.3 North, Latitude = 104.0 West
#define North_LAT 78.3
#define North_LNG 104.0

TinyGPSPlus gps;
static const uint32_t GPSBaud = 9600;
<<<<<<< Updated upstream
=======

static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}

>>>>>>> Stashed changes

void setup()  
{
  //LEd strip initialization
  strip.begin();
  strip.show();  
  // connect at 115200 so we can read the GPS fast enough and echo without dropping chars
  // also spit it out
  Serial.begin(115200);
  ss.begin(GPSBaud);
  lcd.begin(16,2);
  pinMode(11,OUTPUT);
  setBacklight(255);
  strip.setBrightness(64);
}

void setBacklight(uint8_t b) {
  // normalize the red LED - its brighter than the rest!
 

  b = map(b, 0, 255, 0, 100);
 
  // common anode so invert!
  b = map(b, 0, 255, 255, 0);
  analogWrite(11, b);
}

uint32_t timer = millis();
int counter = 0;


void loop()                     // run over and over again
{
  
  while (ss.available() > 0)
<<<<<<< Updated upstream
  {
    if (gps.encode(ss.read()))
    {
      displayInfo();
    }
    else
    {
      lcd.clear();
      for(int i = 0; i < 12; i++)
      {
      
      lcd.setCursor(0,0);
      lcd.print("Searching");
        strip.setPixelColor(i,255,0,255);
        strip.show();
        delay(75);
        strip.setPixelColor(i,0,0,0);
      }  
    }
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
  }
      /*if(GPS.angle > 315 && GPS.angle < 45)
      {
         ClearLEDS();
         strip.setPixelColor(1,255,0,255);
         strip.show(); 
      }
      if(GPS.angle > 45 && GPS.angle < 135)
=======
  {    
      if(gps.encode(ss.read()))
>>>>>>> Stashed changes
      {
        Serial.println(F("test2"));
        displayInfo();
      }
      else
      {
        /*lcd.clear();
        for(int i = 0; i < 12; i++)
        {
        
        lcd.setCursor(0,0);
        lcd.print("Searching");
          strip.setPixelColor(i,255,0,255);
          strip.show();
          //delay(75);
          smartDelay(0);
          strip.setPixelColor(i,0,0,0);
        } 
       //smartDelay(0); */
      }
    if (millis() > 5000 && gps.charsProcessed() < 10)
    {
      Serial.println(F("No GPS detected: check wiring."));
    }

    
  }
        
    

       
}


void ClearLEDS()
{
  for(int i = 0; i < 12; i++)
      {
        strip.setPixelColor(i,0,0,0);
        strip.show();
      }
}

void displayInfo()
{
  
  double courseToDestination = TinyGPSPlus::courseTo(
  gps.location.lat(), gps.location.lng(), North_LAT, North_LNG);
  const char *directionToDestination = TinyGPSPlus::cardinal(courseToDestination);
  int courseChangeNeeded = (int)(360 + courseToDestination - gps.course.deg()) % 360;
  
  if(gps.speed.isValid())
  {
     //lcd.clear();
     //ss.print(gps.speed.kmph());
     lcd.setCursor(0,0);
     lcd.print("Speed (km/h):");
     lcd.setCursor(0,1);
     //lcd.print(69);
     lcd.print(gps.speed.kmph());
     
     //lcd.setCursor(6,1);
     //lcd.print(gps.satellites);
     lcd.setCursor(12,1);
     lcd.print(courseChangeNeeded);
     //Serial.println(gps.location.lat());
     //Serial.println(gps.location.lng());
     //Serial.println(courseChangeNeeded);
     
  }
  smartDelay(0);
  if (courseChangeNeeded >= 345 || courseChangeNeeded < 15)      
      {
         ClearLEDS();
         strip.setPixelColor(1,255,0,255);
         strip.show(); 
      }
    else if (courseChangeNeeded >= 15 && courseChangeNeeded < 45)       
      {
         ClearLEDS();
         strip.setPixelColor(2,255,0,255);
         strip.show(); 
      }     
    else if (courseChangeNeeded >= 45 && courseChangeNeeded < 75)       
      {
         ClearLEDS();
         strip.setPixelColor(3,255,0,255);
         strip.show(); 
      }
    else if (courseChangeNeeded >= 75 && courseChangeNeeded < 105)       
      {
         ClearLEDS();
         strip.setPixelColor(4,255,0,255);
         strip.show(); 
      }     
    else if (courseChangeNeeded >= 105 && courseChangeNeeded < 135)
      {
         ClearLEDS();
         strip.setPixelColor(5,255,0,255);
         strip.show(); 
      }
    else if (courseChangeNeeded >= 135 && courseChangeNeeded < 165)
      {
         ClearLEDS();
         strip.setPixelColor(6,255,0,255);
         strip.show(); 
      }
    else if (courseChangeNeeded >= 165 && courseChangeNeeded < 195)
      {
         ClearLEDS();
         strip.setPixelColor(7,255,0,255);
         strip.show(); 
      }
    else if (courseChangeNeeded >= 195 && courseChangeNeeded < 225)
      {
         ClearLEDS();
         strip.setPixelColor(8,255,0,255);
         strip.show(); 
      }
    else if (courseChangeNeeded >= 225 && courseChangeNeeded < 255)
      {
         ClearLEDS();
         strip.setPixelColor(9,255,0,255);
         strip.show(); 
      }
    else if (courseChangeNeeded >= 255 && courseChangeNeeded < 285)
      {
         ClearLEDS();
         strip.setPixelColor(10,255,0,255);
         strip.show(); 
      }
    else if (courseChangeNeeded >= 285 && courseChangeNeeded < 315)
      {
         ClearLEDS();
         strip.setPixelColor(11,255,0,255);
         strip.show(); 
      }
    else if (courseChangeNeeded >= 315 && courseChangeNeeded < 345)
      {
         ClearLEDS();
         strip.setPixelColor(0,255,0,255);
         strip.show(); 
      }
      
}
