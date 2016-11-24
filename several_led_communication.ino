//////RGB LED/////////////////////////
int AredPin = 2;
int AgreenPin = 3;
int AbluePin = 4;

int BredPin = 5;
int BgreenPin = 6;
int BbluePin = 7;

int CredPin = 8;
int CgreenPin = 9;
int CbluePin = 10;
//////////////servo parameter///////////
#include<Servo.h>
int servoLeftAngle = 1;
Servo servoLeft;
int pinServoLeft = 11;
int speedLeft = 1;

int servoRightAngle = 170;
Servo servoRight;
int pinServoRight = 12;
int speedRight = -1;
/////serial communicate data///////////
int comingData;
boolean stateLeft = false;
boolean stateRight = false;
/////////////////////////////////////
void setup() {
  Serial.begin(9600);
  pinMode(AredPin, OUTPUT);
  pinMode(AgreenPin, OUTPUT);
  pinMode(AbluePin, OUTPUT);
  pinMode(BredPin, OUTPUT);
  pinMode(BgreenPin, OUTPUT);
  pinMode(BbluePin, OUTPUT);
  pinMode(CredPin, OUTPUT);
  pinMode(CgreenPin, OUTPUT);
  pinMode(CbluePin, OUTPUT);
  ////////pinServo//////////////////
  servoLeft.attach(pinServoLeft);
  servoRight.attach(pinServoRight);
  servoRight.write(servoRightAngle);
}
////////////////////////////////////////////
void loop() {
  //////receiving the data from processing///////
  if (Serial.available()) {
    comingData = Serial.read();
    if (comingData < 5 && stateLeft == false) {
      stateLeft = true;
      speedLeft = 1;
      servoLeftAngle = 1;
    }
    if (comingData < 10 && comingData > 4 && stateRight == false) {
      stateRight = true;
      speedRight = -1;
      servoRightAngle = 170;
    }
    if (comingData < 15 && comingData > 9) {
      lighting_Cled();
      delay(4000);
    }
  } else {
    AsetColor(0, 0, 0);
    BsetColor(0, 0, 0);
    CsetColor(0, 0, 0);
  }
  
  //////servo///////
  if (stateLeft == true) {
    servoLeftRotate();
  }

  if (stateRight == true) {
    servoRightRotate();
  }

}
