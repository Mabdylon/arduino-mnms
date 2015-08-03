#ifndef WHEEL_H
#define WHEEL_H

#include <Arduino.h>
#include <Servo.h>

class Wheel {

private:
  int pin;
  Servo servo;

  byte upPosition = 0;
  byte downPosition = 177;
  byte middlePosition = 83;

public:
  Wheel(int);

  void moveUp();
  void moveDown();
  void moveMiddle();
  
};

#endif
