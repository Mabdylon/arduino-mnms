/*
 * 
 * Trieur de bonbons
 * Date: Aout 2015
 * 
 */

#include <Servo.h>

#include "unlocker.h"
#include "wheel.h"
#include "dispatcher.h"
#include "colorReader.h"

// PIN
int unlockerPIN=13;
int wheelPIN=11;
int dispatcherPIN=12;

byte s0PIN = 4;
byte s1PIN = 5;
byte s2PIN = 6;
byte s3PIN = 7;
byte ledPIN = 8;
byte outPIN = 9;
 
// Les composants:
Unlocker* unlocker;
Wheel* wheel; 
Dispatcher* dispatcher;
ColorReader* colorReader;

void setup() {

  Serial.begin(9600);

  unlocker = new Unlocker(unlockerPIN);

  wheel = new Wheel(wheelPIN);
  dispatcher = new Dispatcher(dispatcherPIN);
  colorReader = new ColorReader(s0PIN, s1PIN, s2PIN, s3PIN, ledPIN, outPIN);  
}

void loop() {

  // feedTheWheel: on collecte un bonbon depuis le puit.

  wheel->moveMiddle();
  delay(500);

  colorReader->setSensitivityMode();
  delay(100);

  for (int i=1; i<4; i++) {
    Serial.print("Color: ");
    Serial.print(i);
    Serial.print(" value: ");
    Serial.println(colorReader->readColor(i));
  }
  Serial.println("");
  delay(100);
  colorReader->unsetSensitivityMode();
  delay(500);
  wheel->moveDown();
  delay(1000);
  wheel->moveUp();
  delay(1000);

  /*
  dispatcher->moveYellow();
  delay(1000);
  dispatcher->moveBlue();
  delay(1000);
  dispatcher->moveBrown();
  delay(1000);
  dispatcher->moveOrange();
  delay(1000);
  dispatcher->moveGreen();
  delay(1000);
  dispatcher->moveGarbage();
  delay(1000);
  dispatcher->moveRed();
  delay(1000);
*/  
  // readCandyColor: Je regarde la couleur du bonbon.

  // dispatchCandyByColor: J'envoie le bonbon dans le bon bac.

}
