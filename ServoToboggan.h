#include <Servo.h>

int pinServoToboggan = 3;
Servo servoToboggan;
int posistionsToboggan[] = {0, 36, 72, 108, 144, 180};

int lastTimeToboggan;
int nowToboggan;
int intervalToboggan = 5000;
 
void initServoToboggan() {
  servoToboggan.attach(pinServoToboggan);
  lastTimeToboggan = millis();
  nowToboggan = millis();
}

void randomMoveServoToboggab() {
  nowToboggan = millis();  
  if(nowToboggan - lastTimeToboggan > intervalToboggan) {
    lastTimeToboggan = millis();
    int randomPosition = posistionsToboggan[random(0,7)];
    Serial.print("random pos : ");
    Serial.println(randomPosition);
    servoToboggan.write(randomPosition);
  }
  
}

void forWheelToboggan() {
  int i = 0;
  for (i = 0; i < 180; i = i + 10) {
    servoToboggan.write(i);
    Serial.print("I = ");
    Serial.println(i);
    delay(1000);
  }
}
