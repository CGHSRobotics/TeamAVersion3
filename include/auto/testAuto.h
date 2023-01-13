#pragma once

#include "autonomousFunc.h"

void autoRoutine_testAuto()
{

    autoDriveDistance(1, 50);

    autoDriveDistance(1, 100);

    autoDriveDistance(-1, 50);

    autoTurnXDegrees(360, 20);

    //  After Routine ends, do nothing
    while (true)
    {
        wait(50, msec);
    }
}