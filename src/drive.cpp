#include "main.h"
void op_intake() {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        intake.move(127);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        intake.move(-127);
    }
    else {
        intake.move(0);
    }
}

void op_drive() {
        double power = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        double turn =  0.9 * master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
        double turnadditional = 0.2 * master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        double leftactual = power + turn + turnadditional;
        double rightactual = power - turn - turnadditional;

    DLF.move(leftactual);
    DLB.move(leftactual);
    DLBB.move(leftactual);
    DRF.move(rightactual);
    DRB.move(rightactual);
    DLM.move(leftactual);
    DRM.move(rightactual);
    DRBB.move(rightactual);
}

//int leftwings = 0;
//int rightwings = 0;
void wings(){
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        frontwings.set_value(true);
    }
    else{
        frontwings.set_value(false);
    }
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){
        backwings.set_value(true);
    }
    else{
        backwings.set_value(false);
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
void hangfunc(){
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
        hang.set_value(true);
    }
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){
        hang.set_value(false);
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
