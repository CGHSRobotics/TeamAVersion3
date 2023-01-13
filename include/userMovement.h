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

void intakeForwardAsync()
{
    // Toggle for Controller L2
    if (buttonIntakeForward.pressing())
    {
        intakeToggle = !intakeToggle;
    }

    if (intakeToggle)
    {
        spinMotor(motor_intake, intakeSpeed);
        spinMotor(motor_conveyor, conveyorSpeed_intake);
    }
    else
    {
        spinMotor(motor_intake, 0);
        spinMotor(motor_conveyor, 0);
    }
}

void intakeReverseAsync()
{
    intakeToggle = false;
    if (buttonIntakeReverse.pressing())
    {
        spinMotor(motor_intake, -intakeSpeed);
        spinMotor(motor_conveyor, -conveyorSpeed);
    }
    else
    {
        spinMotor(motor_intake, 0);
        spinMotor(motor_conveyor, 0);
    }
}

void launchDisksAsync()
{
    if (buttonLauncher.pressing())
    {
        spinMotor(motor_launcher, launcherSpeed);
        if (launcherSpeedCheckEnabled)
        {
            while (!(motor_launcher.velocity(percent) >= launcherSpeed * 0.8))
            {
                if (!buttonLauncher.pressing())
                {
                    return;
                }

                wait(10, msec);
            }
            if (!buttonLauncher.pressing())
            {
                motor_launcher.spin(fwd, 12 * 0, volt);
            }
        }

        motor_launcher.spin(fwd, 12 * (launcherSpeed / 100), volt);
        spinMotor(motor_conveyor, -conveyorSpeed);
        spinMotor(motor_intake, intakeSpeed);
        spinMotor(motor_roller, -rollerSpeed);
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
    if (buttonEndgame.pressing())
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
    if (buttonRollerForward.pressing())
    {
        spinMotor(motor_roller, rollerSpeed);
    }
    else
    {
        spinMotor(motor_roller, 0);
    }
}

void rollerReverseAsync()
{
    if (buttonRollerReverse.pressing())
    {
        spinMotor(motor_roller, -rollerSpeed);
    }
    else
    {
        spinMotor(motor_roller, 0);
    }
}

void conveyorForwardAsync()
{
    if (buttonConveyorForward.pressing())
    {
        spinMotor(motor_conveyor, conveyorSpeed);
    }
    else
    {
        spinMotor(motor_conveyor, 0);
    }
}

void conveyorReverseAsync()
{
    if (buttonConveyorReverse.pressing())
    {
        spinMotor(motor_conveyor, -conveyorSpeed);
    }
    else
    {
        spinMotor(motor_conveyor, 0);
    }
}