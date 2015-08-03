#include "unlocker.h"

Unlocker::Unlocker(int unlockerPIN) {

  pin = unlockerPIN;
  servo.attach(pin);
  
  servo.write(servoSpeed);
  
}


