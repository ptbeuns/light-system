// Wire Master Reader
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender" example for use with this

// Created 29 March 2006

// This example code is in the public domain.



#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket 
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        13 // On Trinket or Gemma, suggest changing this to 1 

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 40 // Popular NeoPixel ring size 

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int color = 0;


#include <Wire.h>

char c;
int cijfer; 
int prevCijfer = 0;
String busy = "";

void setup() {
  Wire.begin(8);        // join i2c bus (address optional for master)
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(9600);  // start serial for output
}

void loop() {

  Wire.requestFrom(8, 2);    // request 6 bytes from slave device #8

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
