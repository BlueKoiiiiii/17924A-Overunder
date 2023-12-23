//
// Created by Daniel on 2023-10-29.
//

#include "../include/autonomous.h"
void imu_turnright(int target_angle, int speed) {
    speed = 10;
    double kp = 1.3;
    double ki = 0.02;
    double kd = 0.6;
    int lastError = 0;
//    int totalruntime = 0;
    int totalError = 0;
    int integralActiveZone = 20;
    bool runloop = true;
    imu_sensor.set_heading(1);
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

        master.set_text(0, 0, std::to_string(error));
        pros::delay(10);
    }
}
void imu_turnleftleft(int target_angle, int speed) {
    speed = 10;
    double kp = 1.3;
    double ki = 0.02;
    double kd = 0.6;
    int lastError = 0;
    int totalError = 0;
    int integralActiveZone = 10;
    int totalruntime = 0;
//    int totalruntime = 0;
    bool runloop = true;
    imu_sensor.set_heading(359);
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
        if (totalruntime == 200){
            kp = 2.4;
            ki = 0.15;
        }
        if (totalruntime == 350){
            runloop = false;
        }
        totalruntime += 1;
        master.set_text(0, 0, std::to_string(error));
        pros::delay(10);
    }
}
void farauton(){
    imu_sensor.reset(true);
    //preload scoring
    drive(-120, 2000);
//    drive(50, 200);
//    drive(-60, 1000);
    drive(50, 200);
//    drive(-50, 500);
//    drive(50, 200);
//    drive(-120, 700);
    //move to matchload
    imu_turnleft(325, 50);
    drive(90, 300);
    pros::delay(200);
    imu_turnright(105, 50);
    drive(38, 2000);
    imu_turnright(20, 50);
    drive(10, 1000);
}
void allianceauton(){
    imu_sensor.reset(true);
    drive(120, 750);
    imu_turnright(75, 50);
    intake.move(-127);
    drive(120, 1000);
    drive(-120, 100);
    //second triball
    intake.move(127);
    imu_turnleft(200, 50);
    drive(75, 150);
    pros::delay(400);
    drive(-75, 150);
    imu_turnright(140, 50);
    drive(80, 1200);
    drive(-60, 600);
    //third tribhall
}
void safeskills(){
    cata1.move(127);
    imu_sensor.reset(true);
//    cata1.move(127);
    pros::delay(28000);
    cata1.move(0);
    drive(-30, 200);
    imu_turnright(100, 30);
    drive(-90, 1000);
    //align to prepare against the wall
    drive(30, 400);
    imu_turnleftleft(270, 30);
    drive(-50, 3550);
    //crossed
    drive(0, 100);
    imu_turnright(90, 30);
    drive(-90, 1000);
    drive(60, 900);
    imu_turnleftleft(270, 30);
    drive(60, 1000);
    drive(-20, 500);
    imu_turnleftleft(270, 30);
    drive(-60, 650);
    imu_turnright(90, 30);
    drive(-127, 1400);
    intake.move(-127);
    drive(60, 1300);
    drive(30, 500);
//    pros::delay(400);
    drive(-30, 300);
    imu_turnleftleft(340, 30);
    drive(-120, 1400);
    drive(60, 1000);
    imu_turnleftleft(340, 30);
    drive(-120, 1400);
    drive(60, 300);

}
void skills(){
    cata1.move(127);
    imu_sensor.reset(true);
//    cata1.move(127);
    pros::delay(28000);
    cata1.move(0);
    drive(-30, 200);
    imu_turnright(100, 30);
    drive(-40, 1000);
    drive(-90, 700);
    //align to prepare against the wall
    drive(30, 400);
    imu_turnleftleft(268, 30);
    drive(-70, 2200);
    drive(0, 100);
    //barrier crossed
    imu_turnleftleft(325, 30);
    drive(-50, 1200);
    imu_turnleftleft(310, 30);
    drive(-127, 1000);
    drive(50, 500);
    drive(-127, 1000);
    drive(50, 800);
    drive(-127, 1000);
    drive(50, 400);
    imu_turnleftleft(270, 30);
    drive(-60, 1600);
    drive(20, 200);
    imu_turnright(130, 30);
    drive(-120, 1500);
    drive(60, 300);
    drive(-127, 1000);
    drive(60, 1300);
    drive(30, 500);
    pros::delay(400);
    drive(-30, 300);
    imu_turnleftleft(330, 30);
    drive(-120, 1500);
    drive(60, 300);
    drive(-127, 900);
    drive(60, 1300);
    drive(30, 500);
    pros::delay(400);
    drive(-30, 300);
    imu_turnleftleft(330, 30);
    drive(-120, 1400);
    drive(60, 600);
    drive(-127, 1000);
    drive(30, 900);


}
void oldskills(){
    imu_sensor.reset(true);
    //preload scoring
    drive(-120, 1000);
//    drive(50, 200);
//    drive(-60, 1000);
    drive(50, 200);
//    drive(-50, 500);
//    drive(50, 200);
//    drive(-120, 700);
    //move to matchload
    imu_turnleft(325, 50);
    drive(90, 300);
    pros::delay(200);
    imu_turnright(105, 50);
    drive(38, 2000);
    imu_turnright(20, 50);
    drive(10, 1000);
//    cata1.move(127);
//    pros::delay(28000);
////    cata1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
//    cata1.move(0);
    //move to cross barrier
    drive(-50, 100);
    pros::delay(400);
    imu_turnright(89, 30);
    drive(-50, 800);
    pros::delay(200);
    drive(-70, 1750);
    drive(50, 200);
    pros::delay(300);
    imu_turnleft(270, 50);
    drive(-100, 1550);
    //barrier crossed
    imu_turnright(90, 50);
    drive(-90, 1000);
    drive(30, 500);
    imu_turnright(180, 50);
    drive(-120, 850);
    imu_turnright(100, 50);
    drive(-120, 850);
    drive(50, 200);
    imu_turnright(20, 50);
    drive(90, 500);
    imu_turnleft(330, 50);
    drive(-120, 1000);

//    imu_turnleft(225, 50);
////    imu_turnleft(315, 50);
//    drive(-90, 700);
//    pros::delay(500);
//    imu_turnleft(310, 50);
//    drive(-120, 700);
//    drive(50, 200);
//    drive(-120, 700);
//    drive(50, 400);
//    pros::delay(500);
//    imu_turnleft(270, 50);
//    //move to front of goal
//    drive(-120, 800);
//    imu_turnright(90, 50);
//    drive(-120, 450);
//    imu_turnright(90, 50);
//    wingspistons.set_value(true);
//    pros::delay(600);
//    drive(-120, 1000);
//    drive(120, 800);
////    imu_turnleft(270, 50);
////    drive(-90, 300);
////    imu_turnright(90, 50);
//    pros::delay(1000);
//    drive(-120, 1000);
//    drive(120, 800);
//    drive(-120, 1000);
}