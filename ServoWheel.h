#include <Servo.h>

int pinServoWheel = 5;
int moveServoWheelForward = 93;
int moveServoWheelNone = 99;
int moveServoWheelBackward = 104;
Servo servoWheel;

void initServoWheel() {
  servoWheel.attach(pinServoWheel);
}

void servoWheelMove() {
  if (isServoWheelOn) {
    if (isHoleDetected) {
      servoWheel.write(moveServoWheelNone); // stop the wheel
      Serial.println("I'm stopping for 1 sec");
      delay(1000);
      servoWheel.write(moveServoWheelForward);
      delay(150);
    } else {
      Serial.println("i continue");
      servoWheel.write(moveServoWheelForward);
    }
    /*if (isWheelBlocked) {
      servoWheel.write(moveServoWheelBackward);
      delay(250);
      isWheelBlocked = false;
    }*/
  }
}

void testServoWheelForward() {
  servoWheel.write(125);
}

void testServoWheelBackward() {
  servoWheel.write(135);
}

void testServoWheel90() {
  servoWheel.write(92);
}

void calibrateServoWheel() {
  servoWheel.write(180);
  Serial.println("sending 180");
  delay(3000);
  servoWheel.write(90);
  Serial.println("sending 90");
  delay(15000);
  servoWheel.write(0);
  Serial.println("sending 0");
  delay(3000);
  servoWheel.write(90);
  Serial.println("sending 90");
  delay(15000);
}

void forWheel() {
  int i = 0;
  for (i = 0; i < 360; i = i + 10) {
    servoWheel.write(i);
    Serial.print("I = ");
    Serial.print(i);
    delay(1000);
  }
}

