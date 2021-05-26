#include "main.h"
using namespace pros;

extern pros::Motor right1;
extern pros::Motor right2;
extern pros::Motor left1;
extern pros::Motor left2;
extern pros::Motor rollerR;
extern pros::Motor rollerL;
extern pros::Motor intakeU;
extern pros::Motor intakeD;

extern pros::Controller master;

extern pros::Imu gyro1;
extern pros::Imu gyro2;
extern float getGyro();

extern void rightDrive(int speed, bool vel = false);
extern void leftDrive(int speed, bool vel = false);
extern void allDrive(int speed);

extern void rightSlew(int target);
extern void leftSlew(int target);

extern int getPos();

extern void drive_straight(float dist, int maxSpeed);
extern void drive_turn(float dist, int maxSpeed);

extern void setIntake(int speed);
extern void setRoller(int speed);

extern void skills1();
extern void skills2();

extern void driveTask(void* params);
extern void turnTask(void* params);

extern int sgn(float num);

extern std::shared_ptr<okapi::ChassisController> driveTrain;
extern std::shared_ptr<okapi::AsyncMotionProfileController> profileController;
extern void pathFollow();
