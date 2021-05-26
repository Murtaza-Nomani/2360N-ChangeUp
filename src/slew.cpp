#include "global.h"

int rightSpeed = 0;
int leftSpeed = 0;

int accel = 5;
int decel = 256;

void leftSlew(int target) {
  if(target > 0) {
    if(leftSpeed + accel < target) {
      leftSpeed += accel;
    } else {
      leftSpeed = target;
    }
  } else if (target < 0) {
    if(leftSpeed - accel > target) {
      leftSpeed -= accel;
    } else {
      leftSpeed = target;
    }
  } else {
    leftSpeed = 0;
  }
  leftDrive(leftSpeed);
}

void rightSlew(int target) {
  if(target > 0) {
    if(rightSpeed + accel < target) {
      rightSpeed += accel;
    } else {
      rightSpeed = target;
    }
  } else if (target < 0) {
    if(rightSpeed - accel > target) {
      rightSpeed -= accel;
    } else {
      rightSpeed = target;
    }
  } else {
    rightSpeed = 0;
  }
  rightDrive(rightSpeed);
}
