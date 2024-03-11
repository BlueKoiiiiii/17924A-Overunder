#include "main.h"
#include "autoSelect/selection.h"
#include "lemlib/api.hpp"
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    chassis.calibrate();
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
    selector::init();
	pros::lcd::register_btn1_cb(on_center_button);
//    chassis.calibrate();
//    intake.move(127);
//    chassis.setPose(-35, -59, 90);
//    chassis.moveTo(0, -59, 1000);
//    chassis.follow("asd.txt", 4000, 15);c
//    chassis.turnTo(30, 0, 10000);
//    chassis.moveTo(0, 20, 10000);

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    if (selector::auton == -1) {
//        chassis.calibrate();
        skills();
//        auton_far_six();
//        close_auton_disrupt();
    }
    if(selector::auton == 2){
//        chassis.calibrate();
        auton_far_six();
    }
    if(selector::auton == 3){
    }
    if(selector::auton == 1){
        intake.move(127);
        intake2.move(127);
        chassis.setPose(0, 0, 0);
        chassis.moveTo(0, 47, 1000);
        drive(-80, 300);
        chassis.setPose(0, 0, 0);
        chassis.moveTo(0, 47, 1000);
        chassis.setPose(-59, -23, 0);
        chassis.moveTo(-59, -34, 900, 70);
        chassis.turnTo(47, 7, 1000, false);
        drive(-60, 1000);
        chassis.turnTo(47, -2, 700, false);
        cata1.move_velocity(65);
        drive(-20, 700);
        pros::delay(27000);
        cata1.move(0);

        drive(60, 200);
        chassis.setPose(-61, -47, 35);
        chassis.moveTo(-50, -49, 1000);
        chassis.moveTo(18, -20, 1000, 90);
        chassis.moveTo(18, -15, 1000, 80);
        chassis.setPose(36, -51, 90);
        chassis.moveTo(60, -39, 1000);
        chassis.moveTo(59, -23, 1000);
        drive(-80, 300);
        chassis.moveTo(59, -10, 1000);
        drive(-80, 200);
        chassis.setPose(62, -30, 0);
        chassis.turnTo(12, -28, 1000, true);
        chassis.moveTo(9, -28, 1000);
        chassis.turnTo(47, -18, 1000, false);
        chassis.moveTo(47, -18, 1000);
        drive(-80, 300);
        drive(120, 1000);
        chassis.moveTo(0, -6, 1000, 70);
        leftwings.set_value(true);
        chassis.moveTo(47, -7, 1000);
        drive(-80, 300);
        drive(120, 1000);
        leftwings.set_value(false);
        chassis.moveTo(0, 0, 1000, 70);
        chassis.moveTo(54, 30, 1000);
        chassis.turnTo(61, 1, 1000, false);
        chassis.moveTo(61, 1, 1000);
        chassis.turnTo(57. -6, 1000, false);
        drive(-80, 200);
        drive(120, 1000);
        drive(-80, 200);
        drive(120, 1000);
//        chassis.moveTo(63, -8, 2000);


//        chassis.moveTo()
//        skills();
//        close_auton_disrupt();
//        close_auton_winpoint();
//        void auton_far();
    }
//    if(selector::auton == -2){
//    //redautonomous
//    }
//    if(selector::auton == -3){
//    //redautonomous
//    }
//    if(selector::auton == 0){
//    //redautonomous
//    }
}




/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
//    driverskills();
//    catabumper.calibrate;

	while (true) {
//        left_side.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
//        right_side.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
        op_drive();
        op_intake();
        hangfunc();
//        intakeexpansionmodel();
        catapult();
//        intakepiston();
        wings();
//    pros::?lcd::print(1, "Motor power: %f\n", catabumper.get_value());
		pros::delay(10);
	}
}
