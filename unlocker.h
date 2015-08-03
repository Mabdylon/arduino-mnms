#ifndef UNLOCKER_H
#define UNLOCKER_H

#include <Arduino.h>
#include <Servo.h>

class Unlocker {

private:
  int pin;
  Servo servo;
  int servoSpeed = 93;

/*  
  bool forward;
  int intervalForward;
  int intervalBackward;
  int moveForward;
  int moveBackward;
  unsigned int lastTime;
*/
public:
  Unlocker(int);

  //void turn();

};

#endif
