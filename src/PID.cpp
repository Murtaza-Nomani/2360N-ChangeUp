//THIS CODE IS EXPERIMENTAL, I DID NOT ACTUALLY USE THIS
#include "global.h"

static int driveMode = 1;
static int driveTarget = 0;
static int turnTarget = 0;
static int maxSpeed = 80;

static int gStart = 0;

int drivePos(){
  return (left1.get_position() + right1.get_position())/2;
}

bool isDriving(){
  static int count = 0;
  static int last = 0;
  static int lastTarget = 0;

  int curr = right2.get_position();

  int target = turnTarget;
  if(driveMode == 1)
    target = driveTarget;

  if(abs(last-curr) < 3)
    count++;
  else
    count = 0;

  if(target != lastTarget)
    count = 0;

  lastTarget = target;
  last = curr;

  //not driving if we haven't moved
  if(count > 4)
    return false;
  else
    return true;
  return true;
}

void reset() {
  driveTarget = 0;
  left1.tare_position();
  left2.tare_position();
  right1.tare_position();
  right2.tare_position();
  rightDrive(0);
  leftDrive(0);
}

void driveAsync(int sp){
  reset();
  gStart = getGyro();
  driveTarget = sp;
  driveMode = 1;
}

void turnAsync(int sp){
  reset();
  turnTarget = sp;
  driveMode = 0;
}

void drive(int sp){
  driveAsync(sp);
  delay(450);
  while(isDriving()) delay(20);
}

void turn(int sp){
  turnAsync(sp);
  delay(450);
  while(isDriving()) delay(20);
}

void setSpeed(int speed) {
  maxSpeed = speed;
}


void driveTask(void* param){
  int prevError = 0;
  float kp = 0.29;
  float kd = 3.36;
  float kg = 1.5;
  float slant = 0;
  while(true){
    if(driveMode != 1)
      continue;

    int target = driveTarget;

    int pos = drivePos();

    int error = target - pos;
    int derivative = error - prevError;
    prevError = error;
    int speed = error*kp + derivative*kd;

    if(speed > maxSpeed)
      speed = maxSpeed;
    if(speed < -maxSpeed)
      speed = -maxSpeed;

    float gyroPos = getGyro();
    if(fabs(gStart - gyroPos) >= 0.5) {
      slant = kg * (gStart-gyroPos);
    } else {
      slant = 0;
    }

    leftSlew(speed - slant);
    rightSlew(speed + slant);

    delay(20);
  }
}

void turnTask(void*param) {
  int prevError;
  float kp = 3.1;
  float kd = 13.3;
  while(1){

    if(driveMode != 0)
      continue;

    float deg = turnTarget;

    float pos = getGyro();
    float error = deg - pos;

    float derivative = error - prevError;
    prevError = error;
    int speed = error*kp + derivative*kd;

    if(speed > maxSpeed)
      speed = maxSpeed;
    if(speed < -maxSpeed)
      speed = -maxSpeed;

    leftSlew(-speed);
    rightSlew(speed);

    delay(20);
  }
}
