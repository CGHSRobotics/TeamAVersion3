#pragma once

#include "autonomousFunc.h"

void autoRoutine_skillsAuto()
{
    printTextToScreen("I am very SKILLED", 1, 1);

    //  After Routine ends, do nothing
    while (true)
    {
        wait(50, msec);
    }
};