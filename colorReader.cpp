#include "colorReader.h"

ColorReader::ColorReader(byte s0PIN, byte s1PIN, byte s2PIN, byte s3PIN, byte ledPIN, int outPIN) {
  s0 = s0PIN;
  s1 = s1PIN;
  s2 = s2PIN;
  s3 = s3PIN;
  led = ledPIN;
  out = outPIN;

  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(out, INPUT);
}

void ColorReader::setSensitivityMode() {
  digitalWrite(led, HIGH);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
}

void ColorReader::unsetSensitivityMode() {
  digitalWrite(led, LOW);
  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
}

unsigned long ColorReader::checkWhite() {
  float pulse;
  
  digitalWrite(s2, HIGH);
  digitalWrite(s3, LOW);

  pulse = pulseIn(out, LOW, 80000);

  if ( pulse < 0.1) {
    pulse = 80000;  
  }

  return(pulse);
}

unsigned long ColorReader::checkRed() {
  unsigned long pulse;
  
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);

  pulse = pulseIn(out, LOW, 80000);

  if ( pulse < 0.1) {
    pulse = 80000;  
  }

  return(pulse);
}

unsigned long ColorReader::checkBlue() {
  unsigned long pulse;
  
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);

  pulse = pulseIn(out, LOW, 80000);

  if ( pulse < 0.1) {
    pulse = 80000;  
  }

  return(pulse);
}

unsigned long ColorReader::checkGreen() {
  unsigned long pulse;
  
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);

  pulse = pulseIn(out, LOW, 80000);

  if ( pulse < 0.1) {
    pulse = 80000;  
  }

  return(pulse);
}

unsigned long ColorReader::readColor(byte color) {
  unsigned int pulse;

  if ( color == 0 ) {         // WHITE
    digitalWrite(s2, HIGH);
    digitalWrite(s3, LOW);
  } else if ( color == 1 ) {  // RED
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
  } else if ( color == 2 ) {  // BLUE
    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);    
  } else if ( color == 3 ) {  // GREEN
    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
  }
  
  pulse = pulseIn(out, LOW);

  return(pulse);
}

