// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

char c;
int cijfer;
int prevCijfer = 0;
String busy = "";

void setup()
{
  Wire.begin(8);
  Wire.onReceive(LightsSystem);
  Serial.begin(9600)
  pixels.Start();
}

byte x = 0;

void loop() {
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write("20");              // sends one byte
  Wire.endTransmission();    // stop transmitting

  delay(500);
}
