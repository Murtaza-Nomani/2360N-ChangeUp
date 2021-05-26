#include "global.h"

void skills1() {
  right1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  right2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  left1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  left2.set_brake_mode(E_MOTOR_BRAKE_HOLD);

  intakeD= -60;
  delay(100);
  intakeU = -70;
  delay(2000);
  setIntake(0);
  delay(500);

  setRoller(120);
  intakeD = 120;
  drive_straight(20,60);
  drive_turn(-26,-60);
  delay(300);
  setRoller(0);
  intakeD = 0;

  drive_straight(36.5,60);
  drive_turn(-90,-50);
  delay(300);
  rightDrive(70);
  leftDrive(70);
  delay(700);
  rightDrive(0);
  leftDrive(0);
  setIntake(120);
  delay(1000);
  setIntake(0);
  delay(300);

  drive_straight(-7.5,-60);
  delay(300);
  drive_turn(89,50);
  setRoller(120);
  intakeD = 120;
  drive_straight(12,50);
  drive_straight(37.5,60);
  delay(400);
  setRoller(0);
  intakeD = 0;

  drive_turn(-45,-60);
  delay(200);
  rightDrive(70);
  leftDrive(70);
  delay(1000);
  rightDrive(0);
  leftDrive(0);
  setIntake(120);
  delay(1000);
  setIntake(0);

  drive_straight(-13,-60);
  delay(200);
  drive_turn(135,50);
  delay(300);
  setRoller(120);
  intakeD = 120;
  drive_straight(47,60);
  delay(500);
  setRoller(0);
  intakeD = 0;

  drive_turn(-90,-60);
  delay(300);
  rightDrive(70);
  leftDrive(70);
  delay(500);
  leftDrive(0);
  rightDrive(0);
  setIntake(120);
  delay(700);
  setIntake(0);
}

void skills2() {
  setRoller(-120);
  delay(700);

  //drive into first ball and turn towards the goal
  int start = -33;
  setRoller(120);
  intakeD = 120;
  drive_straight(18,120);
  drive_turn(-32,-120);

  //drive to middle goal and score
  drive_straight(38,100);
  drive_turn(-90+start,120);
  setRoller(0);
  drive_straight(9,120);
  intakeD = 0;
  setIntake(120);
  delay(700);
  setIntake(0);

  //back up, then drive to corner and score
  drive_straight(-9,-120);
  drive_turn(0+ start,120);
  setRoller(120);
  intakeD = 120;
  drive_straight(52,100);
  drive_turn(-45+start,120);
  setRoller(0);
  drive_straight(14,120);
  intakeD = 0;
  setIntake(120);
  delay(500);
  setIntake(0);

  //back up, then drive to second middle goal
  drive_straight(-14,-120);
  drive_turn(-90+start,120);
  setRoller(120);
  intakeD = 120;
  drive_straight(-52,-90);
  drive_turn(0+start, 120);
  drive_straight(8,120);
  setRoller(0);
  intakeD = 0;
  setIntake(120);
  delay(500);
  setIntake(0);


  //back up, intake ball and then score on the second corner
  drive_straight(-17,-100);
  drive_turn(-90+start, 120);
  setRoller(120);
  intakeD = 120;
  drive_straight(-40,-120);
  drive_straight(7,120);
  drive_turn(90-45+start,120);
  setRoller(0);
  intakeD = 0;
    //this is the drive straight that goes into the goal
  drive_straight(32,120);
  setIntake(120);
  delay(500);
  setIntake(0);

  /*setRoller(120);
  intakeD = 120;
  drive_straight(-36,-100);
  drive_turn(47+start, 120);
    //this is the drive straight that goes into the goal
  setRoller(0);
  intakeD = 0;
  drive_straight(68,120);
  setIntake(120);
  delay(500);
  setIntake(0);*/

  //Score on the middle goal w the whack ball
  drive_straight(-48.5,-120);
  drive_turn(180+start,120);
  setRoller(120);
  intakeD = 120;
  drive_straight(20,120);
  drive_turn(90+start, 120);
  setRoller(0);
  intakeD = 0;
  //this is the drive straight that goes into the goal
  drive_straight(31,120);
  setIntake(120);
  delay(500);
  setIntake(0);

  //Score on last corner
  drive_straight(-7,-120);
  drive_turn(180+start,120);
  setRoller(120);
  intakeD = 120;
  drive_straight(48,120);
  drive_turn(180-45+start,120);
  setRoller(0);
  intakeD = 0;
  //this is the drive straight that goes into the goal
  drive_straight(12,120);
  setIntake(120);
  delay(500);
  setIntake(0);

  //do shit
  drive_straight(-12,-120);
  drive_turn(-62+start,-120);
  setRoller(120);
  intakeD = 120;
  drive_straight(51,120);
  drive_turn(0+start,120);
  setRoller(0);
  intakeD = 0;

  //End drive
  allDrive(120);
  delay(600);
  allDrive(0);

  //End shot
  setIntake(120);
  delay(1000);
  setIntake(0);
  //Score on last middle goal
  /*drive_straight(-13,-100);
  drive_turn(-90+start,100);
  setRoller(120);
  intakeD = 120;
  drive_straight(48,100);
  drive_turn(180+start,100);
  setRoller(0);
  intakeD = 0;
  drive_straight(6.5,100);
  setIntake(120);
  delay(500);
  setRoller(0*/
}

void drive_time(int speed, int time) {
  allDrive(speed);
  delay(time);
  allDrive(0);
}
