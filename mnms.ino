boolean isIrSensorOn = true; 
boolean isColorSensorOn = true;
boolean isServoTobogganOn = true;
boolean isServoUnlockerOn = true;
boolean isServoWheelOn = true;
boolean isHoleDetected = false;
boolean isWheelBlocked = false;


#include <Servo.h>
#include "Arduino.h"
#include "ColorSensor.h"
#include "IRSensor.h"
#include "ServoToboggan.h"
#include "ServoUnlocker.h"
#include "ServoWheel.h"

// var :
// int irSensor = 0;
// int pinIRSensor = 4;

void setup() {
  Serial.begin(9600);
  //initColorSensor();
  initIRSensor();
  initServoToboggan();
  initServoWheel();
  initServoUnlocker();
}

void loop() {
  
  irSensorMesure();
  servoWheelMove();
  //moveServoUnlocker();
  //forWheelToboggan();
  //randomMoveServoToboggab();
  //forWheel();
  //testServoWheel90();
  //calibrateServoWheel();
  delay(10);
  //testServoWheelForward();
  //delay(2000);
  //testServoWheelBackward();
  //delay(500);
  //testServoWheelForward();
  //delay(1500);
  //testServoWheelBackward();
  //delay(1000);
  //testIrSensor();
  //delay(1000);
}
