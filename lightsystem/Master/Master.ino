#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket 
#endif

#define PIN        13 // On Trinket or Gemma, suggest changing this to 1 

#define NUMPIXELS 40 // Popular NeoPixel ring size 

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#include <Wire.h>

char c;
int cijfer; 
int prevCijfer = 0;
String busy = "";

void setup() {
  Wire.begin();                // join i2c bus with address #8
  Wire.onReceive(LightsSystem);
}

void loop() {
  delay(100);
  Wire.beginTransmission(8);
  Wire.write("50");
  Wire.endTransmission();
}

void LightsSystem()
{
  while (Wire.available()) { // slave may send less than requested
    c = Wire.read(); // receive a byte as character
    busy += c;
  }
  cijfer = busy.toInt();
  Serial.println(cijfer);

  if (cijfer != prevCijfer)
  {
    if (cijfer < 30)
    {
      for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...

        // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
        // Here we're using a moderately bright green color:
        pixels.setPixelColor(i, pixels.Color(0, 255, 0));

        pixels.show();   // Send the updated pixel colors to the hardware.
      }
    }
    else if (cijfer > 30 && cijfer < 70)
    {
      for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...

        // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
        // Here we're using a moderately bright green color:
        pixels.setPixelColor(i, pixels.Color(255, 165, 0));

        pixels.show();   // Send the updated pixel colors to the hardware.
      }
    }
    else if (cijfer < 100)
    {
      for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...

        // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
        // Here we're using a moderately bright green color:
        pixels.setPixelColor(i, pixels.Color(255, 0, 0));

        pixels.show();   // Send the updated pixel colors to the hardware.
      }
    }
  }
  delay(500);
  prevCijfer = cijfer;
  busy = "";
}
