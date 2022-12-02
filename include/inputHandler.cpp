
#include "inputHandler.h"

button::button(bool isToggle = false) // constructor
{
    isToggle = isToggle;

    pressed = false;
};

void button::onPress()
{
    if (isToggle)
    {
        /* code */
    }
    else
    {
        rawPressed = true;
        pressed = rawPressed;
    }
}

void button::onRelease()
{
    if (isToggle)
    {
        /* code */
    }
    else
    {
        rawPressed = false;
        pressed = rawPressed;
    }
}

bool button::isPressed()
{
    return pressed;
}

input::input()
{
    setupCallbacks();
}
void input::setupCallbacks()
{
    // on press callbacks
    Controller.ButtonY.pressed(press_y);
    Controller.ButtonX.pressed(press_x);
    Controller.ButtonA.pressed(press_a);
    Controller.ButtonB.pressed(press_b);

    Controller.ButtonLeft.pressed(press_left);
    Controller.ButtonUp.pressed(press_up);
    Controller.ButtonRight.pressed(press_right);
    Controller.ButtonDown.pressed(press_down);

    Controller.ButtonL1.pressed(press_l1);
    Controller.ButtonL2.pressed(press_l2);
    Controller.ButtonR1.pressed(press_r1);
    Controller.ButtonR2.pressed(press_r2);

    // on release callbacks
    Controller.ButtonY.released(release_y);
    Controller.ButtonX.released(release_x);
    Controller.ButtonA.released(release_a);
    Controller.ButtonB.released(release_b);

    Controller.ButtonLeft.released(release_left);
    Controller.ButtonUp.released(release_up);
    Controller.ButtonRight.released(release_right);
    Controller.ButtonDown.released(release_down);

    Controller.ButtonL1.released(release_l1);
    Controller.ButtonL2.released(release_l2);
    Controller.ButtonR1.released(release_r1);
    Controller.ButtonR2.released(release_r2);
}