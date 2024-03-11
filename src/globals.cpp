#include "main.h"
#include "lemlib/api.hpp"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor DRM(1, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor cata2(4, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor cata1(4, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
//pros::Motor_Group left_side_motors({DLF, DLB});
//pros::Motor_Group right_side_motors({DRF, DRB});
//pros::Motor_Group catapult_motor({cata1, cata2});
pros::Motor DRF(9, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intake(13, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intake2(15, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DRB(11, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DLF(18, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DLB(17, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DLM(8, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::MotorGroup left_side({DLF, DLB, DLM});
pros::MotorGroup right_side({DRF, DRB, DRM});
//pros::Motor intakeexpansion(11, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
//pros::Motor intakeexpansion2(5, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::ADIDigitalOut leftwings (8);
pros::ADIDigitalOut rightwings(7);
pros::ADIDigitalOut hang(6);
pros::Imu imu_sensor(21);

lemlib::Drivetrain_t drivetrain{
    &left_side,
    &right_side,
    15,
    4,
    343
};

lemlib::OdomSensors_t sensors{
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    &imu_sensor
};

lemlib::ChassisController_t lateralController {
        20, // kP
        60, // kD
        1, // smallErrorRange
        100, // smallErrorTimeout
        3, // largeErrorRange
        500, // largeErrorTimeout
        5 // slew rate
};

lemlib::ChassisController_t angularController {
        4, // kP
        45, // kD
        1, // smallErrorRange
        100, // smallErrorTimeout
        3, // largeErrorRange
        500, // largeErrorTimeout
        0 // slew rate
};

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);