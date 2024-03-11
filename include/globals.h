#include "main.h"
#include "lemlib/api.hpp"
extern pros::Controller master;
extern pros::Motor cata1;
extern pros::Motor cata2;
extern pros::Motor DRF;
extern pros::Motor intake;
extern pros::Motor intake2;
extern pros::Motor DRB;
extern pros::Motor DLF;
extern pros::Motor DLB;
extern pros::Motor DLM;
extern pros::Motor DRM;
extern pros::ADIDigitalIn catabumper;
extern pros::ADIDigitalOut leftwings;
extern pros::ADIDigitalOut hang;
extern pros::Imu imu_sensor;
extern pros::MotorGroup right_side;
extern pros::MotorGroup left_side;
extern lemlib::Drivetrain_t drivetrain;
extern lemlib::OdomSensors_t sensors;
extern lemlib::ChassisController_t lateralController;
extern lemlib::ChassisController_t angularController;
extern lemlib::Chassis chassis;

//extern pros::Motor_Group left_side_motors({DLF, DLB});
//extern pros::Motor_Group right_side_motors({DRF, DRB});
//extern pros::Motor_Group catapult_motor({cata1, cata2});
//extern pros::Controller master;
extern pros::ADIDigitalOut rightwings;
extern pros::Motor intakeexpansion;
extern pros::Motor intakeexpansion2;

