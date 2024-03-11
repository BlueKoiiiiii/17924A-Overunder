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
    leftwings.set_value(true);
    chassis.setPose(-56, -51, 36);
    pros::delay(2000);
    leftwings.set_value(false);
    pros::delay(28000);
    cata1.move(0);
    chassis.turnTo(-110, -24, 1000, true);
    chassis.moveTo(-110, -24, 1000);
}
void auton_far(){
    drive(-120, 3000);
}
void auton_far_six() {
//    chassis.calibrate();
    intake.move(-127);
    chassis.setPose(18, -58, 270);
    chassis.moveTo(10, -58, 800, 80);
    chassis.moveTo(42, -58, 800, 80);
    rightwings.set_value(true);
    chassis.moveTo(59, -45, 800, 80);
//    pros::delay(100);
    rightwings.set_value(false);
//    pros::delay(200);
    chassis.moveTo(67, -21, 800);
    chassis.moveTo(67, -33, 800);
//    chassis.moveTo(67, -21, 8000);
//    chassis.moveTo(67, -40, 800);
    chassis.turnTo(67, 0, 1000, false);
    chassis.moveTo(67, 0, 1000);
//    drive(-120, 300);
//    drive(120, 500);
    chassis.setPose(65, -24, 0);
    chassis.moveTo(65, -39, 1000);
    chassis.moveTo(10, -20, 3000, 70);
    chassis.turnTo(47, 0, 1000);
    intake.move(127);
    pros::delay(500);
    intake.move(-127);
    chassis.moveTo(5, -5, 1000);
//    pros::delay(300);
    chassis.turnTo(60, -10, 1000, true);
//    leftwings.set_value(true);
    rightwings.set_value(true);
    chassis.moveTo(60, -10, 1000);
    chassis.moveTo(25, -10, 1000);
    chassis.turnTo(60, -10, 1000, false);
    leftwings.set_value(false);
    rightwings.set_value(false);
    chassis.moveTo(60, -10, 1000);
    drive(0, 1000);
}
void close_auton_disrupt(){
//    chassis.calibrate();
//    leftwings.set_value(true);
//    pros::delay(500);
//    leftwings.set_value(false);
//    chassis.setPose(0, 0, 0);
    intake.move(-127);
    intake2.move(-127);
    chassis.moveTo(0, 15, 850, 120);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(6, 18, 1000, 80);
    chassis.turnTo(6, 47, 500);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(0, 1, 500, 50);
    pros::delay(400);
    chassis.setPose(6, 18, 0);
    chassis.moveTo(0, 15, 1000);
    chassis.moveTo(0, 0, 500);
    intake.move(0);
    chassis.moveTo(0, -15, 600, 50);
    drive(-45, 2000);
    chassis.setPose(0, 0, 0);
//    drive(80, 50);
    chassis.turnTo(-24, 16, 1000, false);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(0, 9, 600, 80);

    chassis.setPose(0, 0, 180);
    chassis.turnTo(12, 24, 600, true);
    chassis.setPose(0, 0, 0);
    rightwings.set_value(true);
    chassis.moveTo(0, -4, 1000, 60);
    chassis.setPose(0, 0, 315);
    chassis.turnTo(46, 0, 500, true);
    rightwings.set_value(false);
//    pros::delay(500);
    chassis.turnTo(24, 24, 1000, false);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(0, -24, 200, 80);
    drive(-60, 700);
    chassis.setPose(0, 0, 45);
    drive(60, 100);
    chassis.turnTo(12, -12, 500, false);
//    leftwings.set_value(true);
    drive(60, 600);
    chassis.setPose(0, 0, 135);
    intake.move(127);
    chassis.turnTo(48, 0, 500, false);
//    leftwings.set_value(false);
    chassis.setPose(0, 0, 90);
    chassis.moveTo(13, 0, 1500, 110);
    drive(0, 1000);
    //    chassis.setPose(0, 0, 0);
//    chassis.moveTo(-20, -46, 1500);
}
void close_auton_winpoint(){
    chassis.calibrate();
    chassis.setPose(0, 0, 90);
    chassis.moveTo(12, 0, 500, 80);
    rightwings.set_value(true);
    chassis.moveTo(5, 0, 500, 80);
    chassis.setPose(0, 0, 315);
    chassis.turnTo(46, 0, 500, true);
    rightwings.set_value(false);
    pros::delay(500);
    chassis.turnTo(24, 24, 1000, false);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(0, -24, 1000, 80);
    drive(-70, 700);
    chassis.setPose(0, 0, 45);
    drive(60, 100);
    chassis.turnTo(12, -12, 500, false);
    drive(60, 600);
    chassis.setPose(0, 0, 135);
    intake.move(127);
    chassis.turnTo(48, 0, 500, false);
    chassis.setPose(0, 0, 90);
    chassis.moveTo(16, 0, 1500, 70);
}
void skills(){
    cata1.move_velocity(60);
    pros::delay(25000);
    chassis.calibrate();
    cata1.move(0);
    chassis.setPose(0, 0, 0);
    chassis.turnTo(-13, 11, 500, false);
    drive(-60, 800);
    chassis.setPose(0, 0, 45);
    chassis.moveTo(24, -2, 1000);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(-1, 30, 2000, 90);
    chassis.setPose(0, 0, 90);
    intake.move(127);
    chassis.moveTo(22, 26, 1000, 80);
    chassis.moveTo(22, 48, 1000);
    drive(-90, 200);
    drive(120, 500);
    drive(-80, 100);
    chassis.setPose(0, 0, 0);
    chassis.turnTo(24, 0, 600, true);
    chassis.moveTo(24, 0, 500);
    drive(-80, 800);
    //wall resetted
    chassis.setPose(0, 0, 270);
    intake.move(-127);
    chassis.moveTo(-49, 6, 1000);
    chassis.turnTo(0, 24, 1000, false);
    chassis.setPose(0, 0, 0);
    leftwings.set_value(true);
    intake.move(127);
    chassis.moveTo(0, 44, 1000, 80);
    drive(120, 800);
    //first push done
    leftwings.set_value(false);
    drive(-80, 2500);
    chassis.setPose(0, 0, 0);
    leftwings.set_value(true);
    chassis.moveTo(-5, 47, 1000, 80);
    drive(120, 800);
    leftwings.set_value(false);
    drive(-80, 2000);
    drive(80, 100);
    chassis.setPose(0, 0, 90);
    chassis.turnTo(0, 47, 1000, true);
    drive(-80, 2000);
    chassis.setPose(0, 0, 180);
    chassis.turnTo(46, 0, 2000);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(0, -47, 3000, 80);
    chassis.setPose(0, 0, 0);
    chassis.turnTo(-48, 0, 1000, true);
    drive(-128, 1000);
    intake.move(-127);
    chassis.setPose(0, 0, 0);
    chassis.moveTo(-36, 36, 1000);
    chassis.turnTo(-60, 36, 1000);
    hang.set_value(true);
    drive(120, 3000);
    hang.set_value(false);







//    chassis.turnTo()



}