#include "main.h"
void op_intake() {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        intake.move(127);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        intake.move(-127);
    }
    else {
        intake.move(0);
    }
}
void op_drive() {
        double power = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        double turn = 0.88 * master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
        double leftactual = power + turn;
        double rightactual = power - turn;

        DLF.move(leftactual);
        DLB.move(leftactual);
        DRF.move(rightactual);
        DRB.move(rightactual);
        DLM.move(leftactual);
        DRM.move(rightactual);
}


void intakepiston() {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        wingspistons.set_value(true);
    }
    else{
        wingspistons.set_value(false);
    }
}
void blocker(){
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)){
        blockerpiston.set_value(true);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
        blockerpiston.set_value(false);
    }
}
int expansioncount = 0;
//void intakeexpansionmodel(){
//    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
//        intakeexpansion.move(127);
//        intakeexpansion2.move(127);
//    }
//    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
//        intakeexpansion.move(-127);
//        intakeexpansion2.move(-127);
//    }
//}
//bool primed = true
bool catacount = false;
void catapult(){
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        catacount = true;
//        cata2.move(115);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){
        catacount = false;
    }
    if(catacount){
        cata1.move(127);
    }
    else{
        cata1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        cata2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        cata1.brake();
        cata2.brake();
        }
    }
        //        primed = false;
        //    }
        //    if (not primed){
        //        cata1.move_velocity(50);
        //        cata2.move_velocity(50);
        //        pros::delay(100);
        //        if(!catabumper.get_value()) {
        //            cata1.move_velocity(50);
        //            cata2.move_velocity(50);
        //        }
        //        else {
        //            cata1.move_relative(0, 0);
        //            cata2.move_relative(0, 0);
        //            primed = true;
        //        }
        //    }
        //    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        //        cata1.move(127);
        //        cata1.move(127);
        //        pros::delay(200);
        //        cata1.move(0);
        //        cata2.move(0);
        //    }
        //    else{
        //        if (catabumper.get_value()){
        //            cata1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        //            cata2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        //            cata1.brake();
        //            cata2.brake();
        //        }
        //        cata1.move(90);
        //        cata2.move(90);
        //    }
