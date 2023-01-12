
#pragma once

#include "vex.h"
#include <string>

using namespace vex;

using std::string;

const float PI = 3.14159;

brain Brain;
controller Controller;
competition Competition;

motor motor_frontLeft = motor(PORT1, ratio18_1, true);
motor motor_backLeft = motor(PORT2, ratio18_1, true);
motor motor_frontRight = motor(PORT3, ratio18_1, false);
motor motor_backRight = motor(PORT4, ratio18_1, false);

motor_group motorGroup_leftChassis = motor_group(motor_frontLeft, motor_backLeft);
motor_group motorGroup_rightChassis = motor_group(motor_frontRight, motor_backRight);

motor motor_intake = motor(PORT6, ratio18_1, false);
motor motor_conveyor = motor(PORT5, ratio6_1, false);

motor motor_launcher = motor(PORT7, ratio6_1, true);
motor motor_roller = motor(PORT8, ratio36_1, false);

gyro Gyroscope = gyro(Brain.ThreeWirePort.A);
pneumatics pneumatics_Endgame = pneumatics(Brain.ThreeWirePort.B);

const float motorToWheelGearRatio = 60 / 36;
const float wheelDiameter = 3.25;
const float wheelCircumference = wheelDiameter * PI;