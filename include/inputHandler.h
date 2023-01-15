#pragma once

#include "vexDevices.h"
#include "userMovement.h"

void setupCallbacks()
{
    /*
     *   on press callbacks
     */

    buttonEndgame.pressed(triggerEndgameAsync);
    buttonRollerForward.pressed(rollerForwardAsync);
    buttonRollerReverse.pressed(rollerReverseAsync);
    buttonConveyorForward.pressed(conveyorForwardAsync);
    buttonConveyorReverse.pressed(conveyorReverseAsync);
    buttonIntakeForward.pressed(intakeForwardAsync);
    buttonIntakeReverse.pressed(intakeReverseAsync);
    buttonLauncher.pressed(launchDisksAsync);
    buttonLauncherRollerReverse.pressed(launcherRollerReverse);

    /*
     *  on release callbacks
     */

    buttonEndgame.released(triggerEndgameAsync);
    buttonRollerForward.released(rollerForwardAsync);
    buttonRollerReverse.released(rollerReverseAsync);
    buttonConveyorForward.released(conveyorForwardAsync);
    buttonConveyorReverse.released(conveyorReverseAsync);
    buttonIntakeForward.released(intakeForwardAsync);
    buttonIntakeReverse.released(intakeReverseAsync);
    buttonLauncher.released(launchDisksAsync);
    buttonLauncherRollerReverse.released(launcherRollerReverse);
}