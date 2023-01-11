#pragma once

#include "autonomousFunc.h"

void autoRoutine_threeSide()
{
    autoDriveDistance(1, 100, "tile");

    //  After Routine ends, do nothing
    while (true)
    {
        wait(50, msec);
    }
};