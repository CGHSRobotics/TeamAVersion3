#pragma once

#include "autonomousFunc.h"

void autoRoutine_twoSide()
{

    autoLaunchDisks(3, 100);

    autoDriveDistance(1, 10, "tile");

    autoTurnXDegrees(90, 50);

    autoDriveDistance(-0.5, 50, "tile");

    autoSpinRollerTime(1, 20);

    autoDriveDistance(0.1, 20, "tile");

    //  After Routine ends, do nothing
    while (true)
    {
        wait(50, msec);
    }
}