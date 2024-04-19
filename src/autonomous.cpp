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
    cata1.move(127);
    chassis.calibrate();
    backwings.set_value(true);
    chassis.setPose(-56, -51, 36);
    pros::delay(2000);
    backwings.set_value(false);
    pros::delay(28000);
    cata1.move(0);
    chassis.turnTo(-110, -24, 1000, true);
    chassis.moveTo(-110, -24, 1000);
}
void auton_far(){
    drive(-120, 3000);
}
void auton_far_six() {
    chassis.calibrate();
    intake.move(80);
    pros::delay(655);
    intake.move(-127);
    chassis.moveTo(0, 12, 1000);
    chassis.moveTo(-24, 45, 1000);
    chassis.turnTo(0, 45, 1000, false);
    frontwings.set_value(true);
    intake.move(127);
    chassis.moveTo(10, 45, 1000);
    frontwings.set_value(false);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(3, -10, 500);
    chassis.setPose(0, 0, 270);
    intake.move(-127);
    chassis.turnTo(47, 23, 1000, false);
    chassis.setPose(0, 0, 0);
    intake.move(-127);
    chassis.moveTo(0, 18, 1000);
    chassis.turnTo(-46, 24, 1000, true);
    chassis.moveTo(-46, 24, 1000);
    chassis.turnTo(-46, 30, 1000, false);
//    chassis.setPose(0, 0, 180);
//    chassis.turnTo(36, 13, 1000, false);

    pros::delay(4000);

}
void close_auton_disrupt(){
    chassis.calibrate();
    intake.move(80);
    pros::delay(655);
    intake.move(-127);
    chassis.moveTo(5, 47, 1500);
    chassis.moveTo(-5, -3, 1000);
    chassis.setPose(0, 0, 0);
    chassis.turnTo(24, 0, 1000);
    intake.move(127);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(0, -3.5, 500);
    pros::delay(700);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(-18, -18, 1000, 90);
    frontwings.set_value(true);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(0, 5, 850);
    chassis.setPose(0, 0, 0);
    chassis.turnTo(-19, 24, 1000);
    frontwings.set_value(false);
    chassis.setPose(0, 0, 45);
    intake.move(127);
    chassis.moveTo(25, 27, 1500, 80);
    drive(0, 1000);

    pros::delay(5001);

    //    chassis.setPose(0, 0, 0);
//    chassis.moveTo(-20, -46, 1500);
}
void close_auton_winpoint(){
}
