#pragma once

#include "vexDevices.h"
#include "userMovement.h"

void setupCallbacks()
{
    /*
     *   on press callbacks
     */

    buttonLauncher.pressed(triggerEndgameAsync);
    buttonRollerForward.pressed(rollerForwardAsync);
    buttonRollerReverse.pressed(rollerReverseAsync);
    buttonConveyorForward.pressed(conveyorForwardAsync);
    buttonConveyorReverse.pressed(conveyorReverseAsync);
    buttonIntakeForward.pressed(intakeForwardAsync);
    buttonIntakeReverse.pressed(intakeReverseAsync);
    buttonLauncher.pressed(launchDisksAsync);

    /*
     *  on release callbacks
     */

    buttonLauncher.released(triggerEndgameAsync);
    buttonRollerForward.released(rollerForwardAsync);
    buttonRollerReverse.released(rollerReverseAsync);
    buttonConveyorForward.released(conveyorForwardAsync);
    buttonConveyorReverse.released(conveyorReverseAsync);
    buttonIntakeForward.released(intakeForwardAsync);
    buttonIntakeReverse.released(intakeReverseAsync);
    buttonLauncher.released(launchDisksAsync);
}