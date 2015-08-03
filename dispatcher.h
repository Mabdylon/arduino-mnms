#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <Arduino.h>
#include <Servo.h>

class Dispatcher {

private:
  int pin;
  Servo servo;

  byte redPosition = 10;
  byte yellowPosition = 40;
  byte bluePosition = 70;
  byte brownPosition = 100;
  byte orangePosition = 130;
  byte greenPosition = 160;
  byte garbagePosition = 190;

public:
  Dispatcher(int);

  void moveRed();
  void moveYellow();
  void moveBlue();
  void moveBrown();
  void moveOrange();
  void moveGreen();
  void moveGarbage();
  
};

#endif
