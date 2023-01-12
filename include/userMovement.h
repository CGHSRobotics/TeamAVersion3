#pragma once

#include "vex.h"
#include "util.h"

float filterAxis(float input);
void checkAxis();

void intakeForwardAsync();
void intakeReverseAsync();

void launchDisksAsync();

void triggerEndgameAsync();

void rollerForwardAsync();
void rollerReverseAsync();

void conveyorForwardAsync();
void conveyorReverseAsync();

/*
 * Function Definitions
 */

float filterAxis(float input, float cutoff)
{
    float num = input;
    if (num < cutoff && num > -cutoff)
    {
        num = 0;
    }
    return num;
}

void checkAxis()
{
    while (true)
    {
        float leftDriveRaw = Controller.Axis3.position(percent);
        float rightDriveRaw = Controller.Axis2.position(percent);

        float leftDrive = filterAxis(leftDriveRaw, 50);
        float rightDrive = filterAxis(rightDriveRaw, 50);

        motorGroup_leftChassis.setVelocity(leftDrive, percent);
        motorGroup_rightChassis.setVelocity(rightDrive, percent);

        motorGroup_leftChassis.spin(fwd);
        motorGroup_rightChassis.spin(fwd);

        printTextToScreen(leftDrive, 1, 6);
        printTextToScreen(rightDrive, 6, 6);

        wait(20, msec);
    }
}

bool intakeToggle = false;
void intakeForwardAsync()
{
    // Toggle for Controller L2
    if (Controller.ButtonL2.pressing())
    {
        intakeToggle = !intakeToggle;
    }

    if (intakeToggle)
    {
        motor_intake.setVelocity(100, percent);
        motor_conveyor.setVelocity(100, percent);
    }
    else
    {
        motor_intake.setVelocity(0, percent);
        motor_conveyor.setVelocity(0, percent);
    }
    motor_intake.spin(fwd);
    motor_conveyor.spin(fwd);
}

void intakeReverseAsync()
{
    intakeToggle = false;
    if (Controller.ButtonL1.pressing())
    {
        motor_intake.setVelocity(-100, percent);
        motor_conveyor.setVelocity(-100, percent);
    }
    else
    {
        motor_intake.setVelocity(0, percent);
        motor_conveyor.setVelocity(0, percent);
    }
    motor_intake.spin(fwd);
    motor_conveyor.spin(fwd);
}

float launcherSpeed = 1;
bool launcherSpeedCheckEnabled = false;
void launchDisksAsync()
{
    if (Controller.ButtonB.pressing())
    {
        motor_launcher.spin(fwd, 12 * launcherSpeed, volt);
        if (!launcherSpeedCheckEnabled || motor_launcher.velocity(rpm) >= (launcherSpeed * 0.8) * 600)
        {
            spinMotor(motor_conveyor, -100);
            spinMotor(motor_intake, 100);
            spinMotor(motor_roller, -100);
        }
    }
    else
    {
        motor_launcher.spin(fwd, 12 * 0, volt);
        spinMotor(motor_conveyor, 0);
        spinMotor(motor_intake, 0);
        spinMotor(motor_roller, 0);
    }
}

void triggerEndgameAsync()
{
    if (Controller.ButtonX.pressing())
    {
        pneumatics_Endgame.open();
    }
    else
    {
        pneumatics_Endgame.close();
    }
}

void rollerForwardAsync()
{
    if (Controller.ButtonR1.pressing())
    {
        motor_roller.setVelocity(100, percent);
    }
    else
    {
        motor_roller.setVelocity(0, percent);
    }
    motor_roller.spin(fwd);
}

void rollerReverseAsync()
{
    if (Controller.ButtonR2.pressing())
    {
        motor_roller.setVelocity(-100, percent);
    }
    else
    {
        motor_roller.setVelocity(0, percent);
    }
    motor_roller.spin(fwd);
}

void conveyorForwardAsync()
{
    if (Controller.ButtonLeft.pressing())
    {
        motor_conveyor.setVelocity(100, percent);
    }
    else
    {
        motor_conveyor.setVelocity(0, percent);
    }
    motor_conveyor.spin(fwd);
}

void conveyorReverseAsync()
{
    if (Controller.ButtonRight.pressing())
    {
        motor_conveyor.setVelocity(-100, percent);
    }
    else
    {
        motor_conveyor.setVelocity(0, percent);
    }
    motor_conveyor.spin(fwd);
}