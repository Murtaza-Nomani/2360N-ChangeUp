#include "global.h"

void rollers(int time) {
  rollerR = 120;
  rollerL = 120;
  delay(time);
  rollerR = 0;
  rollerL = 0;
}

void intake(int time) {
  intakeU = 120;
  intakeD = 120;
  delay(time);
  intakeU = 0;
  intakeD = 0;
}

void setRoller(int speed) {
  rollerR = speed;
  rollerL = speed;
}

void setIntake(int speed) {
  intakeU = speed;
  intakeD = speed;
}
