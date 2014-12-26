#ifndef ROBOTMAP_H
#define ROBOTMAP_H


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 // drivetrain motors go here, currently set up to assume 4 motor
#define front_right_motor_port 1
#define front_left_motor_port 2
#define rear_right_motor_port 3
#define rear_left_motor_port 4

#endif
