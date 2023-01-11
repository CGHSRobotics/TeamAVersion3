#pragma once

#include "autonomousFunc.h"

void autoRoutine_threeSide()
{
    autoDriveDistance(1, 100, "tile");

    motorGroup_leftChassis.setVelocity(100, percent);
    motorGroup_rightChassis.setVelocity(100, percent);

    motorGroup_leftChassis.spin(fwd);
    motorGroup_rightChassis.spin(fwd);

    //  After Routine ends, do nothing
    while (true)
    {
        wait(50, msec);
    }
};