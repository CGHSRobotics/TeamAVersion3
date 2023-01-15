#pragma once

#include "autonomousFunc.h"

void autoRoutine_threeSide()
{
    autoDriveDistance(-0.1, 10);

    autoSpinRollerTime(0.5, rollerSpeed_auto);

    autoDriveDistance(0.1, 10);

    autoTurnXDegrees(70, 10);

    autoLaunchDisks(5, 60);

    //  After Routine ends, do nothing
    while (true)
    {
        wait(50, msec);
    }
};