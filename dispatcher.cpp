#include "dispatcher.h"

Dispatcher::Dispatcher(int dispatcherPIN) {
  
  pin = dispatcherPIN;
  servo.attach(pin);

  moveRed();
  
}

void Dispatcher::moveRed() {
  servo.write(redPosition);
}

void Dispatcher::moveYellow() {
  servo.write(yellowPosition);
}

void Dispatcher::moveBrown() {
  servo.write(brownPosition);
}

void Dispatcher::moveBlue() {
  servo.write(bluePosition);
}

void Dispatcher::moveOrange() {
  servo.write(orangePosition);
}

void Dispatcher::moveGreen() {
  servo.write(greenPosition);
}

void Dispatcher::moveGarbage() {
  servo.write(garbagePosition);
}

