#include "autonomousFunc.h"

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

void autoTurnXDegrees(float angle){

};

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