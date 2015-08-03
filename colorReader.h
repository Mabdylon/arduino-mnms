#ifndef COLORREADER_H
#define COLORREADER_H

#include <Arduino.h>

class ColorReader {

private:
  byte s0, s1, s2, s3, led;
  int  out;

public:
  ColorReader(byte, byte, byte, byte, byte, int);

  void setSensitivityMode();
  void unsetSensitivityMode(); 

  unsigned long readColor(byte);

  unsigned long checkWhite();
  unsigned long checkRed();
  unsigned long checkBlue();
  unsigned long checkGreen();

};

#endif
