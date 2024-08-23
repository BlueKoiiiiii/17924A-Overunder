//
// Created by Daniel on 2023-10-29.
//

#include "../include/autonomous.h"
#include "main.h"
#include "lemlib/api.hpp"
void drive(int speed, int time) {
    DLF.move(speed);
    DLB.move(speed);
    DLM.move(speed);
    DRF.move(speed);
    DRB.move(speed);
    DRM.move(speed);
    pros::delay(time);
    DLF.move(0);
    DLB.move(0);
    DLM.move(0);
    DRF.move(0);
    DRB.move(0);
    DRM.move(0);
}
void driverskills(){
    frontwings.set_value(true);
    intake.move(80);
    pros::delay(200);
    intake.move(-127);
    frontwings.set_value(false);
    chassis.moveTo(5, 45, 1400);
    pros::delay(200);
    chassis.moveTo(-5, -3, 1000);
    chassis.setPose(0, 0, 0);
    chassis.turnTo(24, 0, 1000);
    intake.move(127);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(-5, -10, 800);
    backwings.set_value(true);
    intake.move(127);
    pros::delay(8000);
    backwings.set_value(false);
    frontwings.set_value(true);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(-2, 35, 1500, 80);
    frontwings.set_value(false);
    chassis.moveTo(0, 0, 1000, 80);
    backwings.set_value(true);
    intake.move(127);
    pros::delay(8000);
    backwings.set_value(false);
    frontwings.set_value(true);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(-2, 35, 1500, 80);
    frontwings.set_value(false);
    chassis.moveTo(0, 0, 1000, 80);
    backwings.set_value(true);
    intake.move(127);
    pros::delay(8000);
    backwings.set_value(false);
    frontwings.set_value(true);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(-2, 35, 1500, 80);
    frontwings.set_value(false);
    chassis.moveTo(0, 0, 1000, 80);
    backwings.set_value(true);


}
void auton_far(){
    drive(-120, 3000);
}
void auton_far_six() {
//    chassis.calibrate();
    frontwings.set_value(true);
    intake.move(80);
    pros::delay(500);
    intake.move(-127);
    frontwings.set_value(false);
    chassis.moveTo(0, 12, 1000);
    chassis.moveTo(-24, 48, 1000);
    chassis.turnTo(0, 60, 1000, false);
    frontwings.set_value(true);
    intake.move(127);
    chassis.moveTo(10, 45, 1000);
    frontwings.set_value(false);
    drive(-127, 400);
    drive(127, 800);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(0, -6, 800);
    chassis.turnTo(35, -12, 800, true);
    chassis.moveTo(60, -12, 1500);
    intake.move(-127);
    chassis.setPose(0, 0, 90);
    chassis.turnTo(5, 26, 1000, false);
    chassis.moveTo(5, 26, 1000);
    chassis.moveTo(0, -5, 1000);
    chassis.setPose(0, 0, 0);
    backwings.set_value(true);
    chassis.moveTo(4, -12, 800);
    chassis.turnTo(24, -24, 800, true);
    backwings.set_value(false);
    chassis.setPose(0, 0, 0);
    chassis.turnTo(-6, -14, 800, false);
    intake.move(127);
    drive(120, 800);
    drive(-120, 300);
    drive(120, 800);
//    chassis.setPose(0, 0, 180);
//    chassis.turnTo(36, 13, 1000, false);

    pros::delay(4000);

}



void close_auton_disrupt(){
//    chassis.calibrate();
    frontwings.set_value(true);
    intake.move(80);
    pros::delay(200);
    intake.move(-127);
    frontwings.set_value(false);
    chassis.moveTo(5, 45, 1400);
    pros::delay(200);
    chassis.moveTo(-5, -3, 1000);
    chassis.setPose(0, 0, 0);
    chassis.turnTo(24, 0, 1000);
    intake.move(127);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(0, -2.5, 500);
    pros::delay(700);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(-15, -15, 1000, 90);
    frontwings.set_value(true);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(0, 5, 850);
    chassis.setPose(0, 0, 0);
    chassis.turnTo(-19, 24, 2000);
    frontwings.set_value(false);
    chassis.setPose(0, 0, 0);
    intake.move(127);
    chassis.moveTo(-5, 40, 1500, 80);
    frontwings.set_value(true);
    pros::delay(300);
    frontwings.set_value(false);

    pros::delay(5001);

    //    chassis.setPose(0, 0, 0);
//    chassis.moveTo(-20, -46, 1500);
}
void close_auton_winpoint(){
}
