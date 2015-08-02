int irSensor = 0;
int pinIRSensor = 13;
int lastIrResult;
int lengthResult = 5;
int results[] = {0,0,0,0,0};
int durationToBlockWheel = 2000;
unsigned long lastTimeChanging;

void initIRSensor() {
  pinMode(pinIRSensor, INPUT);
  lastTimeChanging = millis();
}

void computeIfWheelBlocked(boolean isHole) {
  int now = millis();
  if(isHole || isWheelBlocked) {
    lastTimeChanging = now;
    return;
  }
  if(now - lastTimeChanging > durationToBlockWheel) {
      isWheelBlocked = true;
  }  
}

void pushPopResult(int result) {
  for(int i = 0; i < lengthResult; i++) {
    int oldResult = results[i];
    if(i < lengthResult -1) {
      results[i+1] = oldResult;
    }
  }
  results[0] = result;
}

int computeDominantResult() {
  int sum = 0;
  for(int i= 0; i < lengthResult; i++) {
    sum += results[i];
  }
  if(sum > (lengthResult/2)) {
    return 1;
  } else {
    return 0; 
  }
}

void irSensorMesure() {
  if (isIrSensorOn) {
    
    pushPopResult(digitalRead(pinIRSensor));
    int irResult = computeDominantResult();
    Serial.print("IrSensor : ");
    Serial.println(isHoleDetected);
    Serial.print("IrResult : ");
    Serial.println(digitalRead(pinIRSensor));
    isHoleDetected = (irResult == 0 && lastIrResult == 1);
    computeIfWheelBlocked(isHoleDetected);
    lastIrResult = irResult;
  }
}



void testIrSensor() {
  irSensor = digitalRead(pinIRSensor);
  Serial.println(irSensor);
}

