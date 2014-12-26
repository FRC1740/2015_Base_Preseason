#include "OI.h"

OI::OI() { // maybe rename these based on what port they are plugged in to?
	left_drive_joystick = new Joystick(1);
	right_drive_joystick = new Joystick(2);
	three_axis_joystick = new Joystick(3);
}
