#include "Arduino.h"
#include <iostream>

#include "RGBStrip.h"

RGBStrip::RGBStrip(int redPin, int greenPin, int bluePin) : _redPin(redPin), _greenPin(greenPin), _bluePin(bluePin)
{
  pinMode(_redPin, OUTPUT);
  pinMode(_greenPin, OUTPUT);
  pinMode(_bluePin, OUTPUT);
}

// Class constants

int RGBStrip::RED[3] = {255, 0, 0};
int RGBStrip::GREEN[3] = {0, 255, 0};
int RGBStrip::BLUE[3] = {0, 0, 255};
int RGBStrip::YELLOW[3] = {255, 255, 0};
int RGBStrip::CYAN[3] = {0, 255, 255};
int RGBStrip::MAGENTA[3] = {255, 0, 255};
int RGBStrip::WHITE[3] = {255, 255, 255};
int RGBStrip::ORANGE[3] = {255, 100, 0};

//Public methods

void RGBStrip::test(void)
{
  _test();
}

void RGBStrip::off(void)
{
  _off();
}

void RGBStrip::setColor(int red, int green, int blue)
{
  _setColor(red, green, blue);
}

void RGBStrip::setColor(int rgb[3])
{
  _setColor(rgb[0], rgb[1], rgb[2]);
}

int *RGBStrip::getColor(void)
{
  return _rgb;
}

void RGBStrip::blink(int red, int green, int blue, unsigned long duration)
{
  _blink(red, green, blue, duration, duration);
}

void RGBStrip::blink(int red, int green, int blue, unsigned long onDuration, unsigned long offDuration)
{
  _blink(red, green, blue, onDuration, offDuration);
}

void RGBStrip::blink(int rgb[3], unsigned long duration)
{
  _blink(rgb[0], rgb[1], rgb[2], duration, duration);
}

void RGBStrip::blink(int rgb[3], unsigned long onDuration, unsigned long offDuration)
{
  _blink(rgb[0], rgb[1], rgb[2], onDuration, offDuration);
}

void RGBStrip::fadeIn(int red, int green, int blue, int duration)
{
  _fade(red, green, blue, duration, false);
}

void RGBStrip::fadeIn(int rgb[3], int duration)
{
  _fade(rgb[0], rgb[1], rgb[2], duration, false);
}

void RGBStrip::fadeOut(int red, int green, int blue, int duration)
{
  _fade(red, green, blue, duration, true);
}

void RGBStrip::fadeOut(int rgb[3], int duration)
{
  _fade(rgb[0], rgb[1], rgb[2], duration, true);
}

void RGBStrip::breathe(int red, int green, int blue, unsigned int duration)
{
  _breathe(red, green, blue, duration, duration);
}

void RGBStrip::breathe(int rgb[3], unsigned int duration)
{
  _breathe(rgb[0], rgb[1], rgb[2], duration, duration);
}

void RGBStrip::breathe(int red, int green, int blue, unsigned int inDuration, unsigned int outDuration)
{
  _breathe(red, green, blue, inDuration, outDuration);
}

void RGBStrip::breathe(int rgb[3], unsigned int inDuration, unsigned int outDuration)
{
  _breathe(rgb[0], rgb[1], rgb[2], inDuration, outDuration);
}

void RGBStrip::flicker(int red, int green, int blue, int spread)
{
  _flicker(red, green, blue, spread);
}

void RGBStrip::flicker(int rgb[3], int spread)
{
  _flicker(rgb[0], rgb[1], rgb[2], spread);
}

void RGBStrip::shift(int redStart, int greenStart, int blueStart, int redEnd, int greenEnd, int blueEnd, unsigned int duration)
{
  _shift(redStart, greenStart, blueStart, redEnd, greenEnd, blueEnd, duration);
}

void RGBStrip::shift(int rgbStart[3], int rgbEnd[3], unsigned int duration)
{
  _shift(rgbStart[0], rgbStart[1], rgbStart[2], rgbEnd[0], rgbEnd[1], rgbEnd[2], duration);
}

void RGBStrip::rainbow(unsigned int duration)
{
  int rgbStart[3];
  int rgbEnd[3];
  int totalColors = 7;

  unsigned int now = millis();

  //easing function
  //double x = (now % ((duration + 1) / totalColors)) / double(duration / double(totalColors));
  double x = now % duration / double(duration);
  x = (-cos(PI * x) + 1.) * 0.5;

  //choosing a stage
  //int stage = (now % (duration)) / (duration / totalColors);
  int stage = (now / duration) % totalColors;

  switch (stage)
  {
  case 0:
    for (int i = 0; i < 3; i++)
    {
      rgbStart[i] = RGBStrip::RED[i];
      rgbEnd[i] = RGBStrip::ORANGE[i];
    }
    break;
  case 1:
    for (int i = 0; i < 3; i++)
    {
      rgbStart[i] = RGBStrip::ORANGE[i];
      rgbEnd[i] = RGBStrip::YELLOW[i];
    }
    break;
  case 2:
    for (int i = 0; i < 3; i++)
    {
      rgbStart[i] = RGBStrip::YELLOW[i];
      rgbEnd[i] = RGBStrip::GREEN[i];
    }
    break;
  case 3:
    for (int i = 0; i < 3; i++)
    {
      rgbStart[i] = RGBStrip::GREEN[i];
      rgbEnd[i] = RGBStrip::CYAN[i];
    }
    break;
  case 4:
    for (int i = 0; i < 3; i++)
    {
      rgbStart[i] = RGBStrip::CYAN[i];
      rgbEnd[i] = RGBStrip::BLUE[i];
    }
    break;
  case 5:
    for (int i = 0; i < 3; i++)
    {
      rgbStart[i] = RGBStrip::BLUE[i];
      rgbEnd[i] = RGBStrip::MAGENTA[i];
    }
    break;
  case 6:
    for (int i = 0; i < 3; i++)
    {
      rgbStart[i] = RGBStrip::MAGENTA[i];
      rgbEnd[i] = RGBStrip::RED[i];
    }
    break;
  default:
    for (int i = 0; i < 3; i++)
    {
      rgbStart[i] = 0;
      rgbEnd[i] = 0;
    }
  }

  int rgb[3];
  for (int i = 0; i < 3; i++)
  {
    rgb[i] = rgbStart[i] + x * (rgbEnd[i] - rgbStart[i]);
  }
  setColor(rgb);
}

void RGBStrip::siren(unsigned int duration)
{
  unsigned int now = millis();
  int rgbStart[3];
  int rgbEnd[3];
  int totalColors = 2;

  double x = now % duration / double(duration);
  //easing function
  x = (-cos(PI * x) + 1.) * 0.5;

  int stage = (now / duration) % totalColors;
  switch (stage)
  {
  case 0:
    for (int i = 0; i < 3; i++)
    {
      rgbStart[i] = RGBStrip::RED[i];
      rgbEnd[i] = RGBStrip::BLUE[i];
    }
    break;
  case 1:
    for (int i = 0; i < 3; i++)
    {
      rgbStart[i] = RGBStrip::BLUE[i];
      rgbEnd[i] = RGBStrip::RED[i];
    }
    break;
  default:
    for (int i = 0; i < 3; i++)
    {
      rgbStart[i] = 0;
      rgbEnd[i] = 0;
    }
  }

  int deltas[3];
  for (int i = 0; i < 3; i++)
  {
    deltas[i] = rgbEnd[i] - rgbStart[i];
  }

  int rgb[3];
  for (int i = 0; i < 3; i++)
  {
    rgb[i] = rgbStart[i] + x * deltas[i];
  }
  setColor(rgb);
}

//Private Methods

void RGBStrip::_setColor(int r, int g, int b)
{
  if (r > 255)
  {
    r = 255;
  }
  else if (r < 0)
  {
    r = 0;
  };
  if (g > 255)
  {
    g = 255;
  }
  else if (g < 0)
  {
    g = 0;
  };
  if (b > 255)
  {
    b = 255;
  }
  else if (b < 0)
  {
    b = 0;
  };

  _rgb[0] = r;
  _rgb[1] = g;
  _rgb[2] = b;

  analogWrite(_redPin, r);
  analogWrite(_greenPin, g);
  analogWrite(_bluePin, b);
}

void RGBStrip::_off(void)
{
  _setColor(0, 0, 0);
}

void RGBStrip::_blink(int r, int g, int b, unsigned long onDuration, unsigned long offDuration)
{
  //internal function counter
  unsigned long _t = millis() % (onDuration + offDuration);

  if (_t < onDuration)
  {
    _setColor(r, g, b);
  }
  else if (_t < (onDuration + offDuration))
  {
    _off();
  }
}

void RGBStrip::_fade(int r, int g, int b, unsigned int duration, bool out)
{

  //internal function counter
  double x = millis() % (duration + 1) / double(duration);
  int f = out ? 1 : -1;

  double i = (f * cos(PI * x) + 1.) * 0.5;
  _setColor(r * i, g * i, b * i);
}

void RGBStrip::_breathe(int r, int g, int b, unsigned int inDuration, unsigned int outDuration)
{
  unsigned long _t = millis() % (inDuration + outDuration + 1);
  double x;

  if (_t > inDuration)
  {
    //fade out
    x = (_t - inDuration) / double(outDuration);
  }
  else
  {
    //fade in
    x = _t / double(inDuration) + 1;
  }
  double i = (cos(PI * x) + 1.) * 0.5;
  _setColor(r * i, g * i, b * i);
}

void RGBStrip::_flicker(int r, int g, int b, int s)
{
  int j = (rand() % s) - s;

  int cooldown = 400;

  if ((millis() % cooldown) > (0.7 * cooldown))
  {
    _setColor(r + j, g + j, b + j);
  }
}

void RGBStrip::_shift(int r1, int g1, int b1, int r2, int g2, int b2, unsigned int duration)
{
  int deltas[3] = {r2 - r1, g2 - g1, b2 - b1};
  double x = (millis() % (duration + 1)) / double(duration);

  //easing function
  x = (-cos(PI * x) + 1.) * 0.5;

  _setColor(r1 + x * deltas[0], g1 + x * deltas[1], b1 + x * deltas[2]);
}

void RGBStrip::_test(void)
{
  _setColor(RGBStrip::RED[0], RGBStrip::RED[1], RGBStrip::RED[2]);
  delay(1000);
  _setColor(RGBStrip::GREEN[0], RGBStrip::GREEN[1], RGBStrip::GREEN[2]);
  delay(1000);
  _setColor(RGBStrip::BLUE[0], RGBStrip::BLUE[1], RGBStrip::BLUE[2]);
  delay(1000);
  _setColor(RGBStrip::WHITE[0], RGBStrip::WHITE[1], RGBStrip::WHITE[2]);
  delay(1000);
  _off();
}