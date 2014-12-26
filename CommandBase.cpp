#include "CommandBase.h"
#include "Subsystems/DriveTrain.h"
//#include "Commands/Scheduler.h" this file does not appear to exist, so i commented out the include, -ktk

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
DriveTrain* CommandBase::drivetrain = NULL;
OI* CommandBase::oi = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	drivetrain = new DriveTrain();
	
	oi = new OI();
}
