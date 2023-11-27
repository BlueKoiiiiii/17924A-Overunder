//
// Created by Daniel on 2023-10-29.
//

#include "../include/autonomous.h"
void imu_turnright(int target_angle, int speed) {
    double kp = 0.55;
    double ki = 0.065;
    double kd = 0.1;
    int lastError = 0;
//    int totalruntime = 0;
    int totalError = 0;
    int integralActiveZone = 20;
    bool runloop = true;
    imu_sensor.set_heading(4);
    int deltatime = 0;

//    imu_sensor.reset();
    while (runloop) {
        double current_angle = imu_sensor.get_heading();
        int error = target_angle - current_angle;
        double adjustment = (error * kp) + (totalError * ki) + ((error - lastError) * kd);

        if (error == 0) {
            lastError = 0;
        } else {
            lastError = error;
        }

        if (abs(error) < integralActiveZone and error != 0) {
            totalError += error;
        } else {
            totalError = 0;
        }

//        if (error > 0) {
        DLF.move(speed + adjustment);
        DRF.move(-speed - adjustment);
        DLB.move(speed + adjustment);
        DRB.move(-speed - adjustment);
        DLM.move(speed + adjustment);
        DRM.move(-speed - adjustment);
//        } else {
//            DLF.move(-speed - adjustment);
//            DRF.move(speed + adjustment);
//            DLFF.move(-speed - adjustment);
//            DLB.move(-speed - adjustment);
//            DRFF.move(speed + adjustment);
//            DRB.move(speed + adjustment);
//        }
        if (5 > error and error > -5) {
            deltatime += 1;
            speed = 0;
        }
        else{
            speed = 20;
        }

        if (deltatime > 15) {
            DRF.move(0);
            DLF.move(0);
            DRB.move(0);
            DLB.move(0);
            DLM.move(0);
            DRM.move(0);
            runloop = false;
        }
//        if (totalruntime == 150){
//            runloop = false;
//        }
//        totalruntime += 1;
        master.set_text(0, 0, std::to_string(error));
        pros::delay(10);
    }
}

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
void imu_turnleft(int target_angle, int speed) {
    double kp = 0.55;
    double ki = 0.065;
    double kd = 0.1;
    int lastError = 0;
    int totalError = 0;
    int integralActiveZone = 20;
//    int totalruntime = 0;
    bool runloop = true;
    imu_sensor.set_heading(358);
    int deltatime = 0;
//    imu_sensor.reset();
    while (runloop) {
        int current_angle = imu_sensor.get_heading();
        int error = (current_angle - target_angle);
        double adjustment = (error * kp) + (totalError * ki) + ((error - lastError) * kd);

        if (error == 0) {
            lastError = 0;
        } else {
            lastError = error;
        }

        if (abs(error) < integralActiveZone and error != 0) {
            totalError += error;
        }
        else {
            totalError = 0;
        }

//            if (error < 0) {
//                DLF.move(speed + adjustment);
//                DRF.move(-speed - adjustment);
//                DLFF.move(speed + adjustment);
//                DLB.move(speed + adjustment);
//                DRFF.move(-speed - adjustment);
//                DRB.move(-speed - adjustment);
//            } else {
        DRF.move(speed + adjustment);
        DLF.move(-speed - adjustment);
//        DLFF.move(-speed - adjustment);
        DRB.move(speed + adjustment);
//        DRF/F.move(speed + adjustment);
        DLB.move(-speed- adjustment);
        DLM.move(-speed - adjustment);
        DRM.move(speed + adjustment);
//            }

        if (5 > error and error > -5) {
            deltatime += 1;
            speed = 0;
        }
        else{
            speed = 20;
        }

        if (deltatime > 15) {
            DLF.move(0);
            DRF.move(0);
            DRM.move(0);
            DLM.move(0);
//            DLFF.move(0);
            DLB.move(0);
//            DRFF.move(0);
            DRB.move(0);
            runloop = false;
        }
//        if (totalruntime == 150){
//            runloop = false;
//        }
//        totalruntime += 1;
        master.set_text(0, 0, std::to_string(error));
        pros::delay(10);
    }
}
void farauton(){
    imu_sensor.reset(true);
    imu_turnleft(315, 50);
    drive(127, 650);
    imu_turnright(45, 50);
    intake.move(-127);
    pros::delay(600);
    drive(-90, 100);
    //triball has left the intake
    imu_turnright(175, 50);
    intake.move(0);
    drive(-120, 550);
    pros::delay(550);
    //triball pushed in goal
    drive(90, 200);
    imu_turnright(179, 50);
    wingspistons.set_value(true);
    pros::delay(500);
    //bot positioned to take matchload triball
    drive(-60, 150);
    pros::delay(100);
    imu_turnleft(315, 50);
    drive(-90, 100);
    imu_turnleft(315, 50);
    imu_turnright(45, 50);
    drive(-90, 200);
    pros::delay(200);
    imu_turnleft(315, 60);
    wingspistons.set_value(false);
    //bot positioned to move to alliance bar
    drive(-60, 1400);
}
void allianceauton(){
    imu_sensor.reset(true);
    drive(120, 800);
    imu_turnright(90, 50);
    drive(120, 1000);
    drive(-120, 100);
    //second triball
    intake.move(127);
    imu_turnleft(200, 50);
    drive(120, 200);
    pros::delay(200);
    imu_turnright(160, 50);
    drive(127, 1000);
    drive(-60, 600);
    //third tribhall
    imu_turnright(180, 50);
    drive(127, 300);
    drive(50, 150);
    imu_turnleft(190, 50);
    drive(127, 1200);
    drive(-50, 800);
}
void skills(){
    imu_sensor.reset(true);
    //preload scoring
    drive(-120, 1000);
//    drive(-50, 500);
    drive(50, 200);
    //move to matchload
    imu_turnleft(325, 50);
    drive(50, 800);
    imu_turnright(105, 50);
    drive(35, 1600);
    imu_turnright(30, 50);
    drive(10, 1000);
    cata1.move(127);
    pros::delay(25000);
    cata1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    cata1.move(0);
    //move to cross barrier
    drive(-50, 100);
    imu_turnright(90, 40);
    drive(-50, 800);
    pros::delay(200);
    imu_turnleft(295, 50);
    drive(-80, 2200);
    //barrier crossed
    imu_turnleft(315, 50);
    drive(-110, 600);
    imu_turnleft(310, 50);
    drive(-120, 700);
    drive(50, 200);
    imu_turnleft(270, 50);
    drive(-50, 1200);
    imu_turnright(90, 50);
    drive(-50, 1000);
    imu_turnright(90, 50);
    drive(-120, 1000);
    drive(90, 800);
    imu_turnleft(270, 50);
    drive(-90, 300);
    imu_turnright(90, 50);
    drive(-120, 1000);
}