void servoLeftRotate() {
  lighting_Aled();
  servoLeftAngle += speedLeft;
  servoLeft.write(servoLeftAngle);
  delay(1);
  if (servoLeftAngle == 120) {
    delay(4000);
    speedLeft *= -1;
  }
  if (servoLeftAngle == 0) {
    stateLeft = false;
  }
}

void servoRightRotate() {
  lighting_Bled();
  servoRightAngle += speedRight;
  servoRight.write(servoRightAngle);
  if (servoRightAngle == 100) {
    delay(4000);
    speedRight *= -1;
  }
  if (servoRightAngle == 170) {
    stateRight = false;
  }
}
