// Arduino base library
#include <Arduino.h>

// RGB Strip
#include <RGBStrip.h>

//Pins
#define RED_PIN 12
#define GREEN_PIN 14
#define BLUE_PIN 15

RGBStrip strip(RED_PIN, GREEN_PIN, BLUE_PIN);

int red = 255;  // Red channel
int green = 0;  // Green channel
int blue = 255; // Blue channel

void setup()
{
  // No need to initialize RGB pins
  // The RGBStrip class already does it internally

  // Set RGB pins to OFF
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  // Set strip to green to indicate everything is OK
  strip.setColor(RGBStrip::GREEN);
}

void loop()
{
  // Do some stuff

  // Do nothing for the first five seconds, then
  // breathe for ten seconds then do rainbow effect forever
  // The duration of each effect cycle is adjusted individually
  // No delay() used
  if (millis() < 5000)
  {
  }
  else if (millis() < 15000)
  {
    strip.breathe(red, green, blue, 2000);
  }
  else
  {
    strip.rainbow(1000);
  }

  // Do more stuff
}
