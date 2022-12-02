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
#include "../include/inputHandler.h"

using namespace vex;

void pre_auton(void)
{
	
}

void autonomous(void)
{
	// ..........................................................................
	// Insert autonomous user code here.
	// ..........................................................................
}

void usercontrol(void)
{
	while (1)
	{

		wait(20, msec);
	}
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
