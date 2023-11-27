#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor DRM(5, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor cata2(4, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor cata1(4, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
//pros::Motor_Group left_side_motors({DLF, DLB});
//pros::Motor_Group right_side_motors({DRF, DRB});
//pros::Motor_Group catapult_motor({cata1, cata2});
pros::Motor DRF(13, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intake(3, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DRB(14, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DLF(7, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DLB(15, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DLM(9, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
//pros::Motor intakeexpansion(11, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
//pros::Motor intakeexpansion2(5, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::ADIDigitalIn catabumper (2);
pros::ADIDigitalOut wingspistons (8);
pros::ADIDigitalOut blockerpiston(7);
pros::Imu imu_sensor(8);
