#include "main.h"
#include "lemlib/api.hpp"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor DRM(5, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor cata2(4, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor cata1(4, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
//pros::Motor_Group left_side_motors({DLF, DLB});
//pros::Motor_Group right_side_motors({DRF, DRB});
//pros::Motor_Group catapult_motor({cata1, cata2});
pros::Motor DRF(13, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intake(2, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DRB(11, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DLF(7, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DLB(15, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DLM(9, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::MotorGroup left_side({DLF, DLB, DLM});
pros::MotorGroup right_side({DRF, DRB, DRM});
//pros::Motor intakeexpansion(11, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
//pros::Motor intakeexpansion2(5, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::ADIDigitalIn catabumper (2);
pros::ADIDigitalOut wingspistons (7);
pros::ADIDigitalOut blockerpiston(8);
pros::Imu imu_sensor(8);

lemlib::Drivetrain_t drivetrain{
    &left_side,
    &right_side,
    13,
    3.25,
    480
};

lemlib::OdomSensors_t sensors{
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    &imu_sensor
};

lemlib::ChassisController_t lateralController {
        8, // kP
        30, // kD
        1, // smallErrorRange
        100, // smallErrorTimeout
        3, // largeErrorRange
        500, // largeErrorTimeout
        5 // slew rate
};

lemlib::ChassisController_t angularController {
        4, // kP
        40, // kD
        1, // smallErrorRange
        100, // smallErrorTimeout
        3, // largeErrorRange
        500, // largeErrorTimeout
        0 // slew rate
};