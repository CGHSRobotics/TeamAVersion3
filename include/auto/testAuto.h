#pragma once

#include "autonomousFunc.h"

void autoRoutine_testAuto()
{

    //autoDriveDistance(1, 25);

    autoTurnXDegrees(90, 10);

    //autoDriveDistance(-1, 25);

    autoLaunchDisks(3, 100);

    //  After Routine ends, do nothing
    while (true)
    {
        wait(50, msec);
    }
}