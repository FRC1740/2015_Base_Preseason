#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/TeleopDrive.h"
#include "CommandBase.h"

/* 
 *	Team 1740
 *	2015 Code
 *	Programming Staff:
 *	Lord Kevin "Hjax" Konrad: High Overlord of Programming and Python / C++ grand master
 *	Sire Henry Crain: Majordomo of Programming and Python / C++ master
 *	Lady Allison "armadillokake" Konrad: Queen of the Armadillos and C++ n00b
 *	Sir Jonathan Lei: Python / C++ dude
 *	Our Lord, Charles Estabrooks: Programming God and C / C++ savior
 *	Brian Healy the Eternal Champion: Programming God and Labview / TI-89 grand master
 */

class CommandBasedRobot : public IterativeRobot {
private:
//	Command *autonomousCommand;
	Command *TeleopCommand;
	LiveWindow *lw;
	
	virtual void RobotInit() {
		CommandBase::init();
//		autonomousCommand = new ExampleCommand();
//		TeleopCommand = new TeleopDrive();
		lw = LiveWindow::GetInstance();
	}
	
	virtual void AutonomousInit() {
//		autonomousCommand->Start();
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
//		autonomousCommand->Cancel();
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

