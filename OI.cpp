#include "OI.h"

OI::OI() {
	left_drive_joystick = new Joystick(1);
	right_drive_joystick = new Joystick(2);
}
