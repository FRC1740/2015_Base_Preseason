#ifndef OI_H
#define OI_H

#include "WPILib.h"

// currently set up for 2 joystick tank, add more features later!


class OI {
private:

public:
	OI();
	Joystick *left_drive_joystick;
	Joystick *right_drive_joystick;
	Joystick *three_axis_joystick;

};

#endif
