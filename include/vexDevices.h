
#pragma once

#include "vex.h"
#include <string>

using namespace vex;
using std::string;

const float PI = 3.14159;

// Vex Devices
brain Brain;
controller Controller;
competition Competition;

motor motor_frontLeft = motor(PORT11, ratio18_1, true);
motor motor_backLeft = motor(PORT12, ratio18_1, true);
motor motor_frontRight = motor(PORT3, ratio18_1, false);
motor motor_backRight = motor(PORT14, ratio18_1, false);

motor_group motorGroup_leftChassis = motor_group(motor_frontLeft, motor_backLeft);
motor_group motorGroup_rightChassis = motor_group(motor_frontRight, motor_backRight);

motor motor_intake = motor(PORT6, ratio18_1, false);
motor motor_conveyor = motor(PORT5, ratio6_1, false);

motor motor_launcher = motor(PORT7, ratio6_1, true);
motor motor_roller = motor(PORT8, ratio36_1, false);

gyro Gyroscope = gyro(Brain.ThreeWirePort.A);
pneumatics pneumatics_Endgame = pneumatics(Brain.ThreeWirePort.B);

/*
 *  Speed Settings
 */

// Intake
bool intakeToggle = false;
const float intakeSpeed = 100;

// Conveyor
const float conveyorSpeed = 100;
const float conveyorSpeed_intake = 75;

// Launcher
const bool launcherSpeedCheckEnabled = true;
const float launcherSpeed = 100;

// Roller
const float rollerSpeed = 20;
const float rollerSpeed_launcher = 75;

/*
 *  Robot Dimensions
 */
const float motorToWheelGearRatio = 60 / 36;
const float wheelDiameter = 3.25; // inch
const float wheelCircumference = wheelDiameter * PI;
const float trackLength = 11.5; // inch
const float wheelBase = 11.5;   // inch

const float turnCircleRadius = sqrt((trackLength * trackLength) + (wheelBase * wheelBase));
const float turnCircleCircum = 2 * turnCircleRadius * PI;

/*
 *  Input
 */

// Intake
const vex::controller::button buttonIntakeForward = Controller.ButtonL1;
const vex::controller::button buttonIntakeReverse = Controller.ButtonL2;

// Conveyor
const vex::controller::button buttonConveyorForward = Controller.ButtonLeft;
const vex::controller::button buttonConveyorReverse = Controller.ButtonRight;

// Roller
const vex::controller::button buttonRollerForward = Controller.ButtonA;
const vex::controller::button buttonRollerReverse = Controller.ButtonB;

// Endgame
const vex::controller::button buttonEndgame = Controller.ButtonY;

// Launcher
const vex::controller::button buttonLauncher = Controller.ButtonR2;