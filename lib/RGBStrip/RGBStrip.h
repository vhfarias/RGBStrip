#ifndef _RGBSTRIP_H
#define _RGBSTRIP_H

#include "Arduino.h"

class RGBStrip
{
public:
  RGBStrip(int redPin, int greenPin, int bluePin); // Constructor

  void test(void);

  void off(void);

  void setColor(int red, int green, int blue);
  void setColor(int rgb[3]);

  int *getColor(void);

  void blink(int red, int green, int blue, unsigned long duration);
  void blink(int red, int green, int blue, unsigned long onDuration, unsigned long offDuration);

  void blink(int rgb[3], unsigned long duration);
  void blink(int rgb[3], unsigned long onDuration, unsigned long offDuration);

  void fadeIn(int red, int green, int blue, int duration);
  void fadeIn(int rgb[3], int duration);

  void fadeOut(int red, int green, int blue, int duration);
  void fadeOut(int rgb[3], int duration);

  void breathe(int red, int green, int blue, unsigned int duration);
  void breathe(int rgb[3], unsigned int duration);

  void breathe(int red, int green, int blue, unsigned int inDuration, unsigned int outDuration);
  void breathe(int rgb[3], unsigned int inDuration, unsigned int outDuration);

  void flicker(int red, int green, int blue, int spread);
  void flicker(int rgb[3], int spread);

  void shift(int redStart, int greenStart, int blueStart, int redEnd, int greenEnd, int blueEnd, unsigned int duration);
  void shift(int rgbStart[3], int rgbEnd[3], unsigned int duration);

  void rainbow(unsigned int duration);

  void siren(unsigned int duration);

  static int RED[3];
  static int GREEN[3];
  static int BLUE[3];
  static int MAGENTA[3];
  static int CYAN[3];
  static int YELLOW[3];
  static int WHITE[3];
  static int ORANGE[3];

private:
  void _off(void);
  void _setColor(int r, int g, int b);
  void _blink(int r, int g, int b, unsigned long onDuration, unsigned long offDuration);
  void _fade(int r, int g, int b, unsigned int duration, bool out);
  void _breathe(int r, int g, int b, unsigned int inDuration, unsigned int outDuration);
  void _flicker(int r, int g, int b, int s);
  void _shift(int r1, int g1, int b1, int r2, int g2, int b2, unsigned int duration);
  void _test(void);
  int _redPin;
  int _greenPin;
  int _bluePin;
  int _rgb[3];
  String _queue;
};

#endif // _RGBSTRIP_H