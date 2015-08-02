#include <Servo.h>

int pinServoUnlocker = 6;
Servo servoUnlocker;
int moveServoUnlockerForward = 150;
int moveServoUnlockerBackward = 90;

int lastTimeUnlocker;
int nowUnlocker;
int intervalForwardUnlocker;
int intervalBackwardUnlocker;
boolean isServoMovingForward;

void initServoUnlocker() {
  servoUnlocker.attach(pinServoUnlocker);
  isServoMovingForward = true;
  intervalForwardUnlocker = 90;
  intervalBackwardUnlocker = 1000;
  lastTimeUnlocker = millis();
  servoUnlocker.write(moveServoUnlockerBackward);
}

void moveServoUnlocker() {
  nowUnlocker = millis();
  /*Serial.print("isServoWheelForward : ");
  Serial.println(isServoMovingForward);
  Serial.print("Interval : ");
  Serial.print(lastTimeUnlocker - nowUnlocker);*/
  if(isServoMovingForward) {
    if(nowUnlocker - lastTimeUnlocker  > intervalForwardUnlocker) {
      Serial.println("unlocker forward");
      lastTimeUnlocker = millis();
      isServoMovingForward = !isServoMovingForward;
      servoUnlocker.write(moveServoUnlockerBackward);
    }  
  } else {
    if(nowUnlocker - lastTimeUnlocker  > intervalBackwardUnlocker) {
      Serial.println("unlocker backward");
      lastTimeUnlocker = millis();
      isServoMovingForward = !isServoMovingForward;
      servoUnlocker.write(moveServoUnlockerForward);
    }
  }
}

