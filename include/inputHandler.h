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
    // Controller.ButtonA.pressed(press_a);
    Controller.ButtonB.pressed(launchDisksAsync);

    Controller.ButtonLeft.pressed(conveyorForwardAsync);
    // Controller.ButtonUp.pressed(press_up);
    Controller.ButtonRight.pressed(conveyorReverseAsync);
    // Controller.ButtonDown.pressed(press_down);

    Controller.ButtonL1.pressed(intakeReverseAsync);
    Controller.ButtonL2.pressed(intakeForwardAsync);
    Controller.ButtonR1.pressed(rollerForwardAsync);
    Controller.ButtonR2.pressed(rollerReverseAsync);

    /*
     *  on release callbacks
     */

    // Controller.ButtonY.released(release_y);
    Controller.ButtonX.released(triggerEndgameAsync);
    // Controller.ButtonA.released(release_a);
    Controller.ButtonB.released(launchDisksAsync);

    Controller.ButtonLeft.released(conveyorForwardAsync);
    // Controller.ButtonUp.released(release_up);
    Controller.ButtonRight.released(conveyorReverseAsync);
    // Controller.ButtonDown.released(release_down);

    Controller.ButtonL1.released(intakeReverseAsync);
    Controller.ButtonL2.released(intakeForwardAsync);
    Controller.ButtonR1.released(rollerForwardAsync);
    Controller.ButtonR2.released(rollerReverseAsync);
}