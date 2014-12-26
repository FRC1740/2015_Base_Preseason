#include "DriveTrain.h"
#include "../Robotmap.h"
#include "math.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
	front_right_motor = new Victor(front_right_motor_port);
	front_left_motor = new Victor(front_left_motor_port);
	rear_right_motor = new Victor(rear_right_motor_port);
	rear_left_motor = new Victor(rear_left_motor_port);
	
}
    
void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
//	SetDefaultCommand(new MySpecialCommand());
	//Create all sorts of drive methods and then set the default command accordingly

}
float DriveTrain::Square(float input){ // there might be a better way to do this, input squared method that is shared between all drive classes
	// maybe grab value from smart dash in the future, currently squared is in header file, or use a settings file....
	bool Squared = true;
	return pow(input, Squared + 1) * ((input > 0) - (input < 0));  // one line sign preserving square!
}
// NOTE: STANDARD: high grip wheels
void DriveTrain::StandardTankDrive(float input_left, float input_right){
	front_left_motor->Set(this->Square(input_left));  // note in the tutorial video he uses SetSpeed(float) instead, not sure what the difference is
	rear_left_motor->Set(this->Square(input_left));
	front_right_motor->Set(this->Square(input_right));
	rear_right_motor->Set(this->Square(input_right));
}
void DriveTrain::MecanumTankDrive(float input_left_x, float input_left_y, float input_right_x, float input_right_y){
	front_right_motor->Set(this->Square(input_right_y) + this->Square(input_right_x));
	rear_right_motor->Set(this->Square(input_right_y) - this->Square(input_right_x));
	front_left_motor->Set(-1 * (this->Square(input_left_y) - input_left_x));
	rear_left_motor->Set(-1 * (this->Square(input_left_y) + this->Square(input_left_x)));
}
void DriveTrain::ThreeAxisDrive(float input_y, float input_x, float input_twist){
	front_right_motor->Set(this->Square(input_y) + this->Square(input_x) + this->Square(input_twist));
	rear_right_motor->Set(this->Square(input_y) - this->Square(input_x) + this->Square(input_twist));
	front_left_motor->Set(-1 * (this->Square(input_y) - this->Square(input_x) - this->Square(input_twist)));
	rear_left_motor->Set(-1 * (this->Square(input_y) + this->Square(input_x) - this->Square(input_twist)));
}
void DriveTrain::Stop(){
	front_right_motor->Set(0);
	front_left_motor->Set(0);
	rear_right_motor->Set(0);
	rear_left_motor->Set(0);
}
		



