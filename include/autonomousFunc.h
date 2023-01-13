#pragma once

#include "util.h"

/*
 *  Function Declarations
 */

void autoDriveDistance(float distance, float velocity, string distanceType = "tile");
void autoDriveTime(float time, float velocity);
void autoTurnXDegrees(float angle, float velocity);

void autoSpinRollerTime(float time);

void autoLaunchDisks(float time, float speed);

void autoEndgame();

void autoIntake(bool enabled);

/*
 *  Function Definitions
 */

// Drives the Robot X distance at a certain speed
void autoDriveDistance(float distance, float velocity, string distanceType)
{
    motorGroup_leftChassis.resetPosition();
    motorGroup_rightChassis.resetPosition();

    float motorDegree = ((distance * 24) / wheelCircumference) / motorToWheelGearRatio;

    // note: this “deg” is from vex namespace
    motorGroup_leftChassis.setVelocity(velocity, percent);
    motorGroup_leftChassis.spinToPosition(motorDegree, deg, false);

    motorGroup_rightChassis.setVelocity(velocity, percent);
    motorGroup_rightChassis.spinToPosition(motorDegree, deg, false);

    while (motorGroup_leftChassis.isSpinning() || motorGroup_rightChassis.isSpinning())
    {
        wait(50, msec);
    }

    return;
};

// Drives the Robot for a certain amount of time
void autoDriveTime(float time, float velocity)
{
    float currTime = 0;

    spinMotor(motorGroup_leftChassis, velocity);
    spinMotor(motorGroup_rightChassis, velocity);

    while (true)
    {
        currTime += 20;

        if (currTime >= time / 1000)
        {
            spinMotor(motorGroup_leftChassis, 0);
            spinMotor(motorGroup_rightChassis, 0);

            return;
        }

        wait(20, msec);
    }
};

// Turns the robot a certain number of degrees at a certain speed
void autoTurnXDegrees(float angle, float velocity)
{

    motorGroup_leftChassis.resetPosition();
    motorGroup_rightChassis.resetPosition();

    float motorDegree = (angle * (turnCircleCircum / 360)) / wheelDiameter / motorToWheelGearRatio; // degrees * EncPerDeg;

    // note: this “deg” is from vex namespace
    motorGroup_leftChassis.setVelocity(velocity, percent);
    motorGroup_leftChassis.spinToPosition(motorDegree, deg, false);

    motorGroup_rightChassis.setVelocity(velocity, percent);
    motorGroup_rightChassis.spinToPosition(-motorDegree, deg, false);

    while (motorGroup_leftChassis.isSpinning() || motorGroup_rightChassis.isSpinning())
    {
        wait(50, msec);
    }

    return;
};

// Spins roller for certain amount of time
void autoSpinRollerTime(float time, float velocity)
{
    float timeCurr = 0;

    spinMotor(motor_roller, velocity);

    while (timeCurr < time)
    {
        timeCurr += 10;
        wait(10, msec);
    }

    spinMotor(motor_roller, 0);
}

// Launches disks for a certain amount of time at a certain speed
void autoLaunchDisks(float time, float speed)
{
    float timeCurr = 0;

    spinMotor(motor_launcher, speed);
    while (!(motor_launcher.velocity(percent) >= launcherSpeed * 0.8))
    {
        wait(10, msec);
    }

    motor_launcher.spin(fwd, 12 * (speed / 100), volt);
    spinMotor(motor_conveyor, -conveyorSpeed);
    spinMotor(motor_intake, intakeSpeed);
    spinMotor(motor_roller, -rollerSpeed_launcher);

    while (timeCurr < time)
    {
        timeCurr += 10;
        wait(10, msec);
    }

    motor_launcher.spin(fwd, 12 * 0, volt);
    spinMotor(motor_conveyor, 0);
    spinMotor(motor_intake, 0);
    spinMotor(motor_roller, 0);
}

// Auto Endgame
void autoEndgame()
{
    float time = autoEndgameEnableTime;
    float timeCurr = 0;

    pneumatics_Endgame.open();

    while (timeCurr < time)
    {
        timeCurr += 10;
        wait(10, msec);
    }

    pneumatics_Endgame.close();
}