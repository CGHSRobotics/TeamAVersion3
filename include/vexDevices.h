
#pragma once

#include "vex.h"

using namespace vex;

brain Brain;
controller Controller;
competition Competition;

motor motor_frontLeft = motor(PORT1, ratio18_1, false);
motor motor_backLeft = motor(PORT2, ratio18_1, false);
motor motor_frontRight = motor(PORT3, ratio18_1, false);
motor motor_backRight = motor(PORT4, ratio18_1, false);

motor_group motorGroup_leftChassis = motor_group(motor_frontLeft, motor_backLeft);
motor_group motorGroup_rightChassis = motor_group(motor_frontRight, motor_backRight);

gyro Gyroscope = gyro(Brain.ThreeWirePort.A);

float wheelTravel;
float trackWidth;
float wheelBase;
float externalGearRatio;

drivetrain Chassis_DriveTrain = drivetrain(motorGroup_leftChassis,
                                           motorGroup_rightChassis,
                                           wheelTravel, trackWidth,
                                           wheelBase, inches,
                                           externalGearRatio);

pneumatics pneu_Endgame = pneumatics(Brain.ThreeWirePort.B);
