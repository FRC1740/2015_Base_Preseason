#include "DriveTrain.h"
#include "../Robotmap.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
	front_right_motor = new Victor(front_right_motor_port);
	front_left_motor = new Victor(front_left_motor_port);
	rear_right_motor = new Victor(rear_right_motor_port);
	rear_left_motor = new Victor(rear_left_motor_port);
}
    
void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	//Create all sorts of drive methods and then set the default command accordingly

}
void DriveTrain::StandardTankDrive(float input_left, float input_right){
	front_left_motor->Set(input_left);  // note in the tutorial video he uses SetSpeed(float) instead, not sure what the difference is
	rear_left_motor->Set(input_left);
	front_right_motor->Set(input_right);
	rear_right_motor->Set(input_right);
}
void DriveTrain::MecanumTankDrive(float input_left_x, float input_left_y, float input_right_x, float input_right_y){
	front_right_motor->Set(input_right_y + input_right_x);
	rear_right_motor->Set(input_right_y - input_right_x);
	front_left_motor->Set(-1 * (input_left_y - input_left_x));
	rear_left_motor->Set(-1 * (input_left_y + input_left_x));
}


// Put methods for controlling this subsystem
// here. Call these from Commands.