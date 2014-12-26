#include "TeleopDrive.h"

TeleopDrive::TeleopDrive() {
	// Use requires() here to declare subsystem dependencies
	Requires(drivetrain);
}

// Called just before this Command runs the first time
void TeleopDrive::Initialize() {
	// we would need to read the drive mode from the smart dashboard
	int DriveMode = StandardTankMode;
}

// Called repeatedly when this Command is scheduled to run
void TeleopDrive::Execute() {
	if (DriveMode == StandardTankMode){
		drivetrain->StandardTankDrive(oi->left_drive_joystick->GetX(), oi->right_drive_joystick->GetX());
	}
	else if (DriveMode == MecanumTankMode){
		drivetrain->MecanumTankDrive(oi->left_drive_joystick->GetX(), oi->left_drive_joystick->GetY(), oi->right_drive_joystick->GetX(), oi->right_drive_joystick->GetY());
	}
	else if (DriveMode == ThreeAxisMode){
		drivetrain->ThreeAxisDrive(oi->three_axis_joystick->GetY(), oi->three_axis_joystick->GetX(), oi->three_axis_joystick->GetTwist());
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TeleopDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleopDrive::End() {
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleopDrive::Interrupted() {
	drivetrain->Stop();
}
