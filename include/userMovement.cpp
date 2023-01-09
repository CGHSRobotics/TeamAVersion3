
#include "userMovement.h"

float filterAxis(float input)
{
    if (input < 5 && input > -5)
    {
        input = 5;
    }
    return input;
}

void checkAxis()
{
    while (true)
    {
        float leftDrive = filterAxis(Controller.Axis3.position());
        float rightDrive = filterAxis(Controller.Axis3.position());

        motorGroup_leftChassis.setVelocity(leftDrive, percent);
        motorGroup_rightChassis.setVelocity(rightDrive, percent);

        motorGroup_leftChassis.spin(fwd);
        motorGroup_rightChassis.spin(fwd);

        wait(20, msec);
    }
}

bool intakeToggle = false;
void intakeForwardAsync()
{
    // Toggle for Controller L2
    if (Controller.ButtonL2.pressing())
    {
        intakeToggle = !intakeToggle;
    }

    if (intakeToggle)
    {
        motor_intake.setVelocity(100, percent);
        motor_conveyor.setVelocity(100, percent);
    }
    else
    {
        motor_intake.setVelocity(0, percent);
        motor_conveyor.setVelocity(0, percent);
    }
    motor_intake.spin(fwd);
    motor_conveyor.spin(fwd);
}

void intakeReverseAsync()
{
    intakeToggle = false;
    if (Controller.ButtonL1.pressing())
    {
        motor_intake.setVelocity(-100, percent);
        motor_conveyor.setVelocity(-100, percent);
    }
    else
    {
        motor_intake.setVelocity(0, percent);
        motor_conveyor.setVelocity(0, percent);
    }
    motor_intake.spin(fwd);
    motor_conveyor.spin(fwd);
}

void launchDisksAsync()
{
    if (Controller.ButtonB.pressing())
    {
        motor_launcher.setVelocity(100, percent);
        motor_conveyor.setVelocity(-100, percent);
    }
    else
    {
        motor_launcher.setVelocity(0, percent);
        motor_conveyor.setVelocity(0, percent);
    }
    motor_launcher.spin(fwd);
    motor_conveyor.spin(fwd);
}

void triggerEndgameAsync()
{
    if (Controller.ButtonX.pressing())
    {
        pneumatics_Endgame.open();
    }
    else
    {
        pneumatics_Endgame.close();
    }
}

void rollerForwardAsync()
{
    if (Controller.ButtonR2.pressing())
    {
        motor_roller.setVelocity(100, percent);
    }
    else
    {
        motor_roller.setVelocity(0, percent);
    }
    motor_roller.spin(fwd);
}

void rollerReverseAsync()
{
    if (Controller.ButtonR1.pressing())
    {
        motor_roller.setVelocity(-100, percent);
    }
    else
    {
        motor_roller.setVelocity(0, percent);
    }
    motor_roller.spin(fwd);
}

void conveyorForwardAsync()
{
    if (Controller.ButtonLeft.pressing())
    {
        motor_conveyor.setVelocity(100, percent);
    }
    else
    {
        motor_conveyor.setVelocity(0, percent);
    }
    motor_conveyor.spin(fwd);
}

void conveyorReverseAsync()
{
    if (Controller.ButtonRight.pressing())
    {
        motor_conveyor.setVelocity(-100, percent);
    }
    else
    {
        motor_conveyor.setVelocity(0, percent);
    }
    motor_conveyor.spin(fwd);
}