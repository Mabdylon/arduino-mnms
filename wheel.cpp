#include "wheel.h"

Wheel::Wheel(int wheelPIN) {
  
  pin = wheelPIN;
  servo.attach(pin);

  moveUp();
  
}

void Wheel::moveUp() {
  servo.write(upPosition);
}

void Wheel::moveDown() {
  servo.write(downPosition);
}

void Wheel::moveMiddle() {
  servo.write(middlePosition);
}

