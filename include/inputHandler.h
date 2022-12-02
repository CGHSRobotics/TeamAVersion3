#pragma once

#include "vexDevices.h"

class button
{
public:
    button(bool isToggle = false); // constructor

    bool isPressed(); // get pressed variable

    void onPress();   // on press function for callback
    void onRelease(); // on release callback for callback

private:
    bool isToggle;
    bool pressed;
    bool rawPressed;
};

class input
{
public:
    input();
    void setupCallbacks();

    button y = button();
    button x = button();
    button a = button();
    button b = button();

    button left = button();
    button up = button();
    button right = button();
    button down = button();

    button l1 = button();
    button l2 = button();
    button r1 = button();
    button r2 = button();
};

input Input;

// gloabl functions to bs through function callbacks
void press_y()
{
    Input.y.onPress();
}
void press_x()
{
    Input.x.onPress();
}
void press_a()
{
    Input.a.onPress();
}
void press_b()
{
    Input.b.onPress();
}
void press_left()
{
    Input.left.onPress();
}
void press_up()
{
    Input.up.onPress();
}
void press_right()
{
    Input.right.onPress();
}
void press_down()
{
    Input.down.onPress();
}
void press_l1()
{
    Input.l1.onPress();
}
void press_l2()
{
    Input.l2.onPress();
}
void press_r1()
{
    Input.r1.onPress();
}
void press_r2()
{
    Input.r2.onPress();
}

// on release
void release_y()
{
    Input.y.onRelease();
    // turn on roller
}
void release_x()
{
    Input.x.onRelease();
}
void release_a()
{
    Input.a.onRelease();
}
void release_b()
{
    Input.b.onRelease();
}
void release_left()
{
    Input.left.onRelease();
}
void release_up()
{
    Input.up.onRelease();
}
void release_right()
{
    Input.right.onRelease();
}
void release_down()
{
    Input.down.onRelease();
}
void release_l1()
{
    Input.l1.onRelease();
}
void release_l2()
{
    Input.l2.onRelease();
}
void release_r1()
{
    Input.r1.onRelease();
}
void release_r2()
{
    Input.r2.onRelease();
}