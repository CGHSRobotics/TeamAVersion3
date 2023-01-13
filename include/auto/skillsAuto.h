#pragma once

#include "autonomousFunc.h"

void autoRoutine_skillsAuto()
{
    printTextToScreen("I am very SKILLED", 1, 1);

    autoDriveDistance(-0.1, 50);

    autoSpinRollerTime(1, 20);

    autoDriveDistance(0.1, 50);

    autoTurnXDegrees(90, 50);

    autoLaunchDisks(3, 100);

    autoDriveDistance(-1.0, 50);

    autoSpinRollerTime(1, 20);

    autoDriveDistance(1.5, 20);

    autoTurnXDegrees(-45, 20);

    autoDriveDistance(5, 20);

    //  After Routine ends, do nothing
    while (true)
    {
        wait(50, msec);
    }
};