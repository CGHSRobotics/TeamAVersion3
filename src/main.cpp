/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Robotics1                                                 */
/*    Created:      11/30/2022, 7:38:44 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

#include "../include/vexDevices.h"
#include "../include/util.h"
#include "../include/inputHandler.h"
#include "../include/autonomousFunc.h"

#include "../include/auto/threeAuto.h"
#include "../include/auto/skillsAuto.h"

using namespace vex;

string autonomousRoutineString = "null";

thread autonomousThread;
thread axisMovementThread;

void pre_auton(void)
{
}

void autonomous(void)
{
	if (autonomousRoutineString == "threeSide")
	{
		autonomousThread = thread(autoRoutine_threeSide);
	}
	if (autonomousRoutineString == "skills")
	{
		autonomousThread = thread(autoRoutine_skillsAuto);
	}
	else
	{
		// Else Do Nothing
		while (true)
		{
			wait(50, msec);
		}
	}

	autonomousThread.setPriority(10);
}

void usercontrol(void)
{
	setupCallbacks();

	//axisMovementThread = thread(checkAxis);
}

int main()
{
	// Set up callbacks for autonomous and driver control periods.
	Competition.autonomous(autonomous);
	Competition.drivercontrol(usercontrol);

	// Controller.ButtonA.pressed();

	// Run the pre-autonomous function.
	pre_auton();

	// Prevent main from exiting with an infinite loop.
	while (true)
	{
		wait(100, msec);
	}
}
