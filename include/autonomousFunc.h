#pragma once

#include "util.h"

/*
 *  Function Declarations
 */

void autoDriveDistance(float distance, float velocity, string distanceType);
void autoDriveTime(float time, float velocity);
void autoTurnXDegrees(float angle, float velocity);

void autoSpinRollerTime(float time);

/*
 *  Function Definitions
 */

// Drives the Robot X distance at a certain speed
void autoDriveDistance(float distance, float velocity, string distanceType)
{
    if (distanceType == "tile")
    {
        distance *= 24;
    }

    float startRotationNumLeft = motor_frontLeft.position(rev);
    float startRotationNumRight = motor_frontRight.position(rev);

    motorGroup_leftChassis.setVelocity(velocity, percent);
    motorGroup_rightChassis.setVelocity(velocity, percent);

    motorGroup_leftChassis.spin(fwd);
    motorGroup_rightChassis.spin(fwd);

    while (true)
    {
        float distanceTravelled = (motor_frontLeft.position(rev) - startRotationNumLeft) * motorToWheelGearRatio * wheelCircumference;
        if (distanceTravelled >= distance)
        {
            motorGroup_leftChassis.setVelocity(0, percent);
            motorGroup_rightChassis.setVelocity(0, percent);

            motorGroup_leftChassis.spin(fwd);
            motorGroup_rightChassis.spin(fwd);

            return;
        }

        wait(10, msec);
    }
};

// Drives the Robot for a certain amount of time
void autoDriveTime(float time, float velocity)
{
    float currTime = 0;

    motorGroup_leftChassis.setVelocity(velocity, percent);
    motorGroup_rightChassis.setVelocity(velocity, percent);

    motorGroup_leftChassis.spin(fwd);
    motorGroup_rightChassis.spin(fwd);

    while (true)
    {
        currTime += 20;

        if (currTime >= time / 1000)
        {
            motorGroup_leftChassis.setVelocity(0, percent);
            motorGroup_rightChassis.setVelocity(0, percent);

            motorGroup_leftChassis.spin(fwd);
            motorGroup_rightChassis.spin(fwd);

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

    float totalEnc = 0; // degrees * EncPerDeg;

    // note: this “deg” is from vex namespace
    motorGroup_leftChassis.setVelocity(100.0, percent);
    motorGroup_leftChassis.spinToPosition(totalEnc, deg, false);

    motorGroup_rightChassis.setVelocity(-100.0, percent);
    motorGroup_rightChassis.spinToPosition(-totalEnc, deg, false);

    while (motorGroup_leftChassis.isSpinning() || motorGroup_rightChassis.isSpinning())
    {
        wait(50, msec);
    }

    return;
};

// Spins roller for certain amount of time
void autoSpinRollerTime(float time)
{
    float timeCurr = 0;

    spinMotor(motor_roller, 50);

    while (timeCurr < time)
    {
        timeCurr += 10;
        wait(10, msec);
    }

    spinMotor(motor_roller, 0);
}