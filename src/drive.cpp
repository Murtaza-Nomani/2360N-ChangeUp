#include "global.h"

float CIRCUM= (3.25 * M_PI);
float TICKS= 900;
float GEAR_RATIO =  (5/3);

int sgn(float num) {
  if(num > 0){
    return 1;
  } else {
    return -1;
  }
}

void leftDrive(int speed, bool vel) {
  if(!vel) {
    left1 = speed;
    left2 = speed;
  } else {
    left1.move_velocity(speed);
    left2.move_velocity(speed);
  }
}
void rightDrive(int speed, bool vel) {
  if(!vel) {
    right1 = speed;
    right2 = speed;
  } else {
    right1.move_velocity(speed);
    right2.move_velocity(speed);
  }
}
void allDrive(int speed) {
  rightDrive(speed);
  leftDrive(speed);
}

float getGyro() {
  //scale factor
  return gyro2.get_rotation()/1.00555555556;
}


void drive_straight(float dist, int maxSpeed) {
  //float desiredTicks = ((dist / CIRCUM) * TICKS) / GEAR_RATIO;
  float desiredTicks = 49.41667 * dist;

  float kp = 0.29; //changed from 0.29
  float kd = 2.9;//3.36;
  float ki = 0.00;
  float kg = 1.5;//1.5;

  right1.tare_position();
  left1.tare_position();

  float gStart = getGyro();

  float error = desiredTicks;
  float prevError = error;

  float integral = 0;

  int time = 0;
  float offset = 0;
  while(fabs(error) > 10 || fabs(right2.get_actual_velocity()) > 10) {

    int R = right1.get_position();
    int L = left1.get_position();
    int pos = (R + L) / 2 ;

    float gyroPos = getGyro();
    offset = fabs(gyroPos - gStart) >= 0.5 ? kg* (gyroPos - gStart) : 0;
    offset = fabs(offset) > 5 ? 5 * sgn(offset) : offset;

    error = desiredTicks - pos;

    float deriv = error - prevError;
    prevError = error;

    integral = fabs(error) > 100 ? 0 : integral + error;
    integral = fabs(error) > 5000 ? 5000* sgn(integral) : integral;

    if(error == 0)
      integral = 0;

    int drive_power = kp * error  + kd * deriv + ki * integral;
    drive_power = abs(drive_power) > abs(maxSpeed) ? maxSpeed : drive_power + 10*sgn(error);

    if(fabs(right2.get_actual_velocity()) < 5) {
      time++;
    }

    if(time > 50) {
      break;
    }

    rightSlew(drive_power + offset); //+ offset);
    leftSlew(drive_power - offset); //- offset);

    std::printf("D: %f \n", deriv);
    delay(20);
  }
  lcd::print(4, "Err: +%f", desiredTicks - right1.get_position());
  rightSlew(0);
  leftSlew(0);
  delay(50);
}


void drive_turn(float degs, int maxSpeed) {
  float kp = 3.8;//3.5;
  float kd = 13;//13.3;
  float ki = 0.1;//1;

  //float start = getGyro();
  float error = degs - getGyro();
  float prevError = 0;
  float deriv = error;

  int time = 0;

  float integral = 0;
  while(fabs(error) > 0.5 || fabs(right2.get_actual_velocity()) > 10) {
    error = degs - getGyro();

    deriv = error - prevError;
    prevError = error;

    integral = fabs(error) < 10 ? integral + error : 0;
    integral = fabs(integral) > 500 ? 500 * sgn(integral) : integral;

    if(fabs(error) <= 0.1)
      integral = 0;

    int drive_power = (error * kp) + (kd * deriv) + (ki * integral);
    drive_power = abs(drive_power) > abs(maxSpeed) ? sgn(error)* abs(maxSpeed) : drive_power + 10*sgn(error);

    if(fabs(right2.get_actual_velocity()) < 10) {
      time++;
    }

    if(time > 100) {
      break;
    }

    //lcd::print(4,"deriv %f", deriv);

    rightSlew(-drive_power);
    leftSlew(drive_power);
    delay(20);
  }
  rightSlew(0);
  leftSlew(0);
  delay(50);
}
