
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
motor motor_frontRight = motor(PORT1, ratio18_1, false);
motor motor_backRight = motor(PORT20, ratio18_1, false);

motor_group motorGroup_leftChassis = motor_group(motor_frontLeft, motor_backLeft);
motor_group motorGroup_rightChassis = motor_group(motor_frontRight, motor_backRight);

motor motor_conveyor = motor(PORT15, ratio6_1, false);
motor motor_intake = motor(PORT16, ratio18_1, false);

motor motor_launcher = motor(PORT17, ratio6_1, true);
motor motor_roller = motor(PORT10, ratio18_1, false);

digital_out pneumatics_Endgame = digital_out(Brain.ThreeWirePort.A);

/*
 *  Speed Settings
 */

// Intake
bool intakeToggle = false;
const float intakeSpeed = 100;

// Conveyor
const float conveyorSpeed = 100;
const float conveyorSpeed_intake = 75;
const float conveyorSpeed_launcher = 25;

// Launcher
const bool launcherSpeedCheckEnabled = true;
const float launcherSpeed = 80;

// Roller
const float rollerSpeed = 100;
const float rollerSpeed_launcher = 100;
const float rollerSpeed_auto = 40;

// Endgame
const float autoEndgameEnableTime = 1;

/*
 *  Robot Dimensions
 */
const float motorToWheelGearRatio = 60.0 / 36.0;
const float wheelDiameter = 3.25; // inch
const float wheelCircumference = wheelDiameter * PI;
const float trackLength = 11.5; // inch
const float wheelBase = 11.5;   // inch

const float turnCircleRadius = sqrt(((trackLength / 2.0) * (trackLength / 2.0)) + ((wheelBase / 2.0) * (wheelBase / 2.0)));
const float turnCircleCircum = 2.0 * turnCircleRadius * PI;

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
const vex::controller::button buttonEndgame = Controller.ButtonUp;

// Launcher
const vex::controller::button buttonLauncher = Controller.ButtonR2;
const vex::controller::button buttonLauncherRollerReverse = Controller.ButtonR1;