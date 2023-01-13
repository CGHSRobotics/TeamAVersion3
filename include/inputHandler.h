#pragma once

#include "vexDevices.h"
#include "userMovement.h"

void setupCallbacks()
{
    /*
     *   on press callbacks
     */

    Controller.ButtonY.pressed(triggerEndgameAsync);
    // Controller.ButtonX.pressed(press_x);
    Controller.ButtonA.pressed(rollerForwardAsync);
    Controller.ButtonB.pressed(rollerReverseAsync);

    Controller.ButtonLeft.pressed(conveyorForwardAsync);
    // Controller.ButtonUp.pressed();
    Controller.ButtonRight.pressed(conveyorReverseAsync);
    // Controller.ButtonDown.pressed(press_down);

    Controller.ButtonL1.pressed(intakeForwardAsync);
    Controller.ButtonL2.pressed(intakeReverseAsync);
    // Controller.ButtonR1.pressed();
    Controller.ButtonR2.pressed(launchDisksAsync);

    /*
     *  on release callbacks
     */

    Controller.ButtonY.released(triggerEndgameAsync);
    // Controller.ButtonX.released();
    Controller.ButtonA.released(rollerForwardAsync);
    Controller.ButtonB.released(rollerReverseAsync);

    Controller.ButtonLeft.released(conveyorForwardAsync);
    // Controller.ButtonUp.released();
    Controller.ButtonRight.released(conveyorReverseAsync);
    // Controller.ButtonDown.released(release_down);

    Controller.ButtonL1.released(intakeForwardAsync);
    Controller.ButtonL2.released(intakeReverseAsync);
    // Controller.ButtonR1.released();
    Controller.ButtonR2.released(launchDisksAsync);
}