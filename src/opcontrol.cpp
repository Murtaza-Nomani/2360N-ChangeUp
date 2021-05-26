#include "global.h"

void opcontrol() {
	//pathFollow();
	while(1) {
		int left = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
		int right = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);

	  rightDrive(left - right);
		leftDrive(left + right);

		/*if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) {
			rollerR = 127;
			rollerL = 127;
      intakeD = 127;
		} else if(master.get_digital(E_CONTROLLER_DIGITAL_L2)) {
			rollerR = -120;
			rollerL = -120;
		} else if(!(master.get_digital(E_CONTROLLER_DIGITAL_R1) || master.get_digital(E_CONTROLLER_DIGITAL_R2))) {
      intakeD = 0;
			intakeU = 0;
			rollerR = 0;
			rollerL = 0;
    } else {
      rollerR = 0;
      rollerL = 0;
    }

		if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) {
			intakeU = 127;
			intakeD = 127;
		} else if(master.get_digital(E_CONTROLLER_DIGITAL_R2)) {
			intakeU = -120;
			intakeD = -120;
		} else if(!(master.get_digital(E_CONTROLLER_DIGITAL_L1) || master.get_digital(E_CONTROLLER_DIGITAL_L2))) {
      intakeU = 0;
      intakeD = 0;
    } else {
      intakeU = 0;
    }*/


		if(master.get_digital(E_CONTROLLER_DIGITAL_L1)) {
			setRoller(127);
			intakeD = 127;
		} else if(master.get_digital(E_CONTROLLER_DIGITAL_L2)) {
			setRoller(-120);
			intakeD = -120;
		} else if(!(master.get_digital(E_CONTROLLER_DIGITAL_R1) || master.get_digital(E_CONTROLLER_DIGITAL_R2))) {
			setRoller(0);
			setIntake(0);
		} else {
			setRoller(0);
		}

    if(master.get_digital(E_CONTROLLER_DIGITAL_R1)) {
      setIntake(127);
    } else if(master.get_digital(E_CONTROLLER_DIGITAL_R2)) {
      setIntake(-120);
    } else if(!(master.get_digital(E_CONTROLLER_DIGITAL_L1) || master.get_digital(E_CONTROLLER_DIGITAL_L2))) {
      setIntake(0);
    } else {
			intakeU = 0;
		}

		if(master.get_digital(E_CONTROLLER_DIGITAL_B)) {
			setRoller(-120);
		}

		if(master.get_digital(E_CONTROLLER_DIGITAL_UP)) {
			//autonomous();
		}

		//lcd::print(2,"R: %f", right1.get_position());
		//lcd::print(3,"L: %f", left1.get_position());

		lcd::print(2,"IMU: %f", gyro2.get_rotation());
		lcd::print(1,"Right: %d", right);

  	/*if(master.get_digital(E_CONTROLLER_DIGITAL_X)) {
  		intakeD= -70;
  	  delay(100);
  	  intakeU = -120;
  	  delay(700);
  	  setIntake(0);
  	}

  	if(master.get_digital(E_CONTROLLER_DIGITAL_UP)) {
  		setIntake(-70);
  		setRoller(-70);
  	}*/

  	pros::delay(10);
  }
}
