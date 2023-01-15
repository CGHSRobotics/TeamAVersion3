#pragma once

#include "autonomousFunc.h"

void autoRoutine_skillsAuto()
{
    autoDriveDistance(-0.1, 10);

    autoSpinRollerTime(1, rollerSpeed_auto);

    autoDriveDistance(0.1, 10);

    autoTurnXDegrees(70, 10);

    autoLaunchDisks(4, 60);

    autoTurnXDegrees(-45, 10);

    autoEndgame();

    autoDriveDistance(5, 100);

    //  After Routine ends, do nothing
    while (true)
    {
        wait(50, msec);
    }
};