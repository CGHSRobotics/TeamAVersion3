#pragma once

#include "autonomousFunc.h"

void autoRoutine_threeSide()
{
    autoDriveDistance(-0.1, 50, "tile");

    autoSpinRollerTime(1, 20);

    //  After Routine ends, do nothing
    while (true)
    {
        wait(50, msec);
    }
};