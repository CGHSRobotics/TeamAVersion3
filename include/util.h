#pragma once

#include "vexDevices.h"

/*
 * Function Declaration
 */

void spinMotor(motor motorToSpin, float velocity);
void printTextToScreen(string text, int row, int col);

/*
 * Function Definitions
 */

// Spin Motor
void spinMotor(motor motorToSpin, float velocity)
{
    motorToSpin.setVelocity(velocity, percent);
    motorToSpin.spin(fwd);
};

// Prints Text to Screen at Position
void printTextToScreen(string text, int row, int col)
{
    Brain.Screen.setCursor(row, col);
    Brain.Screen.print(text.c_str());
};
void printTextToScreen(float text, int row, int col)
{
    Brain.Screen.setCursor(row, col);
    Brain.Screen.print(text);
};